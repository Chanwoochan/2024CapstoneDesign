// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from motor_interface:msg/Motor.idl
// generated code does not contain a copyright notice
#include "motor_interface/msg/detail/motor__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "motor_interface/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "motor_interface/msg/detail/motor__struct.h"
#include "motor_interface/msg/detail/motor__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _Motor__ros_msg_type = motor_interface__msg__Motor;

static bool _Motor__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Motor__ros_msg_type * ros_message = static_cast<const _Motor__ros_msg_type *>(untyped_ros_message);
  // Field name: m1
  {
    cdr << ros_message->m1;
  }

  // Field name: m2
  {
    cdr << ros_message->m2;
  }

  // Field name: m3
  {
    cdr << ros_message->m3;
  }

  // Field name: m4
  {
    cdr << ros_message->m4;
  }

  // Field name: m5
  {
    cdr << ros_message->m5;
  }

  // Field name: m6
  {
    cdr << ros_message->m6;
  }

  // Field name: m7
  {
    cdr << ros_message->m7;
  }

  // Field name: st
  {
    cdr << ros_message->st;
  }

  return true;
}

static bool _Motor__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Motor__ros_msg_type * ros_message = static_cast<_Motor__ros_msg_type *>(untyped_ros_message);
  // Field name: m1
  {
    cdr >> ros_message->m1;
  }

  // Field name: m2
  {
    cdr >> ros_message->m2;
  }

  // Field name: m3
  {
    cdr >> ros_message->m3;
  }

  // Field name: m4
  {
    cdr >> ros_message->m4;
  }

  // Field name: m5
  {
    cdr >> ros_message->m5;
  }

  // Field name: m6
  {
    cdr >> ros_message->m6;
  }

  // Field name: m7
  {
    cdr >> ros_message->m7;
  }

  // Field name: st
  {
    cdr >> ros_message->st;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_motor_interface
size_t get_serialized_size_motor_interface__msg__Motor(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Motor__ros_msg_type * ros_message = static_cast<const _Motor__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name m1
  {
    size_t item_size = sizeof(ros_message->m1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name m2
  {
    size_t item_size = sizeof(ros_message->m2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name m3
  {
    size_t item_size = sizeof(ros_message->m3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name m4
  {
    size_t item_size = sizeof(ros_message->m4);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name m5
  {
    size_t item_size = sizeof(ros_message->m5);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name m6
  {
    size_t item_size = sizeof(ros_message->m6);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name m7
  {
    size_t item_size = sizeof(ros_message->m7);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name st
  {
    size_t item_size = sizeof(ros_message->st);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Motor__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_motor_interface__msg__Motor(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_motor_interface
size_t max_serialized_size_motor_interface__msg__Motor(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: m1
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: m2
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: m3
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: m4
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: m5
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: m6
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: m7
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: st
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _Motor__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_motor_interface__msg__Motor(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Motor = {
  "motor_interface::msg",
  "Motor",
  _Motor__cdr_serialize,
  _Motor__cdr_deserialize,
  _Motor__get_serialized_size,
  _Motor__max_serialized_size
};

static rosidl_message_type_support_t _Motor__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Motor,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, motor_interface, msg, Motor)() {
  return &_Motor__type_support;
}

#if defined(__cplusplus)
}
#endif
