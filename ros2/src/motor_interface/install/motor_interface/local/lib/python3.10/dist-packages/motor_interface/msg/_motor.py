# generated from rosidl_generator_py/resource/_idl.py.em
# with input from motor_interface:msg/Motor.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Motor(type):
    """Metaclass of message 'Motor'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('motor_interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'motor_interface.msg.Motor')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__motor
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__motor
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__motor
            cls._TYPE_SUPPORT = module.type_support_msg__msg__motor
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__motor

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Motor(metaclass=Metaclass_Motor):
    """Message class 'Motor'."""

    __slots__ = [
        '_m1',
        '_m2',
        '_m3',
        '_m4',
        '_m5',
        '_m6',
        '_m7',
        '_st',
    ]

    _fields_and_field_types = {
        'm1': 'int64',
        'm2': 'int64',
        'm3': 'int64',
        'm4': 'int64',
        'm5': 'int64',
        'm6': 'int64',
        'm7': 'int64',
        'st': 'int64',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.m1 = kwargs.get('m1', int())
        self.m2 = kwargs.get('m2', int())
        self.m3 = kwargs.get('m3', int())
        self.m4 = kwargs.get('m4', int())
        self.m5 = kwargs.get('m5', int())
        self.m6 = kwargs.get('m6', int())
        self.m7 = kwargs.get('m7', int())
        self.st = kwargs.get('st', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.m1 != other.m1:
            return False
        if self.m2 != other.m2:
            return False
        if self.m3 != other.m3:
            return False
        if self.m4 != other.m4:
            return False
        if self.m5 != other.m5:
            return False
        if self.m6 != other.m6:
            return False
        if self.m7 != other.m7:
            return False
        if self.st != other.st:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def m1(self):
        """Message field 'm1'."""
        return self._m1

    @m1.setter
    def m1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'm1' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'm1' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._m1 = value

    @builtins.property
    def m2(self):
        """Message field 'm2'."""
        return self._m2

    @m2.setter
    def m2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'm2' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'm2' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._m2 = value

    @builtins.property
    def m3(self):
        """Message field 'm3'."""
        return self._m3

    @m3.setter
    def m3(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'm3' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'm3' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._m3 = value

    @builtins.property
    def m4(self):
        """Message field 'm4'."""
        return self._m4

    @m4.setter
    def m4(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'm4' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'm4' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._m4 = value

    @builtins.property
    def m5(self):
        """Message field 'm5'."""
        return self._m5

    @m5.setter
    def m5(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'm5' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'm5' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._m5 = value

    @builtins.property
    def m6(self):
        """Message field 'm6'."""
        return self._m6

    @m6.setter
    def m6(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'm6' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'm6' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._m6 = value

    @builtins.property
    def m7(self):
        """Message field 'm7'."""
        return self._m7

    @m7.setter
    def m7(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'm7' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'm7' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._m7 = value

    @builtins.property
    def st(self):
        """Message field 'st'."""
        return self._st

    @st.setter
    def st(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'st' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'st' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._st = value
