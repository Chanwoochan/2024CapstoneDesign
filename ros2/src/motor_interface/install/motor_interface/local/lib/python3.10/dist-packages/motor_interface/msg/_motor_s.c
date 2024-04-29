// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from motor_interface:msg/Motor.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "motor_interface/msg/detail/motor__struct.h"
#include "motor_interface/msg/detail/motor__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool motor_interface__msg__motor__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[33];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("motor_interface.msg._motor.Motor", full_classname_dest, 32) == 0);
  }
  motor_interface__msg__Motor * ros_message = _ros_message;
  {  // m1
    PyObject * field = PyObject_GetAttrString(_pymsg, "m1");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->m1 = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // m2
    PyObject * field = PyObject_GetAttrString(_pymsg, "m2");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->m2 = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // m3
    PyObject * field = PyObject_GetAttrString(_pymsg, "m3");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->m3 = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // m4
    PyObject * field = PyObject_GetAttrString(_pymsg, "m4");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->m4 = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // m5
    PyObject * field = PyObject_GetAttrString(_pymsg, "m5");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->m5 = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // m6
    PyObject * field = PyObject_GetAttrString(_pymsg, "m6");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->m6 = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // m7
    PyObject * field = PyObject_GetAttrString(_pymsg, "m7");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->m7 = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // st
    PyObject * field = PyObject_GetAttrString(_pymsg, "st");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->st = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * motor_interface__msg__motor__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Motor */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("motor_interface.msg._motor");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Motor");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  motor_interface__msg__Motor * ros_message = (motor_interface__msg__Motor *)raw_ros_message;
  {  // m1
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->m1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "m1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // m2
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->m2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "m2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // m3
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->m3);
    {
      int rc = PyObject_SetAttrString(_pymessage, "m3", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // m4
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->m4);
    {
      int rc = PyObject_SetAttrString(_pymessage, "m4", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // m5
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->m5);
    {
      int rc = PyObject_SetAttrString(_pymessage, "m5", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // m6
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->m6);
    {
      int rc = PyObject_SetAttrString(_pymessage, "m6", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // m7
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->m7);
    {
      int rc = PyObject_SetAttrString(_pymessage, "m7", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // st
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->st);
    {
      int rc = PyObject_SetAttrString(_pymessage, "st", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
