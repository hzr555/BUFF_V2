// Generated by gencpp from file uart_process_2/uart_send.msg
// DO NOT EDIT!


#ifndef UART_PROCESS_2_MESSAGE_UART_SEND_H
#define UART_PROCESS_2_MESSAGE_UART_SEND_H


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
struct uart_send_
{
  typedef uart_send_<ContainerAllocator> Type;

  uart_send_()
    : curYaw(0.0)
    , curPitch(0.0)
    , curDistance(0.0)
    , time(0)
    , predictYaw(0.0)
    , predictPitch(0.0)
    , predictLatency(0)
    , attackFlag(0)  {
    }
  uart_send_(const ContainerAllocator& _alloc)
    : curYaw(0.0)
    , curPitch(0.0)
    , curDistance(0.0)
    , time(0)
    , predictYaw(0.0)
    , predictPitch(0.0)
    , predictLatency(0)
    , attackFlag(0)  {
  (void)_alloc;
    }



   typedef float _curYaw_type;
  _curYaw_type curYaw;

   typedef float _curPitch_type;
  _curPitch_type curPitch;

   typedef float _curDistance_type;
  _curDistance_type curDistance;

   typedef uint32_t _time_type;
  _time_type time;

   typedef float _predictYaw_type;
  _predictYaw_type predictYaw;

   typedef float _predictPitch_type;
  _predictPitch_type predictPitch;

   typedef uint32_t _predictLatency_type;
  _predictLatency_type predictLatency;

   typedef uint8_t _attackFlag_type;
  _attackFlag_type attackFlag;





  typedef boost::shared_ptr< ::uart_process_2::uart_send_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::uart_process_2::uart_send_<ContainerAllocator> const> ConstPtr;

}; // struct uart_send_

typedef ::uart_process_2::uart_send_<std::allocator<void> > uart_send;

typedef boost::shared_ptr< ::uart_process_2::uart_send > uart_sendPtr;
typedef boost::shared_ptr< ::uart_process_2::uart_send const> uart_sendConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::uart_process_2::uart_send_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::uart_process_2::uart_send_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::uart_process_2::uart_send_<ContainerAllocator1> & lhs, const ::uart_process_2::uart_send_<ContainerAllocator2> & rhs)
{
  return lhs.curYaw == rhs.curYaw &&
    lhs.curPitch == rhs.curPitch &&
    lhs.curDistance == rhs.curDistance &&
    lhs.time == rhs.time &&
    lhs.predictYaw == rhs.predictYaw &&
    lhs.predictPitch == rhs.predictPitch &&
    lhs.predictLatency == rhs.predictLatency &&
    lhs.attackFlag == rhs.attackFlag;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::uart_process_2::uart_send_<ContainerAllocator1> & lhs, const ::uart_process_2::uart_send_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace uart_process_2

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::uart_process_2::uart_send_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::uart_process_2::uart_send_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::uart_process_2::uart_send_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::uart_process_2::uart_send_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::uart_process_2::uart_send_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::uart_process_2::uart_send_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::uart_process_2::uart_send_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d112f4a4a5820fb9f88abfc424376903";
  }

  static const char* value(const ::uart_process_2::uart_send_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd112f4a4a5820fb9ULL;
  static const uint64_t static_value2 = 0xf88abfc424376903ULL;
};

template<class ContainerAllocator>
struct DataType< ::uart_process_2::uart_send_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uart_process_2/uart_send";
  }

  static const char* value(const ::uart_process_2::uart_send_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::uart_process_2::uart_send_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 curYaw\n"
"float32 curPitch\n"
"float32 curDistance\n"
"uint32  time\n"
"float32 predictYaw\n"
"float32 predictPitch\n"
"uint32  predictLatency\n"
"uint8 attackFlag\n"
;
  }

  static const char* value(const ::uart_process_2::uart_send_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::uart_process_2::uart_send_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.curYaw);
      stream.next(m.curPitch);
      stream.next(m.curDistance);
      stream.next(m.time);
      stream.next(m.predictYaw);
      stream.next(m.predictPitch);
      stream.next(m.predictLatency);
      stream.next(m.attackFlag);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct uart_send_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::uart_process_2::uart_send_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::uart_process_2::uart_send_<ContainerAllocator>& v)
  {
    s << indent << "curYaw: ";
    Printer<float>::stream(s, indent + "  ", v.curYaw);
    s << indent << "curPitch: ";
    Printer<float>::stream(s, indent + "  ", v.curPitch);
    s << indent << "curDistance: ";
    Printer<float>::stream(s, indent + "  ", v.curDistance);
    s << indent << "time: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.time);
    s << indent << "predictYaw: ";
    Printer<float>::stream(s, indent + "  ", v.predictYaw);
    s << indent << "predictPitch: ";
    Printer<float>::stream(s, indent + "  ", v.predictPitch);
    s << indent << "predictLatency: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.predictLatency);
    s << indent << "attackFlag: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.attackFlag);
  }
};

} // namespace message_operations
} // namespace ros

#endif // UART_PROCESS_2_MESSAGE_UART_SEND_H