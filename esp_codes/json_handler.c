/* JSON STRUCTURE

Json with PID data to be sent to client

{
    "current" : current,
    "error" : error,
    "P" : P,
    "I" : I,
    "D" : D
}

Json with Kp,ki,kd and setpoint data to be recieved

{
    "kp" : kp,
    "ki" : ki,
    "kd" : kd,
    "setpoint" : setpoint
}

*/

#include "cjson/cJSON.h"
#include "stdio.h"

struct pid_const
{
    float kp;
    float ki;
    float kd;
    float setpoint;
};

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

// int main()
// {
//     char *str = create_pid_data_to_json(10,10,23,10,10);
//     char *data_json = "{\"kp\": 10, \"ki\": 20, \"kd\": 345, \"setpoint\": 34}";

//     printf("%s",str);

//     struct pid_const edata = read_pid_data_from_json(data_json);

//     printf("%f %f %f %f", edata.kp, edata.ki, edata.kd, edata.setpoint);
    
// }