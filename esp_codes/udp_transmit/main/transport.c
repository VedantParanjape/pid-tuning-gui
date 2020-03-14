#include "transport.h"

static const char* TAG_init_queue = "transport <> init_queue";
static const char* TAG_send_to_queue = "transport <> send_to_queue";
static const char* TAG_receive_from_queue = "transport <> receive_from_queue";
static const char* TAG_transport = "transport";

esp_err_t init_queue(void)
{
    pid_struct_queue = xQueueCreate(50, sizeof(struct pid_terms));

    if (pid_struct_queue == NULL)
    {
        logW(TAG_init_queue, "%s", "Queue creation failed\n");
        return ESP_FAIL;
    }
    else
    {
        logD(TAG_init_queue, "%s", "Queue created\n");
        return ESP_OK;
    }
}

esp_err_t send_to_queue(struct pid_terms pid_data)
{
    BaseType_t qerror = xQueueSendToBack(pid_struct_queue, (void*)&pid_data, (TickType_t) 0/portTICK_PERIOD_MS);
    
    if(qerror == pdPASS)
    {
        logD(TAG_send_to_queue, "%s", "Data sent to Queue\n");
        return ESP_OK;
    }
    else if(qerror == errQUEUE_FULL)
    {
        logW(TAG_send_to_queue, "%s", "Data not sent to Queue, Queue full\n");
        return ESP_FAIL;
    }
    else
    {
        logW(TAG_send_to_queue, "%s", "Unknown error\n");
        return ESP_FAIL;
    }
}

struct data_recv receive_from_queue(void)
{
    struct pid_terms data;
    struct data_recv ret_data;
    BaseType_t qerror = xQueueReceive(pid_struct_queue, &(data), (TickType_t) 10000/portTICK_PERIOD_MS);
    
    logD(TAG_receive_from_queue, "%f", data.D);
    
    if(qerror == pdPASS)
    {
        logD(TAG_receive_from_queue, "%s", "Data received from Queue\n");
        ret_data.data = data;
        ret_data.err = ESP_OK;
    }
    else if(qerror == pdFALSE)
    {
        logW(TAG_receive_from_queue, "%s", "Data not received from Queue\n");
        ret_data.err = ESP_FAIL;
    }
    else
    {
        logW(TAG_receive_from_queue, "%s", "Unknown error\n");
        ret_data.err = ESP_FAIL;
    }

    return ret_data;
}

void pid_transport(void)
{
    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    
    ESP_ERROR_CHECK(example_connect());
    
    struct network_data* handle = malloc(sizeof(struct network_data));
    network_manager(handle);

    while(true)
    {
        struct data_recv pid = receive_from_queue();
        char* message = NULL;

        if (pid.err == ESP_OK)
        {
            message = create_pid_data_to_json(pid.data.current, pid.data.error, pid.data.P, pid.data.I, pid.data.D);
            logD(TAG_transport, "%s\n", message);
            int len = send_data(handle, message);
            logI(TAG_transport, "%d %s", len, "bytes of data sent\n");
        }
        else if(pid.err == ESP_FAIL)
        {
            message = "no data received from Queue";
            int len = send_data(handle, message);
            logI(TAG_transport, "%d %s", len, "no data received from Queue\n");
        }
        else
        {
            message = "Unknown error";
            int len = send_data(handle, message);
            logI(TAG_transport, "%d %s", len, "Unknown error\n");
        }
    }
}