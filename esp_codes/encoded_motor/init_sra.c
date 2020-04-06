#include "init_sra.h"
#define ESP_INTR_FLAG_DEFAULT 0

void init_interrupt(gpio_num_t NUM_GPIO){
    gpio_config_t io_conf;
    printf("init_interrupt(%d)\n", NUM_GPIO);
    io_conf.intr_type = GPIO_INTR_ANYEDGE;
    io_conf.mode = GPIO_MODE_INPUT;
    io_conf.pin_bit_mask = ((uint64_t)1 << NUM_GPIO);
    io_conf.pull_up_en = 1;
    gpio_config(&io_conf);
    gpio_install_isr_service(ESP_INTR_FLAG_DEFAULT);
    printf("init_interrupt(%d) ENDS\n", NUM_GPIO);
}

void init_gpio(gpio_num_t NUM_GPIO, gpio_mode_t GPIO_MODE){
    gpio_config_t io_conf;
    printf("init_gpio(%d, %u)\n", NUM_GPIO, GPIO_MODE);
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE;
    io_conf.pin_bit_mask = ((uint64_t)1 << NUM_GPIO);
    io_conf.pull_up_en = 1;
    io_conf.pull_down_en = 1;
    gpio_config(&io_conf);
    printf("init_gpio(%d, %u) ENDS\n", NUM_GPIO, GPIO_MODE);
}

void init_mcpwm(mcpwm_t* pwm){
    mcpwm_gpio_init(pwm->pwm_unit, pwm->pwm_io_signals, pwm->pwm_pin);
    mcpwm_config_t pwm_config;
    pwm_config.frequency = 400;
    pwm_config.cmpr_a = 0;
    pwm_config.cmpr_b = 0;
    pwm_config.counter_mode = MCPWM_UP_COUNTER;
    pwm_config.duty_mode = MCPWM_DUTY_MODE_0;
    mcpwm_init(pwm->pwm_unit, pwm->pwm_timer, &pwm_config);
}