#include <string.h>
#include <sys/param.h>


static const char *TAG = "udp_handler";
// static const char *payload = "Message from ESP32 ";

#define HOST_IP_ADDR "192.168.0.118"
#define PORT 1212

extern "C" 
{
    #include "freertos/FreeRTOS.h"
    #include "freertos/task.h"
    #include "freertos/event_groups.h"
    #include "esp_system.h"
    #include "esp_wifi.h"
    #include "esp_event.h"
    #include "esp_log.h"
    #include "nvs_flash.h"
    #include "esp_netif.h"
    #include "protocol_examples_common.h"

    #include "lwip/err.h"
    #include "lwip/sockets.h"
    #include "lwip/sys.h"
    #include <lwip/netdb.h>
    
    void app_main(void);
}

class network_manager{
    private:
        char rx_buffer[128];
        char addr_str[128];
        int addr_family;
        int ip_protocol;
        struct sockaddr_in dest_addr;
        int sock;

    public:
        network_manager();
        int send_data(char *payload);
        char* recieve_data();
        ~network_manager();
};
