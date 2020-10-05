#include <task_ethernet.h>

#include <FreeRTOS.h>
#include <semphr.h>
#include <task.h>

#include <ethernet_phy.h>
#include <gmac.h>
#include <gmac_raw_2.h>
#include <sysclk.h>

#include <conf_eth.h>
#include <mini_ip.h>

#include <cstring>

constexpr const char* kEthernetTaskName = "Ethernet";
constexpr uint32_t kEthernetTaskStackSize = 10240U / sizeof(portSTACK_TYPE);
constexpr UBaseType_t kEthernetTaskPriority = tskIDLE_PRIORITY;

static StackType_t ethernet_task_stack[kEthernetTaskStackSize] = {};
static StaticTask_t ethernet_task_buffer = {};

static TaskHandle_t ethernet_task_handle = nullptr;


/** The MAC address used for the test */
static uint8_t gs_uc_mac_address[] =
        { ETHERNET_CONF_ETHADDR0, ETHERNET_CONF_ETHADDR1, ETHERNET_CONF_ETHADDR2,
            ETHERNET_CONF_ETHADDR3, ETHERNET_CONF_ETHADDR4, ETHERNET_CONF_ETHADDR5
};

/** The IP address used for test (ping ...) */
static uint8_t gs_uc_ip_address[] =
        { ETHERNET_CONF_IPADDR0, ETHERNET_CONF_IPADDR1,
            ETHERNET_CONF_IPADDR2, ETHERNET_CONF_IPADDR3 };

/** The GMAC driver instance */
static gmac_device_t gs_gmac_dev;

/** Buffer for ethernet packets */
static volatile uint8_t gs_uc_eth_buffer[GMAC_FRAME_LENTGH_MAX];



// Hacky hack hack.
extern SemaphoreHandle_t netif_notification_semaphore;



/**
 * \brief Process & return the ICMP checksum.
 *
 * \param p_buff Pointer to the buffer.
 * \param ul_len The length of the buffered data.
 *
 * \return Checksum of the ICMP.
 */
static uint16_t gmac_icmp_checksum(uint16_t *p_buff, uint32_t ul_len)
{
    uint32_t i, ul_tmp;

    for (i = 0, ul_tmp = 0; i < ul_len; i++, p_buff++) {

        ul_tmp += SWAP16(*p_buff);
    }
    ul_tmp = (ul_tmp & 0xffff) + (ul_tmp >> 16);

    return  static_cast<uint16_t>(~ul_tmp);
}

/**
 * \brief Process the received ARP packet; change address and send it back.
 *
 * \param p_uc_data  The data to process.
 * \param ul_size The data size.
 */
static void gmac_process_arp_packet(uint8_t *p_uc_data, uint32_t ul_size)
{
    uint32_t i;
    uint8_t ul_rc = GMAC_OK;

    p_ethernet_header_t p_eth = (p_ethernet_header_t) p_uc_data;
    p_arp_header_t p_arp = (p_arp_header_t) (p_uc_data + ETH_HEADER_SIZE);

    if (SWAP16(p_arp->ar_op) == ARP_REQUEST) {
        /*printf("-- MAC %x:%x:%x:%x:%x:%x\n\r",
                p_eth->et_dest[0], p_eth->et_dest[1],
                p_eth->et_dest[2], p_eth->et_dest[3],
                p_eth->et_dest[4], p_eth->et_dest[5]);

        printf("-- MAC %x:%x:%x:%x:%x:%x\n\r",
                p_eth->et_src[0], p_eth->et_src[1],
                p_eth->et_src[2], p_eth->et_src[3],
                p_eth->et_src[4], p_eth->et_src[5]);*/

        /* ARP reply operation */
        p_arp->ar_op = SWAP16(ARP_REPLY);

        /* Fill the destination address and source address */
        for (i = 0; i < 6; i++) {
            /* Swap ethernet destination address and ethernet source address */
            p_eth->et_dest[i] = p_eth->et_src[i];
            p_eth->et_src[i] = gs_uc_mac_address[i];
            p_arp->ar_tha[i] = p_arp->ar_sha[i];
            p_arp->ar_sha[i] = gs_uc_mac_address[i];
        }
        /* Swap the source IP address and the destination IP address */
        for (i = 0; i < 4; i++) {
            p_arp->ar_tpa[i] = p_arp->ar_spa[i];
            p_arp->ar_spa[i] = gs_uc_ip_address[i];
        }

        ul_rc = gmac_dev_write(&gs_gmac_dev, GMAC_QUE_0, p_uc_data, ul_size, NULL);

        if (ul_rc != GMAC_OK) {
            printf("E: ARP Send - 0x%x\n\r", ul_rc);
        }
    }
}

