#ifndef _ROS_mesh_msgs_VectorFieldStamped_h
#define _ROS_mesh_msgs_VectorFieldStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "mesh_msgs/VectorField.h"

namespace mesh_msgs
{

  class VectorFieldStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef mesh_msgs::VectorField _vector_field_type;
      _vector_field_type vector_field;

    VectorFieldStamped():
      header(),
      vector_field()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->vector_field.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->vector_field.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "mesh_msgs/VectorFieldStamped"; };
    const char * getMD5(){ return "3d9fc2de2c0939ad4bbe0890ccb68ce5"; };

  };

}
#endif
