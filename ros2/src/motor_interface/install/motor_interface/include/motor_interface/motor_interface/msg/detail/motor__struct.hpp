// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from motor_interface:msg/Motor.idl
// generated code does not contain a copyright notice

#ifndef MOTOR_INTERFACE__MSG__DETAIL__MOTOR__STRUCT_HPP_
#define MOTOR_INTERFACE__MSG__DETAIL__MOTOR__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__motor_interface__msg__Motor __attribute__((deprecated))
#else
# define DEPRECATED__motor_interface__msg__Motor __declspec(deprecated)
#endif

namespace motor_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Motor_
{
  using Type = Motor_<ContainerAllocator>;

  explicit Motor_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->m1 = 0ll;
      this->m2 = 0ll;
      this->m3 = 0ll;
      this->m4 = 0ll;
      this->m5 = 0ll;
      this->m6 = 0ll;
      this->m7 = 0ll;
      this->st = 0ll;
    }
  }

  explicit Motor_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->m1 = 0ll;
      this->m2 = 0ll;
      this->m3 = 0ll;
      this->m4 = 0ll;
      this->m5 = 0ll;
      this->m6 = 0ll;
      this->m7 = 0ll;
      this->st = 0ll;
    }
  }

  // field types and members
  using _m1_type =
    int64_t;
  _m1_type m1;
  using _m2_type =
    int64_t;
  _m2_type m2;
  using _m3_type =
    int64_t;
  _m3_type m3;
  using _m4_type =
    int64_t;
  _m4_type m4;
  using _m5_type =
    int64_t;
  _m5_type m5;
  using _m6_type =
    int64_t;
  _m6_type m6;
  using _m7_type =
    int64_t;
  _m7_type m7;
  using _st_type =
    int64_t;
  _st_type st;

  // setters for named parameter idiom
  Type & set__m1(
    const int64_t & _arg)
  {
    this->m1 = _arg;
    return *this;
  }
  Type & set__m2(
    const int64_t & _arg)
  {
    this->m2 = _arg;
    return *this;
  }
  Type & set__m3(
    const int64_t & _arg)
  {
    this->m3 = _arg;
    return *this;
  }
  Type & set__m4(
    const int64_t & _arg)
  {
    this->m4 = _arg;
    return *this;
  }
  Type & set__m5(
    const int64_t & _arg)
  {
    this->m5 = _arg;
    return *this;
  }
  Type & set__m6(
    const int64_t & _arg)
  {
    this->m6 = _arg;
    return *this;
  }
  Type & set__m7(
    const int64_t & _arg)
  {
    this->m7 = _arg;
    return *this;
  }
  Type & set__st(
    const int64_t & _arg)
  {
    this->st = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    motor_interface::msg::Motor_<ContainerAllocator> *;
  using ConstRawPtr =
    const motor_interface::msg::Motor_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<motor_interface::msg::Motor_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<motor_interface::msg::Motor_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      motor_interface::msg::Motor_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<motor_interface::msg::Motor_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      motor_interface::msg::Motor_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<motor_interface::msg::Motor_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<motor_interface::msg::Motor_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<motor_interface::msg::Motor_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__motor_interface__msg__Motor
    std::shared_ptr<motor_interface::msg::Motor_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__motor_interface__msg__Motor
    std::shared_ptr<motor_interface::msg::Motor_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Motor_ & other) const
  {
    if (this->m1 != other.m1) {
      return false;
    }
    if (this->m2 != other.m2) {
      return false;
    }
    if (this->m3 != other.m3) {
      return false;
    }
    if (this->m4 != other.m4) {
      return false;
    }
    if (this->m5 != other.m5) {
      return false;
    }
    if (this->m6 != other.m6) {
      return false;
    }
    if (this->m7 != other.m7) {
      return false;
    }
    if (this->st != other.st) {
      return false;
    }
    return true;
  }
  bool operator!=(const Motor_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Motor_

// alias to use template instance with default allocator
using Motor =
  motor_interface::msg::Motor_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace motor_interface

#endif  // MOTOR_INTERFACE__MSG__DETAIL__MOTOR__STRUCT_HPP_
