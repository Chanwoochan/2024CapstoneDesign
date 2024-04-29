// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from motor_interface:msg/Motor.idl
// generated code does not contain a copyright notice

#ifndef MOTOR_INTERFACE__MSG__DETAIL__MOTOR__BUILDER_HPP_
#define MOTOR_INTERFACE__MSG__DETAIL__MOTOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "motor_interface/msg/detail/motor__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace motor_interface
{

namespace msg
{

namespace builder
{

class Init_Motor_st
{
public:
  explicit Init_Motor_st(::motor_interface::msg::Motor & msg)
  : msg_(msg)
  {}
  ::motor_interface::msg::Motor st(::motor_interface::msg::Motor::_st_type arg)
  {
    msg_.st = std::move(arg);
    return std::move(msg_);
  }

private:
  ::motor_interface::msg::Motor msg_;
};

class Init_Motor_m7
{
public:
  explicit Init_Motor_m7(::motor_interface::msg::Motor & msg)
  : msg_(msg)
  {}
  Init_Motor_st m7(::motor_interface::msg::Motor::_m7_type arg)
  {
    msg_.m7 = std::move(arg);
    return Init_Motor_st(msg_);
  }

private:
  ::motor_interface::msg::Motor msg_;
};

class Init_Motor_m6
{
public:
  explicit Init_Motor_m6(::motor_interface::msg::Motor & msg)
  : msg_(msg)
  {}
  Init_Motor_m7 m6(::motor_interface::msg::Motor::_m6_type arg)
  {
    msg_.m6 = std::move(arg);
    return Init_Motor_m7(msg_);
  }

private:
  ::motor_interface::msg::Motor msg_;
};

class Init_Motor_m5
{
public:
  explicit Init_Motor_m5(::motor_interface::msg::Motor & msg)
  : msg_(msg)
  {}
  Init_Motor_m6 m5(::motor_interface::msg::Motor::_m5_type arg)
  {
    msg_.m5 = std::move(arg);
    return Init_Motor_m6(msg_);
  }

private:
  ::motor_interface::msg::Motor msg_;
};

class Init_Motor_m4
{
public:
  explicit Init_Motor_m4(::motor_interface::msg::Motor & msg)
  : msg_(msg)
  {}
  Init_Motor_m5 m4(::motor_interface::msg::Motor::_m4_type arg)
  {
    msg_.m4 = std::move(arg);
    return Init_Motor_m5(msg_);
  }

private:
  ::motor_interface::msg::Motor msg_;
};

class Init_Motor_m3
{
public:
  explicit Init_Motor_m3(::motor_interface::msg::Motor & msg)
  : msg_(msg)
  {}
  Init_Motor_m4 m3(::motor_interface::msg::Motor::_m3_type arg)
  {
    msg_.m3 = std::move(arg);
    return Init_Motor_m4(msg_);
  }

private:
  ::motor_interface::msg::Motor msg_;
};

class Init_Motor_m2
{
public:
  explicit Init_Motor_m2(::motor_interface::msg::Motor & msg)
  : msg_(msg)
  {}
  Init_Motor_m3 m2(::motor_interface::msg::Motor::_m2_type arg)
  {
    msg_.m2 = std::move(arg);
    return Init_Motor_m3(msg_);
  }

private:
  ::motor_interface::msg::Motor msg_;
};

class Init_Motor_m1
{
public:
  Init_Motor_m1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Motor_m2 m1(::motor_interface::msg::Motor::_m1_type arg)
  {
    msg_.m1 = std::move(arg);
    return Init_Motor_m2(msg_);
  }

private:
  ::motor_interface::msg::Motor msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::motor_interface::msg::Motor>()
{
  return motor_interface::msg::builder::Init_Motor_m1();
}

}  // namespace motor_interface

#endif  // MOTOR_INTERFACE__MSG__DETAIL__MOTOR__BUILDER_HPP_
