#include "freertos/FreeRTOS.h"
#include "esp_timer.h"
#include "freertos/task.h"
#include "encoder.h"
#include "pin_defs.h"

void IRAM_ATTR enc_isr_handler0(encoder_t* encoder){   
  if(encoder->dir)
    encoder->ticks_count++;
  else
    encoder->ticks_count--; 
 }

void IRAM_ATTR enc_isr_handler1(encoder_t* encoder){
  if(encoder->dir)
    encoder->ticks_count++;
  else
    encoder->ticks_count--;
}

void init_encoder(encoder_t* encoder){
  printf("init_encoder()\n");
  init_interrupt(encoder->enc_intr0);
  init_interrupt(encoder->enc_intr1);
	gpio_isr_handler_add(encoder->enc_intr0, (void*)enc_isr_handler0, (void*) encoder);
  gpio_isr_handler_add(encoder->enc_intr1, (void*)enc_isr_handler1, (void*) encoder);
  setup_rpm_calculator(encoder);
  printf("init_encoder() END\n ");
}

void calculate_rpm(encoder_t* encoder){
  encoder->curr_rpm = encoder->ticks_count * 1.250;    //(1000000*60)/(135*111111) = 4.0000400004
  encoder->total_ticks +=  encoder->ticks_count;
  encoder->ticks_count = 0;
  vTaskDelay(1 / portTICK_RATE_MS);
}

void setup_rpm_calculator(encoder_t* encoder){
  printf("setup_rpm_calculator()\n");
  const esp_timer_create_args_t periodic_timer_args = {
          .callback = calculate_rpm,
          .arg = encoder,
          .name = encoder->name
  };

  esp_timer_create(&periodic_timer_args, &(encoder->periodic_timer));
  esp_timer_start_periodic(encoder->periodic_timer, 88888);
  printf("setup_rpm_calculator() ENDS\n");
}
