; Auto-generated. Do not edit!


(cl:in-package sagitari_debug-msg)


;//! \htmlinclude sagitari_img_debug.msg.html

(cl:defclass <sagitari_img_debug> (roslisp-msg-protocol:ros-message)
  ((title
    :reader title
    :initarg :title
    :type cl:string
    :initform "")
   (image
    :reader image
    :initarg :image
    :type sensor_msgs-msg:Image
    :initform (cl:make-instance 'sensor_msgs-msg:Image)))
)

(cl:defclass sagitari_img_debug (<sagitari_img_debug>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <sagitari_img_debug>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'sagitari_img_debug)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sagitari_debug-msg:<sagitari_img_debug> is deprecated: use sagitari_debug-msg:sagitari_img_debug instead.")))

(cl:ensure-generic-function 'title-val :lambda-list '(m))
(cl:defmethod title-val ((m <sagitari_img_debug>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sagitari_debug-msg:title-val is deprecated.  Use sagitari_debug-msg:title instead.")
  (title m))

(cl:ensure-generic-function 'image-val :lambda-list '(m))
(cl:defmethod image-val ((m <sagitari_img_debug>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sagitari_debug-msg:image-val is deprecated.  Use sagitari_debug-msg:image instead.")
  (image m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <sagitari_img_debug>) ostream)
  "Serializes a message object of type '<sagitari_img_debug>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'title))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'title))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'image) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <sagitari_img_debug>) istream)
  "Deserializes a message object of type '<sagitari_img_debug>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'title) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'title) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'image) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<sagitari_img_debug>)))
  "Returns string type for a message object of type '<sagitari_img_debug>"
  "sagitari_debug/sagitari_img_debug")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'sagitari_img_debug)))
  "Returns string type for a message object of type 'sagitari_img_debug"
  "sagitari_debug/sagitari_img_debug")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<sagitari_img_debug>)))
  "Returns md5sum for a message object of type '<sagitari_img_debug>"
  "c762dcea1190e889820cef1cb4eeff24")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'sagitari_img_debug)))
  "Returns md5sum for a message object of type 'sagitari_img_debug"
  "c762dcea1190e889820cef1cb4eeff24")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<sagitari_img_debug>)))
  "Returns full string definition for message of type '<sagitari_img_debug>"
  (cl:format cl:nil "string title~%sensor_msgs/Image image~%================================================================================~%MSG: sensor_msgs/Image~%# This message contains an uncompressed image~%# (0, 0) is at top-left corner of image~%#~%~%Header header        # Header timestamp should be acquisition time of image~%                     # Header frame_id should be optical frame of camera~%                     # origin of frame should be optical center of camera~%                     # +x should point to the right in the image~%                     # +y should point down in the image~%                     # +z should point into to plane of the image~%                     # If the frame_id here and the frame_id of the CameraInfo~%                     # message associated with the image conflict~%                     # the behavior is undefined~%~%uint32 height         # image height, that is, number of rows~%uint32 width          # image width, that is, number of columns~%~%# The legal values for encoding are in file src/image_encodings.cpp~%# If you want to standardize a new string format, join~%# ros-users@lists.sourceforge.net and send an email proposing a new encoding.~%~%string encoding       # Encoding of pixels -- channel meaning, ordering, size~%                      # taken from the list of strings in include/sensor_msgs/image_encodings.h~%~%uint8 is_bigendian    # is this data bigendian?~%uint32 step           # Full row length in bytes~%uint8[] data          # actual matrix data, size is (step * rows)~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'sagitari_img_debug)))
  "Returns full string definition for message of type 'sagitari_img_debug"
  (cl:format cl:nil "string title~%sensor_msgs/Image image~%================================================================================~%MSG: sensor_msgs/Image~%# This message contains an uncompressed image~%# (0, 0) is at top-left corner of image~%#~%~%Header header        # Header timestamp should be acquisition time of image~%                     # Header frame_id should be optical frame of camera~%                     # origin of frame should be optical center of camera~%                     # +x should point to the right in the image~%                     # +y should point down in the image~%                     # +z should point into to plane of the image~%                     # If the frame_id here and the frame_id of the CameraInfo~%                     # message associated with the image conflict~%                     # the behavior is undefined~%~%uint32 height         # image height, that is, number of rows~%uint32 width          # image width, that is, number of columns~%~%# The legal values for encoding are in file src/image_encodings.cpp~%# If you want to standardize a new string format, join~%# ros-users@lists.sourceforge.net and send an email proposing a new encoding.~%~%string encoding       # Encoding of pixels -- channel meaning, ordering, size~%                      # taken from the list of strings in include/sensor_msgs/image_encodings.h~%~%uint8 is_bigendian    # is this data bigendian?~%uint32 step           # Full row length in bytes~%uint8[] data          # actual matrix data, size is (step * rows)~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <sagitari_img_debug>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'title))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'image))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <sagitari_img_debug>))
  "Converts a ROS message object to a list"
  (cl:list 'sagitari_img_debug
    (cl:cons ':title (title msg))
    (cl:cons ':image (image msg))
))
