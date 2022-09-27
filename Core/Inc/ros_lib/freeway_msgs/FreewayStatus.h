#ifndef _ROS_freeway_msgs_FreewayStatus_h
#define _ROS_freeway_msgs_FreewayStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace freeway_msgs
{

  class FreewayStatus : public ros::Msg
  {
    public:
      typedef float _distance_remaining_type;
      _distance_remaining_type distance_remaining;
      typedef float _arrival_time_type;
      _arrival_time_type arrival_time;

    FreewayStatus():
      distance_remaining(0),
      arrival_time(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->distance_remaining);
      offset += serializeAvrFloat64(outbuffer + offset, this->arrival_time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->distance_remaining));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->arrival_time));
     return offset;
    }

    const char * getType(){ return "freeway_msgs/FreewayStatus"; };
    const char * getMD5(){ return "e15ae44a114b517af4722fee9b9deb57"; };

  };

}
#endif
