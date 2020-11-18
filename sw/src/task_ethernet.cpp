#include <task_ethernet.h>

#include <FreeRTOS.h>
#include <semphr.h>
#include <task.h>

#include <FreeRTOS_IP.h>
#include <FreeRTOS_Sockets.h>

#include <conf_eth.h>
#include <stdio_serial.h>

#include <array>

constexpr const char* kEthernetTaskName = "Ethernet";
constexpr uint32_t kEthernetTaskStackSize = 4096U / sizeof(portSTACK_TYPE);
constexpr UBaseType_t kEthernetTaskPriority = tskIDLE_PRIORITY + 1;

static StackType_t ethernet_task_stack[kEthernetTaskStackSize] = {};
static StaticTask_t ethernet_task_buffer = {};

static TaskHandle_t ethernet_task_handle = nullptr;

static void task_ethernet(void* /*pvParameters*/)
{
    TickType_t last_wake_time_ticks = xTaskGetTickCount();

    struct freertos_sockaddr xClient, xBindAddress;
    Socket_t xListeningSocket, xConnectedSocket;
    socklen_t xSize = sizeof( xClient );
    static const TickType_t xReceiveTimeOut = portMAX_DELAY;
    const BaseType_t xBacklog = 20;

    constexpr uint32_t kRxBufferSizeBytes = 1536;
    uint8_t rx_buffer[kRxBufferSizeBytes] = {};

    /* Attempt to open the socket. */
    xListeningSocket = FreeRTOS_socket(FREERTOS_AF_INET, FREERTOS_SOCK_STREAM, FREERTOS_IPPROTO_TCP);

    /* Check the socket was created. */
    configASSERT(xListeningSocket != FREERTOS_INVALID_SOCKET);

    /* If FREERTOS_SO_RCVBUF or FREERTOS_SO_SNDBUF are to be used with
    FreeRTOS_setsockopt() to change the buffer sizes from their default then do
    it here!.  (see the FreeRTOS_setsockopt() documentation. */

    /* If ipconfigUSE_TCP_WIN is set to 1 and FREERTOS_SO_WIN_PROPERTIES is to
    be used with FreeRTOS_setsockopt() to change the sliding window size from
    its default then do it here! (see the FreeRTOS_setsockopt()
    documentation. */

    /* Set a time out so accept() will just wait for a connection. */
    FreeRTOS_setsockopt(xListeningSocket,
                        0,
                        FREERTOS_SO_RCVTIMEO,
                        &xReceiveTimeOut,
                        sizeof(xReceiveTimeOut));

    /* Set the listening port to 10000. */
    xBindAddress.sin_port = ( uint16_t )5001;
    xBindAddress.sin_port = FreeRTOS_htons(xBindAddress.sin_port);

    /* Bind the socket to the port that the client RTOS task will send to. */
    FreeRTOS_bind( xListeningSocket, &xBindAddress, sizeof( xBindAddress ) );

    /* Set the socket into a listening state so it can accept connections.
    The maximum number of simultaneous connections is limited to 20. */
    FreeRTOS_listen(xListeningSocket, xBacklog);

    while (true)
    {
        /* Wait for incoming connections. */
        xConnectedSocket = FreeRTOS_accept(xListeningSocket, &xClient, &xSize);
        configASSERT(xConnectedSocket != FREERTOS_INVALID_SOCKET);
        printf("iperf client connected!\r\n");

        while (true)
        {
            /* Receive another block of data into the cRxedData buffer. */
            BaseType_t lBytesReceived = FreeRTOS_recv(xConnectedSocket, &rx_buffer, kRxBufferSizeBytes, 0);

            if(lBytesReceived > 0)
            {
                /* Data was received, process it here. */
                //prvPorcessData( cRxedData, lBytesReceived );
                // printf("Received %ld bytes.\r\n", lBytesReceived);
            }
            else if( lBytesReceived == 0 )
            {
                /* No data was received, but FreeRTOS_recv() did not return an error.
                Timeout? */
            }
            else
            {
                /* Error (maybe the connected socket already shut down the socket?).
                Attempt graceful shutdown. */
                printf("Disconnecting iperf client.\r\n");
                FreeRTOS_shutdown(xConnectedSocket, FREERTOS_SHUT_RDWR);
                break;
            }
        }
    }
}


bool create_task_ethernet(const Eui48MacAddress& mac_addr)
{
    constexpr std::array<uint8_t, 4> ip_addr = {ETHERNET_CONF_IPADDR0, ETHERNET_CONF_IPADDR1, ETHERNET_CONF_IPADDR2,
        ETHERNET_CONF_IPADDR3};
    constexpr std::array<uint8_t, 4> net_mask = {255, 255, 255, 0};
    constexpr std::array<uint8_t, 4> gw_addr = ip_addr;
    constexpr std::array<uint8_t, 4> dns_addr = ip_addr;

    FreeRTOS_IPInit(&(ip_addr[0]), &(net_mask[0]), &(gw_addr[0]), &(dns_addr[0]), &(mac_addr[0]));

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
