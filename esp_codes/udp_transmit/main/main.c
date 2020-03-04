#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "json_handler.h"

void app_main(void)
{
    char *str = create_pid_data_to_json(10,10,23,10,10);
    char *data_json = "{\"kp\": 10, \"ki\": 20, \"kd\": 345, \"setpoint\": 34}";
    struct pid_const edata = read_pid_data_from_json(data_json);

    while (1)
    {
        printf("%s\n",str);    
        printf("%f %f %f %f\n", edata.kp, edata.ki, edata.kd, edata.setpoint);
        vTaskDelay(100);
    }
}

