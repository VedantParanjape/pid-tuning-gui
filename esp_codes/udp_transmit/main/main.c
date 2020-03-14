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
#include "transport.h"

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
    struct pid_terms dt;
    dt.current = 1.00;
    dt.error = 2.00;
    dt.P = 3.00;
    dt.I = 4.00;
    dt.D = 5.00;
    ESP_ERROR_CHECK(init_queue());
    logD("1", "%s", "1");
    ESP_ERROR_CHECK(send_to_queue(dt));
    ESP_ERROR_CHECK(send_to_queue(dt));
    logD("2", "%s", "2");
    pid_transport();
}