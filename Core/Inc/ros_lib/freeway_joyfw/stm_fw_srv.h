#ifndef _ROS_SERVICE_stm_fw_srv_h
#define _ROS_SERVICE_stm_fw_srv_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace freeway_joyfw
{

static const char STM_FW_SRV[] = "freeway_joyfw/stm_fw_srv";

  class stm_fw_srvRequest : public ros::Msg
  {
    public:

    stm_fw_srvRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return STM_FW_SRV; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class stm_fw_srvResponse : public ros::Msg
  {
    public:
      typedef bool _result_type;
      _result_type result;

    stm_fw_srvResponse():
      result(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_result.real;
      offset += sizeof(this->result);
     return offset;
    }

    const char * getType(){ return STM_FW_SRV; };
    const char * getMD5(){ return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class stm_fw_srv {
    public:
    typedef stm_fw_srvRequest Request;
    typedef stm_fw_srvResponse Response;
  };

}
#endif
