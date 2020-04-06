#ifndef _INIT_SRA_H
#define _INIT_SRA_H
#include "driver/gpio.h"
#include "esp_attr.h"
#include "driver/mcpwm.h"
#include "soc/mcpwm_reg.h"
#include "soc/mcpwm_struct.h"
#include "pin_defs.h"

typedef struct{
    mcpwm_unit_t pwm_unit;
    mcpwm_timer_t pwm_timer;
    mcpwm_io_signals_t pwm_io_signals;
    mcpwm_operator_t pwm_operator;
    gpio_num_t pwm_pin;
}mcpwm_t;

void init_interrupt(gpio_num_t NUM_GPIO);    //TODO: 1) Add parameter for type of edge, 2) Add arguments to pass isr_handler, 3) add varags to pass args to isr

void init_gpio(gpio_num_t NUM_GPIO, gpio_mode_t GPIO_MODE);

void init_mcpwm(mcpwm_t* motor);

#endif