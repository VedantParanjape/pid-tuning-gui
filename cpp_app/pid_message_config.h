#ifndef PID_MESSAGE_CONFIG_H
#define PID_MESSAGE_CONFIG_H
struct  pid_terms_incomming_values
{
    double Ki;
    double Kp;
    double Kd;
    double current;
    double error;

};

struct pid_term_send_values
{
    double Ki;
    double Kp;
    double Kd;
    double setpoint;

} ;


#endif // PID_MESSAGE_CONFIG_H
