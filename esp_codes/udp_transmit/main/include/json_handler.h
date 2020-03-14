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

#ifndef JSON_HANDLER_H
#define JSON_HANDLER_H

#include "cJSON.h"
#include "stdio.h"

struct pid_const
{
    float kp;
    float ki;
    float kd;
    float setpoint;
};

char *create_pid_data_to_json(float current, float error, float P, float I, float D);
struct pid_const read_pid_data_from_json(const char* data);

#endif