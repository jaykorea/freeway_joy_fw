/*
 * mainpp.cpp
 *
 *  Created on: Sep 16, 2022
 *      Author: van
 */

#include <mainpp.h>
#include <ros.h>
#include <std_msgs/Empty.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>
#include <ros/service_client.h>
#include <freeway_joyfw/stm_fw_msg.h>
#include <freeway_joyfw/stm_am_msg.h>
#include <freeway_joyfw/stm_fw_srv.h>
// Node:
ros::NodeHandle nh;
using freeway_joyfw::stm_fw_srv;
// Publisher:
geometry_msgs::Twist cmd_vel_msg;
freeway_joyfw::stm_fw_msg stm_pub_msg;
ros::Publisher freeway_diagnostics("freeway/diagnostics", &stm_pub_msg);

// Service Client:
//ros::ServiceClient<Stm32_Status::stm_status::Request, Stm32_Status::stm_status::Response>clt("/e_stop_status");
//Stm32_Status::stm_status::Request ESTOP_STATUS;
//Stm32_Status::stm_status::Response RESULT;
bool *e_stop_status, *am_status;

//void auto_mode_cb(const stm_fw_srv::Request &req, stm_fw_srv::Response &res){
//	bool tf = false;
//	am_status = &tf;
//	//HAL_Delay(5);
//}
//
//void manual_mode_cb(const stm_fw_srv::Request &req, stm_fw_srv::Response &res){
//	bool tf = true;
//	am_status = &tf;
//	//HAL_Delay(5);
//}

// Service Server
//ros::ServiceServer<stm_fw_srv::Request, stm_fw_srv::Response> server("auto_mode", &auto_mode_cb);
//ros::ServiceServer<stm_fw_srv::Request, stm_fw_srv::Response> server2("manual_mode", &manual_mode_cb);
bool td = true;
bool fd = false;

double axis_X, axis_Y;
bool axis_B = true;
double l_scale_ = 0.3;
double a_scale_ = 0.4;

// Subscriber:
void am_status_cb(const freeway_joyfw::stm_am_msg &msg) {
	bool tf = msg.am_status2;
	*am_status = tf;
}
ros::Subscriber<freeway_joyfw::stm_am_msg> am_status_sub("freeway/am_status", &am_status_cb);

long map(uint32_t a, long b, long c, long d, long e) {
	return (a - b)*(e - d)/(c - b) + d;
}


// Setup node:
void setup(void) {
  nh.initNode();

//  nh.advertiseService(server);
//  nh.advertiseService(server2);
  nh.subscribe(am_status_sub);
  nh.advertise(freeway_diagnostics);
  //nh.advertiseService(server2);
  e_stop_status = &td;
  am_status = &fd;
}

// Loop:
void loop(uint32_t x_val, uint32_t y_val) {


  nh.spinOnce();

  if (*e_stop_status==true && *am_status==true) { //if var 'am_status == true' , it defines manual mode
	  axis_X = map(x_val,0,4095,-10000,10000) / (float)10000.0;
	  axis_Y = map(y_val,0,4095,-10000,10000) / (float)10000.0;

	  //cmd_vel_msg.linear.x = l_scale_ * axis_X;
	  //cmd_vel_msg.angular.z = a_scale_ * axis_Y;
	  stm_pub_msg.am_status = true;
	  stm_pub_msg.e_stop_status = true;
	  stm_pub_msg.cmd_vel_mcu.linear.x = l_scale_ * axis_X;
	  stm_pub_msg.cmd_vel_mcu.angular.z = -a_scale_ * axis_Y;

	  freeway_diagnostics.publish(&stm_pub_msg);
  }
  else if (*e_stop_status==false) // e_stop is on & *am_status is on/off
  {
	  stm_pub_msg.am_status = *am_status;
	  stm_pub_msg.e_stop_status = false;
	  stm_pub_msg.cmd_vel_mcu.linear.x = 0;
	  stm_pub_msg.cmd_vel_mcu.angular.z = 0;

	  freeway_diagnostics.publish(&stm_pub_msg);
  }

  HAL_Delay(30);
}


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(GPIO_Pin);
  static bool pin_stat = true;
  /* NOTE: This function Should not be modified, when the callback is needed,
           the HAL_GPIO_EXTI_Callback could be implemented in the user file
   */
  for (int i=0; i<10; i++){
	pin_stat = HAL_GPIO_ReadPin (GPIOA, GPIO_Pin);
  }
  *e_stop_status = pin_stat;
//  bool pin_stat3 = HAL_GPIO_ReadPin (GPIOB, GPIO_Pin);
//  if(e_stop_status == true && axis_B == true) {
//	  cmd_vel_msg.linear.x = 0;
//	  cmd_vel_msg.angular.z = 0;
//
//	  cmd_vel_pub.publish(&cmd_vel_msg);
//  }
//  else if(e_stop_status == true && axis_B == false) {
//	  cmd_vel_msg.linear.x = 0;
//	  cmd_vel_msg.angular.z = 0;
//
//	  cmd_vel_pub.publish(&cmd_vel_msg);
//  }
//  else if(e_stop_status == false && axis_B == false) {
//	  cmd_vel_msg.linear.x = l_scale_ * axis_X;
//	  cmd_vel_msg.angular.z = a_scale_ * axis_Y;
//
//	  cmd_vel_pub.publish(&cmd_vel_msg);
//  }
//  ESTOP_STATUS.estop_query = e_stop_status;
//  ESTOP_STATUS.am_query = true;
//
//  RESULT.result = 1;
//
//  clt.call(ESTOP_STATUS, RESULT);
  //HAL_Delay(1);

}

void HAL_GPIO_EXTI_Callback3(uint16_t GPIO_Pin)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(GPIO_Pin);
  static bool pin_stat = true;
  /* NOTE: This function Should not be modified, when the callback is needed,
           the HAL_GPIO_EXTI_Callback could be implemented in the user file
   */
  for (int i=0; i<10; i++){
	pin_stat = HAL_GPIO_ReadPin (GPIOB, GPIO_Pin);
  }
  //am_status = &pin_stat;
  //HAL_Delay(1);
}
