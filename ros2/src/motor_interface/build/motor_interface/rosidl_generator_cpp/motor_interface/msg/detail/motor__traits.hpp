// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from motor_interface:msg/Motor.idl
// generated code does not contain a copyright notice

#ifndef MOTOR_INTERFACE__MSG__DETAIL__MOTOR__TRAITS_HPP_
#define MOTOR_INTERFACE__MSG__DETAIL__MOTOR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "motor_interface/msg/detail/motor__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace motor_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const Motor & msg,
  std::ostream & out)
{
  out << "{";
  // member: m1
  {
    out << "m1: ";
    rosidl_generator_traits::value_to_yaml(msg.m1, out);
    out << ", ";
  }

  // member: m2
  {
    out << "m2: ";
    rosidl_generator_traits::value_to_yaml(msg.m2, out);
    out << ", ";
  }

  // member: m3
  {
    out << "m3: ";
    rosidl_generator_traits::value_to_yaml(msg.m3, out);
    out << ", ";
  }

  // member: m4
  {
    out << "m4: ";
    rosidl_generator_traits::value_to_yaml(msg.m4, out);
    out << ", ";
  }

  // member: m5
  {
    out << "m5: ";
    rosidl_generator_traits::value_to_yaml(msg.m5, out);
    out << ", ";
  }

  // member: m6
  {
    out << "m6: ";
    rosidl_generator_traits::value_to_yaml(msg.m6, out);
    out << ", ";
  }

  // member: m7
  {
    out << "m7: ";
    rosidl_generator_traits::value_to_yaml(msg.m7, out);
    out << ", ";
  }

  // member: st
  {
    out << "st: ";
    rosidl_generator_traits::value_to_yaml(msg.st, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Motor & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: m1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "m1: ";
    rosidl_generator_traits::value_to_yaml(msg.m1, out);
    out << "\n";
  }

  // member: m2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "m2: ";
    rosidl_generator_traits::value_to_yaml(msg.m2, out);
    out << "\n";
  }

  // member: m3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "m3: ";
    rosidl_generator_traits::value_to_yaml(msg.m3, out);
    out << "\n";
  }

  // member: m4
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "m4: ";
    rosidl_generator_traits::value_to_yaml(msg.m4, out);
    out << "\n";
  }

  // member: m5
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "m5: ";
    rosidl_generator_traits::value_to_yaml(msg.m5, out);
    out << "\n";
  }

  // member: m6
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "m6: ";
    rosidl_generator_traits::value_to_yaml(msg.m6, out);
    out << "\n";
  }

  // member: m7
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "m7: ";
    rosidl_generator_traits::value_to_yaml(msg.m7, out);
    out << "\n";
  }

  // member: st
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "st: ";
    rosidl_generator_traits::value_to_yaml(msg.st, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Motor & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace motor_interface

namespace rosidl_generator_traits
{

[[deprecated("use motor_interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const motor_interface::msg::Motor & msg,
  std::ostream & out, size_t indentation = 0)
{
  motor_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use motor_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const motor_interface::msg::Motor & msg)
{
  return motor_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<motor_interface::msg::Motor>()
{
  return "motor_interface::msg::Motor";
}

template<>
inline const char * name<motor_interface::msg::Motor>()
{
  return "motor_interface/msg/Motor";
}

template<>
struct has_fixed_size<motor_interface::msg::Motor>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<motor_interface::msg::Motor>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<motor_interface::msg::Motor>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MOTOR_INTERFACE__MSG__DETAIL__MOTOR__TRAITS_HPP_
