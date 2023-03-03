# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from uart_process_2/uart_send.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class uart_send(genpy.Message):
  _md5sum = "d112f4a4a5820fb9f88abfc424376903"
  _type = "uart_process_2/uart_send"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """float32 curYaw
float32 curPitch
float32 curDistance
uint32  time
float32 predictYaw
float32 predictPitch
uint32  predictLatency
uint8 attackFlag"""
  __slots__ = ['curYaw','curPitch','curDistance','time','predictYaw','predictPitch','predictLatency','attackFlag']
  _slot_types = ['float32','float32','float32','uint32','float32','float32','uint32','uint8']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       curYaw,curPitch,curDistance,time,predictYaw,predictPitch,predictLatency,attackFlag

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(uart_send, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.curYaw is None:
        self.curYaw = 0.
      if self.curPitch is None:
        self.curPitch = 0.
      if self.curDistance is None:
        self.curDistance = 0.
      if self.time is None:
        self.time = 0
      if self.predictYaw is None:
        self.predictYaw = 0.
      if self.predictPitch is None:
        self.predictPitch = 0.
      if self.predictLatency is None:
        self.predictLatency = 0
      if self.attackFlag is None:
        self.attackFlag = 0
    else:
      self.curYaw = 0.
      self.curPitch = 0.
      self.curDistance = 0.
      self.time = 0
      self.predictYaw = 0.
      self.predictPitch = 0.
      self.predictLatency = 0
      self.attackFlag = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_3fI2fIB().pack(_x.curYaw, _x.curPitch, _x.curDistance, _x.time, _x.predictYaw, _x.predictPitch, _x.predictLatency, _x.attackFlag))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      _x = self
      start = end
      end += 29
      (_x.curYaw, _x.curPitch, _x.curDistance, _x.time, _x.predictYaw, _x.predictPitch, _x.predictLatency, _x.attackFlag,) = _get_struct_3fI2fIB().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_3fI2fIB().pack(_x.curYaw, _x.curPitch, _x.curDistance, _x.time, _x.predictYaw, _x.predictPitch, _x.predictLatency, _x.attackFlag))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      _x = self
      start = end
      end += 29
      (_x.curYaw, _x.curPitch, _x.curDistance, _x.time, _x.predictYaw, _x.predictPitch, _x.predictLatency, _x.attackFlag,) = _get_struct_3fI2fIB().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_3fI2fIB = None
def _get_struct_3fI2fIB():
    global _struct_3fI2fIB
    if _struct_3fI2fIB is None:
        _struct_3fI2fIB = struct.Struct("<3fI2fIB")
    return _struct_3fI2fIB