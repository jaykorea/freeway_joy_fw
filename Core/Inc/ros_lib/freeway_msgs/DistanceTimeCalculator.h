#ifndef _ROS_freeway_msgs_DistanceTimeCalculator_h
#define _ROS_freeway_msgs_DistanceTimeCalculator_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace freeway_msgs
{

  class DistanceTimeCalculator : public ros::Msg
  {
    public:
      typedef float _distance_remaining_type;
      _distance_remaining_type distance_remaining;
      typedef float _arrival_time_type;
      _arrival_time_type arrival_time;
      typedef float _distance_robot_traveled_type;
      _distance_robot_traveled_type distance_robot_traveled;
      typedef float _remaining_distance_percentage_type;
      _remaining_distance_percentage_type remaining_distance_percentage;
      typedef uint8_t _status_info_type;
      _status_info_type status_info;

    DistanceTimeCalculator():
      distance_remaining(0),
      arrival_time(0),
      distance_robot_traveled(0),
      remaining_distance_percentage(0),
      status_info(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->distance_remaining);
      offset += serializeAvrFloat64(outbuffer + offset, this->arrival_time);
      offset += serializeAvrFloat64(outbuffer + offset, this->distance_robot_traveled);
      offset += serializeAvrFloat64(outbuffer + offset, this->remaining_distance_percentage);
      *(outbuffer + offset + 0) = (this->status_info >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status_info);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->distance_remaining));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->arrival_time));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->distance_robot_traveled));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->remaining_distance_percentage));
      this->status_info =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status_info);
     return offset;
    }

    const char * getType(){ return "freeway_msgs/DistanceTimeCalculator"; };
    const char * getMD5(){ return "81e822a92cb126c3f8f6f2c755ae25fa"; };

  };

}
#endif
