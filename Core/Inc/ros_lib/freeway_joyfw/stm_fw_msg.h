#ifndef _ROS_freeway_joyfw_stm_fw_msg_h
#define _ROS_freeway_joyfw_stm_fw_msg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Twist.h"

namespace freeway_joyfw
{

  class stm_fw_msg : public ros::Msg
  {
    public:
      typedef bool _am_status_type;
      _am_status_type am_status;
      typedef bool _e_stop_status_type;
      _e_stop_status_type e_stop_status;
      typedef geometry_msgs::Twist _cmd_vel_mcu_type;
      _cmd_vel_mcu_type cmd_vel_mcu;

    stm_fw_msg():
      am_status(0),
      e_stop_status(0),
      cmd_vel_mcu()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_am_status;
      u_am_status.real = this->am_status;
      *(outbuffer + offset + 0) = (u_am_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->am_status);
      union {
        bool real;
        uint8_t base;
      } u_e_stop_status;
      u_e_stop_status.real = this->e_stop_status;
      *(outbuffer + offset + 0) = (u_e_stop_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->e_stop_status);
      offset += this->cmd_vel_mcu.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_am_status;
      u_am_status.base = 0;
      u_am_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->am_status = u_am_status.real;
      offset += sizeof(this->am_status);
      union {
        bool real;
        uint8_t base;
      } u_e_stop_status;
      u_e_stop_status.base = 0;
      u_e_stop_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->e_stop_status = u_e_stop_status.real;
      offset += sizeof(this->e_stop_status);
      offset += this->cmd_vel_mcu.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "freeway_joyfw/stm_fw_msg"; };
    const char * getMD5(){ return "fa2d9ef9f2382f4119166968f815e551"; };

  };

}
#endif
