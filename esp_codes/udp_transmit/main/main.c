#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_netif.h"
#include "pid_plotter.h"
#include <math.h>
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


void broad()
{
    struct pid_terms dt;
    dt.current = 1.00;
    dt.error = 2.00;
    dt.P = 3.00;
    dt.I = 4.00;
    dt.D = 5.00;

    int count = 0;
    while(1)
    {
        esp_err_t err = send_to_queue(dt);
        err = send_to_queue(dt);
        logD("main", "%f", pid_const_read().setpoint);
        dt.current = tan((double)count/0.0001);
	dt.error = sin((double)count/0.0001);
	dt.P = cos((double)count/0.0001);
	dt.I = atan((double)count/0.0001);
	dt.D = sin((double)count/0.0001);
        count++;
	vTaskDelay(10);
    }
}

void app_main(void)
{

    xTaskCreate(broad, "send", 4096, NULL, 1, NULL);
    plotter();
}
