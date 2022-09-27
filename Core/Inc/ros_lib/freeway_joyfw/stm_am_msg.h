#ifndef _ROS_freeway_joyfw_stm_am_msg_h
#define _ROS_freeway_joyfw_stm_am_msg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace freeway_joyfw
{

  class stm_am_msg : public ros::Msg
  {
    public:
      typedef bool _am_status2_type;
      _am_status2_type am_status2;

    stm_am_msg():
      am_status2(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_am_status2;
      u_am_status2.real = this->am_status2;
      *(outbuffer + offset + 0) = (u_am_status2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->am_status2);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_am_status2;
      u_am_status2.base = 0;
      u_am_status2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->am_status2 = u_am_status2.real;
      offset += sizeof(this->am_status2);
     return offset;
    }

    const char * getType(){ return "freeway_joyfw/stm_am_msg"; };
    const char * getMD5(){ return "7d69f08cbd0079f4e385def6382afcb2"; };

  };

}
#endif
