// Auto-generated. Do not edit!

// (in-package uart_process_2.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class uart_send {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.curYaw = null;
      this.curPitch = null;
      this.curDistance = null;
      this.time = null;
      this.predictYaw = null;
      this.predictPitch = null;
      this.predictLatency = null;
      this.attackFlag = null;
    }
    else {
      if (initObj.hasOwnProperty('curYaw')) {
        this.curYaw = initObj.curYaw
      }
      else {
        this.curYaw = 0.0;
      }
      if (initObj.hasOwnProperty('curPitch')) {
        this.curPitch = initObj.curPitch
      }
      else {
        this.curPitch = 0.0;
      }
      if (initObj.hasOwnProperty('curDistance')) {
        this.curDistance = initObj.curDistance
      }
      else {
        this.curDistance = 0.0;
      }
      if (initObj.hasOwnProperty('time')) {
        this.time = initObj.time
      }
      else {
        this.time = 0;
      }
      if (initObj.hasOwnProperty('predictYaw')) {
        this.predictYaw = initObj.predictYaw
      }
      else {
        this.predictYaw = 0.0;
      }
      if (initObj.hasOwnProperty('predictPitch')) {
        this.predictPitch = initObj.predictPitch
      }
      else {
        this.predictPitch = 0.0;
      }
      if (initObj.hasOwnProperty('predictLatency')) {
        this.predictLatency = initObj.predictLatency
      }
      else {
        this.predictLatency = 0;
      }
      if (initObj.hasOwnProperty('attackFlag')) {
        this.attackFlag = initObj.attackFlag
      }
      else {
        this.attackFlag = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type uart_send
    // Serialize message field [curYaw]
    bufferOffset = _serializer.float32(obj.curYaw, buffer, bufferOffset);
    // Serialize message field [curPitch]
    bufferOffset = _serializer.float32(obj.curPitch, buffer, bufferOffset);
    // Serialize message field [curDistance]
    bufferOffset = _serializer.float32(obj.curDistance, buffer, bufferOffset);
    // Serialize message field [time]
    bufferOffset = _serializer.uint32(obj.time, buffer, bufferOffset);
    // Serialize message field [predictYaw]
    bufferOffset = _serializer.float32(obj.predictYaw, buffer, bufferOffset);
    // Serialize message field [predictPitch]
    bufferOffset = _serializer.float32(obj.predictPitch, buffer, bufferOffset);
    // Serialize message field [predictLatency]
    bufferOffset = _serializer.uint32(obj.predictLatency, buffer, bufferOffset);
    // Serialize message field [attackFlag]
    bufferOffset = _serializer.uint8(obj.attackFlag, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type uart_send
    let len;
    let data = new uart_send(null);
    // Deserialize message field [curYaw]
    data.curYaw = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [curPitch]
    data.curPitch = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [curDistance]
    data.curDistance = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [time]
    data.time = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [predictYaw]
    data.predictYaw = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [predictPitch]
    data.predictPitch = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [predictLatency]
    data.predictLatency = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [attackFlag]
    data.attackFlag = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 29;
  }

  static datatype() {
    // Returns string type for a message object
    return 'uart_process_2/uart_send';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd112f4a4a5820fb9f88abfc424376903';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 curYaw
    float32 curPitch
    float32 curDistance
    uint32  time
    float32 predictYaw
    float32 predictPitch
    uint32  predictLatency
    uint8 attackFlag
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new uart_send(null);
    if (msg.curYaw !== undefined) {
      resolved.curYaw = msg.curYaw;
    }
    else {
      resolved.curYaw = 0.0
    }

    if (msg.curPitch !== undefined) {
      resolved.curPitch = msg.curPitch;
    }
    else {
      resolved.curPitch = 0.0
    }

    if (msg.curDistance !== undefined) {
      resolved.curDistance = msg.curDistance;
    }
    else {
      resolved.curDistance = 0.0
    }

    if (msg.time !== undefined) {
      resolved.time = msg.time;
    }
    else {
      resolved.time = 0
    }

    if (msg.predictYaw !== undefined) {
      resolved.predictYaw = msg.predictYaw;
    }
    else {
      resolved.predictYaw = 0.0
    }

    if (msg.predictPitch !== undefined) {
      resolved.predictPitch = msg.predictPitch;
    }
    else {
      resolved.predictPitch = 0.0
    }

    if (msg.predictLatency !== undefined) {
      resolved.predictLatency = msg.predictLatency;
    }
    else {
      resolved.predictLatency = 0
    }

    if (msg.attackFlag !== undefined) {
      resolved.attackFlag = msg.attackFlag;
    }
    else {
      resolved.attackFlag = 0
    }

    return resolved;
    }
};

module.exports = uart_send;
