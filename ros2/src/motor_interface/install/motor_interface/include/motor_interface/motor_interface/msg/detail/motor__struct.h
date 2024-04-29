// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from motor_interface:msg/Motor.idl
// generated code does not contain a copyright notice

#ifndef MOTOR_INTERFACE__MSG__DETAIL__MOTOR__STRUCT_H_
#define MOTOR_INTERFACE__MSG__DETAIL__MOTOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Motor in the package motor_interface.
typedef struct motor_interface__msg__Motor
{
  int64_t m1;
  int64_t m2;
  int64_t m3;
  int64_t m4;
  int64_t m5;
  int64_t m6;
  int64_t m7;
  int64_t st;
} motor_interface__msg__Motor;

// Struct for a sequence of motor_interface__msg__Motor.
typedef struct motor_interface__msg__Motor__Sequence
{
  motor_interface__msg__Motor * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} motor_interface__msg__Motor__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MOTOR_INTERFACE__MSG__DETAIL__MOTOR__STRUCT_H_