/**
 * \brief Process the received IP packet; change address and send it back.
 *
 * \param p_uc_data  The data to process.
 * \param ul_size The data size.
 */
static void gmac_process_ip_packet(uint8_t *p_uc_data, uint32_t ul_size)
{
    uint32_t i;
    uint32_t ul_icmp_len;
    int32_t ul_rc = GMAC_OK;

    /* avoid Cppcheck Warning */
    UNUSED(ul_size);

    p_ethernet_header_t p_eth = (p_ethernet_header_t) p_uc_data;
    p_ip_header_t p_ip_header = (p_ip_header_t) (p_uc_data + ETH_HEADER_SIZE);

    p_icmp_echo_header_t p_icmp_echo =
            (p_icmp_echo_header_t) ((int8_t *) p_ip_header +
            ETH_IP_HEADER_SIZE);

    /*printf("-- IP  %d.%d.%d.%d\n\r", p_ip_header->ip_dst[0], p_ip_header->ip_dst[1],
            p_ip_header->ip_dst[2], p_ip_header->ip_dst[3]);

    printf("-- IP  %d.%d.%d.%d\n\r",
            p_ip_header->ip_src[0], p_ip_header->ip_src[1], p_ip_header->ip_src[2],
            p_ip_header->ip_src[3]);*/

    switch (p_ip_header->ip_p) {
    case IP_PROT_ICMP:
        if (p_icmp_echo->type == ICMP_ECHO_REQUEST) {
            p_icmp_echo->type = ICMP_ECHO_REPLY;
            p_icmp_echo->code = 0;
            p_icmp_echo->cksum = 0;

            /* Checksum of the ICMP message */
            ul_icmp_len = (SWAP16(p_ip_header->ip_len) - ETH_IP_HEADER_SIZE);
            if (ul_icmp_len % 2) {
                *((uint8_t *) p_icmp_echo + ul_icmp_len) = 0;
                ul_icmp_len++;
            }
            ul_icmp_len = ul_icmp_len / sizeof(uint16_t);

            p_icmp_echo->cksum = SWAP16(
                    gmac_icmp_checksum((uint16_t *)p_icmp_echo, ul_icmp_len));
            /* Swap the IP destination  address and the IP source address */
            for (i = 0; i < 4; i++) {
                p_ip_header->ip_dst[i] =
                        p_ip_header->ip_src[i];
                p_ip_header->ip_src[i] = gs_uc_ip_address[i];
            }
            /* Swap ethernet destination address and ethernet source address */
            for (i = 0; i < 6; i++) {
                /* Swap ethernet destination address and ethernet source address */
                p_eth->et_dest[i] = p_eth->et_src[i];
                p_eth->et_src[i] = gs_uc_mac_address[i];
            }
            /* Send the echo_reply */

            ul_rc = gmac_dev_write(&gs_gmac_dev, GMAC_QUE_0, p_uc_data,
                    SWAP16(p_ip_header->ip_len) + 14, NULL);

            if (ul_rc != GMAC_OK) {
                printf("E: ICMP Send - 0x%x\n\r", ul_rc);
            }
        }
        break;

    default:
        break;
    }
}

/**
 * \brief Process the received GMAC packet.
 *
 * \param p_uc_data  The data to process.
 * \param ul_size The data size.
 */
