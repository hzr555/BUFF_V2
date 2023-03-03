; Auto-generated. Do not edit!


(cl:in-package uart_process_2-msg)


;//! \htmlinclude uart_send.msg.html

(cl:defclass <uart_send> (roslisp-msg-protocol:ros-message)
  ((curYaw
    :reader curYaw
    :initarg :curYaw
    :type cl:float
    :initform 0.0)
   (curPitch
    :reader curPitch
    :initarg :curPitch
    :type cl:float
    :initform 0.0)
   (curDistance
    :reader curDistance
    :initarg :curDistance
    :type cl:float
    :initform 0.0)
   (time
    :reader time
    :initarg :time
    :type cl:integer
    :initform 0)
   (predictYaw
    :reader predictYaw
    :initarg :predictYaw
    :type cl:float
    :initform 0.0)
   (predictPitch
    :reader predictPitch
    :initarg :predictPitch
    :type cl:float
    :initform 0.0)
   (predictLatency
    :reader predictLatency
    :initarg :predictLatency
    :type cl:integer
    :initform 0)
   (attackFlag
    :reader attackFlag
    :initarg :attackFlag
    :type cl:fixnum
    :initform 0))
)

(cl:defclass uart_send (<uart_send>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <uart_send>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'uart_send)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name uart_process_2-msg:<uart_send> is deprecated: use uart_process_2-msg:uart_send instead.")))

(cl:ensure-generic-function 'curYaw-val :lambda-list '(m))
(cl:defmethod curYaw-val ((m <uart_send>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader uart_process_2-msg:curYaw-val is deprecated.  Use uart_process_2-msg:curYaw instead.")
  (curYaw m))

(cl:ensure-generic-function 'curPitch-val :lambda-list '(m))
(cl:defmethod curPitch-val ((m <uart_send>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader uart_process_2-msg:curPitch-val is deprecated.  Use uart_process_2-msg:curPitch instead.")
  (curPitch m))

(cl:ensure-generic-function 'curDistance-val :lambda-list '(m))
(cl:defmethod curDistance-val ((m <uart_send>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader uart_process_2-msg:curDistance-val is deprecated.  Use uart_process_2-msg:curDistance instead.")
  (curDistance m))

(cl:ensure-generic-function 'time-val :lambda-list '(m))
(cl:defmethod time-val ((m <uart_send>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader uart_process_2-msg:time-val is deprecated.  Use uart_process_2-msg:time instead.")
  (time m))

(cl:ensure-generic-function 'predictYaw-val :lambda-list '(m))
(cl:defmethod predictYaw-val ((m <uart_send>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader uart_process_2-msg:predictYaw-val is deprecated.  Use uart_process_2-msg:predictYaw instead.")
  (predictYaw m))

(cl:ensure-generic-function 'predictPitch-val :lambda-list '(m))
(cl:defmethod predictPitch-val ((m <uart_send>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader uart_process_2-msg:predictPitch-val is deprecated.  Use uart_process_2-msg:predictPitch instead.")
  (predictPitch m))

(cl:ensure-generic-function 'predictLatency-val :lambda-list '(m))
(cl:defmethod predictLatency-val ((m <uart_send>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader uart_process_2-msg:predictLatency-val is deprecated.  Use uart_process_2-msg:predictLatency instead.")
  (predictLatency m))

(cl:ensure-generic-function 'attackFlag-val :lambda-list '(m))
(cl:defmethod attackFlag-val ((m <uart_send>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader uart_process_2-msg:attackFlag-val is deprecated.  Use uart_process_2-msg:attackFlag instead.")
  (attackFlag m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <uart_send>) ostream)
  "Serializes a message object of type '<uart_send>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'curYaw))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'curPitch))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'curDistance))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'time)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'time)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'time)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'time)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'predictYaw))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'predictPitch))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'predictLatency)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'predictLatency)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'predictLatency)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'predictLatency)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'attackFlag)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <uart_send>) istream)
  "Deserializes a message object of type '<uart_send>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'curYaw) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'curPitch) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'curDistance) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'time)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'time)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'time)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'time)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'predictYaw) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'predictPitch) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'predictLatency)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'predictLatency)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'predictLatency)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'predictLatency)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'attackFlag)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<uart_send>)))
  "Returns string type for a message object of type '<uart_send>"
  "uart_process_2/uart_send")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'uart_send)))
  "Returns string type for a message object of type 'uart_send"
  "uart_process_2/uart_send")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<uart_send>)))
  "Returns md5sum for a message object of type '<uart_send>"
  "d112f4a4a5820fb9f88abfc424376903")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'uart_send)))
  "Returns md5sum for a message object of type 'uart_send"
  "d112f4a4a5820fb9f88abfc424376903")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<uart_send>)))
  "Returns full string definition for message of type '<uart_send>"
  (cl:format cl:nil "float32 curYaw~%float32 curPitch~%float32 curDistance~%uint32  time~%float32 predictYaw~%float32 predictPitch~%uint32  predictLatency~%uint8 attackFlag~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'uart_send)))
  "Returns full string definition for message of type 'uart_send"
  (cl:format cl:nil "float32 curYaw~%float32 curPitch~%float32 curDistance~%uint32  time~%float32 predictYaw~%float32 predictPitch~%uint32  predictLatency~%uint8 attackFlag~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <uart_send>))
  (cl:+ 0
     4
     4
     4
     4
     4
     4
     4
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <uart_send>))
  "Converts a ROS message object to a list"
  (cl:list 'uart_send
    (cl:cons ':curYaw (curYaw msg))
    (cl:cons ':curPitch (curPitch msg))
    (cl:cons ':curDistance (curDistance msg))
    (cl:cons ':time (time msg))
    (cl:cons ':predictYaw (predictYaw msg))
    (cl:cons ':predictPitch (predictPitch msg))
    (cl:cons ':predictLatency (predictLatency msg))
    (cl:cons ':attackFlag (attackFlag msg))
))
