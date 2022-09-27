#ifndef _ROS_SERVICE_stm_status_h
#define _ROS_SERVICE_stm_status_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace duckpot_door
{

static const char STM_STATUS[] = "duckpot_door/stm_status";

  class stm_statusRequest : public ros::Msg
  {
    public:
      typedef bool _estop_query_type;
      _estop_query_type estop_query;
      typedef bool _am_query_type;
      _am_query_type am_query;

    stm_statusRequest():
      estop_query(0),
      am_query(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_estop_query;
      u_estop_query.real = this->estop_query;
      *(outbuffer + offset + 0) = (u_estop_query.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->estop_query);
      union {
        bool real;
        uint8_t base;
      } u_am_query;
      u_am_query.real = this->am_query;
      *(outbuffer + offset + 0) = (u_am_query.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->am_query);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_estop_query;
      u_estop_query.base = 0;
      u_estop_query.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->estop_query = u_estop_query.real;
      offset += sizeof(this->estop_query);
      union {
        bool real;
        uint8_t base;
      } u_am_query;
      u_am_query.base = 0;
      u_am_query.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->am_query = u_am_query.real;
      offset += sizeof(this->am_query);
     return offset;
    }

    const char * getType(){ return STM_STATUS; };
    const char * getMD5(){ return "3f14e77f9d7d27e7e7d9c92cf4c5988e"; };

  };

  class stm_statusResponse : public ros::Msg
  {
    public:
      typedef int8_t _result_type;
      _result_type result;

    stm_statusResponse():
      result(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
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
        int8_t real;
        uint8_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_result.real;
      offset += sizeof(this->result);
     return offset;
    }

    const char * getType(){ return STM_STATUS; };
    const char * getMD5(){ return "4414c67819626a1b8e0f043a9a0d6c9a"; };

  };

  class stm_status {
    public:
    typedef stm_statusRequest Request;
    typedef stm_statusResponse Response;
  };

}
#endif
