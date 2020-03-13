#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "json_handler.h"
#include "udp_handler.h"
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

// void app_main(void)
// {
//     char *str = create_pid_data_to_json(10,10,23,10,10);
//     char *data_json = "{\"kp\": 10, \"ki\": 20, \"kd\": 345, \"setpoint\": 34}";
//     struct pid_const edata = read_pid_data_from_json(data_json);

//     while (1)
//     {
//         printf("%s\n",str);    
//         printf("%f %f %f %f\n", edata.kp, edata.ki, edata.kd, edata.setpoint);
//         vTaskDelay(100);
//     }
// }

void app_main(void)
{
    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    ESP_ERROR_CHECK(example_connect());

    struct network_data* handle = malloc(sizeof(struct network_data));
    network_manager(handle);

    int rec = 1;
    while(1)
    {
        rec = send_data(handle, "vedant");
        printf("send data: %d\n", rec);
        vTaskDelay(10);
    }

    char *recS = recieve_data(handle);
    
    printf("data is: %s\n", recS);
    close_network_manager(handle);
    
    printf("init\n");
    while (1)
    {
        printf("it worked\n");
        vTaskDelay(100);
    }
    
}