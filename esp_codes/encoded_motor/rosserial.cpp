#include "ros.h"
#include "auto_nav/ticks_msg.h"
#include "auto_nav/velocity_msg.h"
#include "rosserial.h"

ros::NodeHandle nh;

auto_nav::ticks_msg ticks;
auto_nav::velocity_msg velocity;
ros::Publisher espPub("ticks", &ticks);

void callback(const auto_nav::velocity_msg& msg){
  velocity.motor_F = msg.motor_F;
  velocity.motor_B = msg.motor_B;
  velocity.motor_L = msg.motor_L;
  velocity.motor_R = msg.motor_R;
}
ros::Subscriber<auto_nav::velocity_msg> espSub("teleop", &callback);

void rosserial_setup(){  // Initialize ROS
  nh.initNode();
  nh.advertise(espPub);
  nh.subscribe(espSub);
  velocity.motor_F = 0;
  velocity.motor_B = 0;
  velocity.motor_L = 0;
  velocity.motor_R = 0;
}

void rosserial_publish(volatile long int* ticks_L, volatile long int* ticks_R){
  ticks.motor_L = *ticks_L;
  ticks.motor_R = *ticks_R;
  ticks.motor_R *= -1;
  espPub.publish(&ticks);  // publish the msg
}

void rosserial_subscribe(float* duty_F, float* duty_B, float* duty_L, float* duty_R){
  *duty_F = velocity.motor_F;
  *duty_B = velocity.motor_B;
  *duty_L = velocity.motor_L;
  *duty_R = velocity.motor_R;
  nh.spinOnce();
}

void rosserial_spinonce(){
  nh.spinOnce();
}
