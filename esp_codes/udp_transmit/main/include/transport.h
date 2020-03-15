#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <stdlib.h>
#include "udp_handler.h"
#include "json_handler.h"
#include "tcp_handler.h"
#include "logger.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "freertos/queue.h"
#include "freertos/event_groups.h"
#include "esp_err.h"
#include "protocol_examples_common.h"

TaskHandle_t pid_transport_handle, pid_const_transport_handle;
QueueHandle_t pid_struct_queue;

#define MESSAGE_QUEUE_SIZE CONFIG_MESSAGE_QUEUE_SIZE 
struct pid_terms
{
    float current;
    float error;
    float P;
    float I;
    float D;
};

struct data_recv
{
    struct pid_terms data;
    esp_err_t err;
};

struct pid_const pid_const_data;

esp_err_t init_queue(void);
void init_transport(void);
esp_err_t send_to_queue(struct pid_terms pid_data);
struct data_recv receive_from_queue(void);
void pid_transport();
void pid_const_transport();

#endif