static void gmac_process_eth_packet(uint8_t *p_uc_data, uint32_t ul_size)
{
    uint16_t us_pkt_format;

    p_ethernet_header_t p_eth = (p_ethernet_header_t) (p_uc_data);
    p_ip_header_t p_ip_header = (p_ip_header_t) (p_uc_data + ETH_HEADER_SIZE);
    ip_header_t ip_header;
    us_pkt_format = SWAP16(p_eth->et_protlen);

    switch (us_pkt_format) {
    /* ARP Packet format */
    case ETH_PROT_ARP:
        /* Process the ARP packet */
        gmac_process_arp_packet(p_uc_data, ul_size);

        break;

    /* IP protocol frame */
    case ETH_PROT_IP:
        /* Backup the header */
        memcpy(&ip_header, p_ip_header, sizeof(ip_header_t));

        /* Process the IP packet */
        gmac_process_ip_packet(p_uc_data, ul_size);
        break;

    default:
        printf("=== Default w_pkt_format= 0x%X===\n\r", us_pkt_format);
        break;
    }
}



#ifdef __cplusplus
extern "C" {
#endif
/**
 * \brief GMAC interrupt handler.
 */
void GMAC_Handler(void)
{
    gmac_handler(&gs_gmac_dev, GMAC_QUE_0);
}
#ifdef __cplusplus
}
#endif


static void task_ethernet(void* /*pvParameters*/)
{
    uint32_t ul_frm_size = 0U;

    while (true)
    {
        if( xSemaphoreTake(netif_notification_semaphore, portMAX_DELAY) == pdFALSE)
        {
            continue;
        }

        /* Process packets */
        if (GMAC_OK != gmac_dev_read(&gs_gmac_dev, GMAC_QUE_0, (uint8_t *) gs_uc_eth_buffer,
                        sizeof(gs_uc_eth_buffer), &ul_frm_size))
        {
            continue;
        }

        if (ul_frm_size > 0)
        {
            /* Handle input frame */
            gmac_process_eth_packet((uint8_t *) gs_uc_eth_buffer, ul_frm_size);
        }
    }
}

bool create_task_ethernet()
{
    /* Wait for PHY to be ready (CAT811: Max400ms) */
    //volatile uint32_t ul_delay = sysclk_get_cpu_hz() / 1000 / 3 * 400;
    //while (ul_delay--);

    /* Enable GMAC clock */
    pmc_enable_periph_clk(ID_GMAC);

    /* Fill in GMAC options */
    gmac_options_t gmac_option = {};
    gmac_option.uc_copy_all_frame = 0;
    gmac_option.uc_no_boardcast = 0;

    memcpy(gmac_option.uc_mac_addr, gs_uc_mac_address, sizeof(gs_uc_mac_address));

    gs_gmac_dev.p_hw = GMAC;

    /* Init GMAC driver structure */
    gmac_dev_init(GMAC, &gs_gmac_dev, &gmac_option);

    /* Enable Interrupt */
    NVIC_SetPriority(GMAC_IRQn, configMAC_INTERRUPT_PRIORITY);
    NVIC_EnableIRQ(GMAC_IRQn);

    /* Init MAC PHY driver */
    if (ethernet_phy_init(GMAC, BOARD_GMAC_PHY_ADDR, sysclk_get_cpu_hz())
                    != GMAC_OK) {
        puts("PHY Initialize ERROR!\r");
        return false;
    }

    /* Auto Negotiate, work in RMII mode */
    if (ethernet_phy_auto_negotiate(GMAC, BOARD_GMAC_PHY_ADDR) != GMAC_OK)
    {

        puts("Auto Negotiate ERROR!\r");
        return false;
    }

    /* Establish ethernet link */
    if (ethernet_phy_set_link(GMAC, BOARD_GMAC_PHY_ADDR, 1) != GMAC_OK)
    {
        puts("Set link ERROR!\r");
        return false;
    }

    ethernet_task_handle = xTaskCreateStatic(
        &task_ethernet,
        kEthernetTaskName,
        kEthernetTaskStackSize,
        nullptr,
        kEthernetTaskPriority,
        &ethernet_task_stack[0],
        &ethernet_task_buffer
    );

    return ethernet_task_handle != nullptr;
}
