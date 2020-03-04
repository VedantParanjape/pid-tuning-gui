#include "json_handler.h"

char *create_pid_data_to_json(float current, float error, float P, float I, float D)
{
    cJSON *data = cJSON_CreateObject();
    char* json_string = NULL;

    cJSON_AddNumberToObject(data, "current", current);
    cJSON_AddNumberToObject(data, "error", error);
    cJSON_AddNumberToObject(data, "P", P);
    cJSON_AddNumberToObject(data, "I", I);
    cJSON_AddNumberToObject(data, "D", D);

    json_string = cJSON_Print(data);
    cJSON_Delete(data);
    
    return json_string;
}

struct pid_const read_pid_data_from_json(const char* data)
{
    struct pid_const data_extracted;
    const cJSON *data_json = cJSON_Parse(data);
    const cJSON *kp = NULL;
    const cJSON *ki = NULL;
    const cJSON *kd = NULL;
    const cJSON *setpoint = NULL;

    data_extracted.kp = cJSON_GetObjectItemCaseSensitive(data_json, "kp")->valuedouble;
    data_extracted.ki = cJSON_GetObjectItemCaseSensitive(data_json, "ki")->valuedouble;
    data_extracted.kd = cJSON_GetObjectItemCaseSensitive(data_json, "kd")->valuedouble;
    data_extracted.setpoint = cJSON_GetObjectItemCaseSensitive(data_json, "setpoint")->valuedouble;

    return data_extracted;
}
