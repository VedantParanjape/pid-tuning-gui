#ifndef _ENCODER_H
#define _ENCODER_H

#include "init_sra.h"

typedef struct{
    char  name[10];
    int   id;
    float   curr_rpm;
    volatile long int ticks_count;
    volatile long int total_ticks;
	//volatile bool flag; 
    gpio_num_t enc_intr0;
    //gpio_num_t enc_dir;
    gpio_num_t enc_intr1;
    esp_timer_handle_t periodic_timer;
    bool dir;
}encoder_t;

void init_encoder(encoder_t *encoder);    //TODO: add parameter for type of edge

void IRAM_ATTR enc_isr_handler(encoder_t* encoder);

void IRAM_ATTR calculate_rpm(encoder_t* encoder);

void setup_rpm_calculator(encoder_t* encoder);

#endif