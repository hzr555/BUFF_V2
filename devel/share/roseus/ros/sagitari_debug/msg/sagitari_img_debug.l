;; Auto-generated. Do not edit!


(when (boundp 'sagitari_debug::sagitari_img_debug)
  (if (not (find-package "SAGITARI_DEBUG"))
    (make-package "SAGITARI_DEBUG"))
  (shadow 'sagitari_img_debug (find-package "SAGITARI_DEBUG")))
(unless (find-package "SAGITARI_DEBUG::SAGITARI_IMG_DEBUG")
  (make-package "SAGITARI_DEBUG::SAGITARI_IMG_DEBUG"))

(in-package "ROS")
;;//! \htmlinclude sagitari_img_debug.msg.html
(if (not (find-package "SENSOR_MSGS"))
  (ros::roseus-add-msgs "sensor_msgs"))


(defclass sagitari_debug::sagitari_img_debug
  :super ros::object
  :slots (_title _image ))

(defmethod sagitari_debug::sagitari_img_debug
  (:init
   (&key
    ((:title __title) "")
    ((:image __image) (instance sensor_msgs::Image :init))
    )
   (send-super :init)
   (setq _title (string __title))
   (setq _image __image)
   self)
  (:title
   (&optional __title)
   (if __title (setq _title __title)) _title)
  (:image
   (&rest __image)
   (if (keywordp (car __image))
       (send* _image __image)
     (progn
       (if __image (setq _image (car __image)))
       _image)))
  (:serialization-length
   ()
   (+
    ;; string _title
    4 (length _title)
    ;; sensor_msgs/Image _image
    (send _image :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _title
       (write-long (length _title) s) (princ _title s)
     ;; sensor_msgs/Image _image
       (send _image :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _title
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _title (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; sensor_msgs/Image _image
     (send _image :deserialize buf ptr-) (incf ptr- (send _image :serialization-length))
   ;;
   self)
  )

(setf (get sagitari_debug::sagitari_img_debug :md5sum-) "c762dcea1190e889820cef1cb4eeff24")
(setf (get sagitari_debug::sagitari_img_debug :datatype-) "sagitari_debug/sagitari_img_debug")
(setf (get sagitari_debug::sagitari_img_debug :definition-)
      "string title
sensor_msgs/Image image
================================================================================
MSG: sensor_msgs/Image
# This message contains an uncompressed image
# (0, 0) is at top-left corner of image
#

Header header        # Header timestamp should be acquisition time of image
                     # Header frame_id should be optical frame of camera
                     # origin of frame should be optical center of camera
                     # +x should point to the right in the image
                     # +y should point down in the image
                     # +z should point into to plane of the image
                     # If the frame_id here and the frame_id of the CameraInfo
                     # message associated with the image conflict
                     # the behavior is undefined

uint32 height         # image height, that is, number of rows
uint32 width          # image width, that is, number of columns

# The legal values for encoding are in file src/image_encodings.cpp
# If you want to standardize a new string format, join
# ros-users@lists.sourceforge.net and send an email proposing a new encoding.

string encoding       # Encoding of pixels -- channel meaning, ordering, size
                      # taken from the list of strings in include/sensor_msgs/image_encodings.h

uint8 is_bigendian    # is this data bigendian?
uint32 step           # Full row length in bytes
uint8[] data          # actual matrix data, size is (step * rows)

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

")



(provide :sagitari_debug/sagitari_img_debug "c762dcea1190e889820cef1cb4eeff24")


