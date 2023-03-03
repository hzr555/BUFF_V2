// Generated by gencpp from file uart_process_2/uart_receive.msg
// DO NOT EDIT!


#ifndef UART_PROCESS_2_MESSAGE_UART_RECEIVE_H
#define UART_PROCESS_2_MESSAGE_UART_RECEIVE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace uart_process_2
{
template <class ContainerAllocator>
struct uart_receive_
{
  typedef uart_receive_<ContainerAllocator> Type;

  uart_receive_()
    : yaw(0.0)
    , pitch(0.0)
    , mod(0)
    , red_blue(0)
    , shoot_speed_mod(0)  {
    }
  uart_receive_(const ContainerAllocator& _alloc)
    : yaw(0.0)
    , pitch(0.0)
    , mod(0)
    , red_blue(0)
    , shoot_speed_mod(0)  {
  (void)_alloc;
    }



   typedef float _yaw_type;
  _yaw_type yaw;

   typedef float _pitch_type;
  _pitch_type pitch;

   typedef uint8_t _mod_type;
  _mod_type mod;

   typedef uint8_t _red_blue_type;
  _red_blue_type red_blue;

   typedef uint8_t _shoot_speed_mod_type;
  _shoot_speed_mod_type shoot_speed_mod;





  typedef boost::shared_ptr< ::uart_process_2::uart_receive_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::uart_process_2::uart_receive_<ContainerAllocator> const> ConstPtr;

}; // struct uart_receive_

typedef ::uart_process_2::uart_receive_<std::allocator<void> > uart_receive;

typedef boost::shared_ptr< ::uart_process_2::uart_receive > uart_receivePtr;
typedef boost::shared_ptr< ::uart_process_2::uart_receive const> uart_receiveConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::uart_process_2::uart_receive_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::uart_process_2::uart_receive_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::uart_process_2::uart_receive_<ContainerAllocator1> & lhs, const ::uart_process_2::uart_receive_<ContainerAllocator2> & rhs)
{
  return lhs.yaw == rhs.yaw &&
    lhs.pitch == rhs.pitch &&
    lhs.mod == rhs.mod &&
    lhs.red_blue == rhs.red_blue &&
    lhs.shoot_speed_mod == rhs.shoot_speed_mod;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::uart_process_2::uart_receive_<ContainerAllocator1> & lhs, const ::uart_process_2::uart_receive_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace uart_process_2

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::uart_process_2::uart_receive_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::uart_process_2::uart_receive_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::uart_process_2::uart_receive_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::uart_process_2::uart_receive_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::uart_process_2::uart_receive_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::uart_process_2::uart_receive_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::uart_process_2::uart_receive_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9eb1c17f9d76fdce5a06ed519a258d0d";
  }

  static const char* value(const ::uart_process_2::uart_receive_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9eb1c17f9d76fdceULL;
  static const uint64_t static_value2 = 0x5a06ed519a258d0dULL;
};

template<class ContainerAllocator>
struct DataType< ::uart_process_2::uart_receive_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uart_process_2/uart_receive";
  }

  static const char* value(const ::uart_process_2::uart_receive_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::uart_process_2::uart_receive_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 yaw\n"
"float32 pitch\n"
"uint8 mod\n"
"uint8 red_blue\n"
"uint8 shoot_speed_mod\n"
;
  }

  static const char* value(const ::uart_process_2::uart_receive_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::uart_process_2::uart_receive_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.yaw);
      stream.next(m.pitch);
      stream.next(m.mod);
      stream.next(m.red_blue);
      stream.next(m.shoot_speed_mod);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct uart_receive_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::uart_process_2::uart_receive_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::uart_process_2::uart_receive_<ContainerAllocator>& v)
  {
    s << indent << "yaw: ";
    Printer<float>::stream(s, indent + "  ", v.yaw);
    s << indent << "pitch: ";
    Printer<float>::stream(s, indent + "  ", v.pitch);
    s << indent << "mod: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.mod);
    s << indent << "red_blue: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.red_blue);
    s << indent << "shoot_speed_mod: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.shoot_speed_mod);
  }
};

} // namespace message_operations
} // namespace ros

#endif // UART_PROCESS_2_MESSAGE_UART_RECEIVE_H
