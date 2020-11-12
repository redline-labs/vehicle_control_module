#include <task_ethernet.h>

#include <FreeRTOS.h>
#include <semphr.h>
#include <task.h>

#include <FreeRTOS_IP.h>
#include <FreeRTOS_IP_Private.h>
#include <NetworkBufferManagement.h>

#include <ethernet_phy.h>
#include <gmac.h>
#include <gmac_raw_2.h>
#include <sysclk.h>

#include <conf_eth.h>

#include <array>

bool create_task_ethernet(const Eui48MacAddress& mac_addr)
{
    constexpr std::array<uint8_t, 4> ip_addr = {ETHERNET_CONF_IPADDR0, ETHERNET_CONF_IPADDR1, ETHERNET_CONF_IPADDR2,
        ETHERNET_CONF_IPADDR3};
    constexpr std::array<uint8_t, 4> net_mask = {255, 255, 255, 0};
    constexpr std::array<uint8_t, 4> gw_addr = ip_addr;
    constexpr std::array<uint8_t, 4> dns_addr = ip_addr;

    BaseType_t ret = FreeRTOS_IPInit(&(ip_addr[0]), &(net_mask[0]), &(gw_addr[0]), &(dns_addr[0]), &(mac_addr[0]));
/*
    ethernet_task_handle = xTaskCreateStatic(
        &task_ethernet,
        kEthernetTaskName,
        kEthernetTaskStackSize,
        nullptr,
        kEthernetTaskPriority,
        &ethernet_task_stack[0],
        &ethernet_task_buffer
    );
*/
    return ret == pdPASS;
}
