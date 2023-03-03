;; Auto-generated. Do not edit!


(when (boundp 'uart_process_2::uart_send)
  (if (not (find-package "UART_PROCESS_2"))
    (make-package "UART_PROCESS_2"))
  (shadow 'uart_send (find-package "UART_PROCESS_2")))
(unless (find-package "UART_PROCESS_2::UART_SEND")
  (make-package "UART_PROCESS_2::UART_SEND"))

(in-package "ROS")
;;//! \htmlinclude uart_send.msg.html


(defclass uart_process_2::uart_send
  :super ros::object
  :slots (_curYaw _curPitch _curDistance _time _predictYaw _predictPitch _predictLatency _attackFlag ))

(defmethod uart_process_2::uart_send
  (:init
   (&key
    ((:curYaw __curYaw) 0.0)
    ((:curPitch __curPitch) 0.0)
    ((:curDistance __curDistance) 0.0)
    ((:time __time) 0)
    ((:predictYaw __predictYaw) 0.0)
    ((:predictPitch __predictPitch) 0.0)
    ((:predictLatency __predictLatency) 0)
    ((:attackFlag __attackFlag) 0)
    )
   (send-super :init)
   (setq _curYaw (float __curYaw))
   (setq _curPitch (float __curPitch))
   (setq _curDistance (float __curDistance))
   (setq _time (round __time))
   (setq _predictYaw (float __predictYaw))
   (setq _predictPitch (float __predictPitch))
   (setq _predictLatency (round __predictLatency))
   (setq _attackFlag (round __attackFlag))
   self)
  (:curYaw
   (&optional __curYaw)
   (if __curYaw (setq _curYaw __curYaw)) _curYaw)
  (:curPitch
   (&optional __curPitch)
   (if __curPitch (setq _curPitch __curPitch)) _curPitch)
  (:curDistance
   (&optional __curDistance)
   (if __curDistance (setq _curDistance __curDistance)) _curDistance)
  (:time
   (&optional __time)
   (if __time (setq _time __time)) _time)
  (:predictYaw
   (&optional __predictYaw)
   (if __predictYaw (setq _predictYaw __predictYaw)) _predictYaw)
  (:predictPitch
   (&optional __predictPitch)
   (if __predictPitch (setq _predictPitch __predictPitch)) _predictPitch)
  (:predictLatency
   (&optional __predictLatency)
   (if __predictLatency (setq _predictLatency __predictLatency)) _predictLatency)
  (:attackFlag
   (&optional __attackFlag)
   (if __attackFlag (setq _attackFlag __attackFlag)) _attackFlag)
  (:serialization-length
   ()
   (+
    ;; float32 _curYaw
    4
    ;; float32 _curPitch
    4
    ;; float32 _curDistance
    4
    ;; uint32 _time
    4
    ;; float32 _predictYaw
    4
    ;; float32 _predictPitch
    4
    ;; uint32 _predictLatency
    4
    ;; uint8 _attackFlag
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _curYaw
       (sys::poke _curYaw (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _curPitch
       (sys::poke _curPitch (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _curDistance
       (sys::poke _curDistance (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; uint32 _time
       (write-long _time s)
     ;; float32 _predictYaw
       (sys::poke _predictYaw (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _predictPitch
       (sys::poke _predictPitch (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; uint32 _predictLatency
       (write-long _predictLatency s)
     ;; uint8 _attackFlag
       (write-byte _attackFlag s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _curYaw
     (setq _curYaw (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _curPitch
     (setq _curPitch (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _curDistance
     (setq _curDistance (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; uint32 _time
     (setq _time (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float32 _predictYaw
     (setq _predictYaw (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _predictPitch
     (setq _predictPitch (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; uint32 _predictLatency
     (setq _predictLatency (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint8 _attackFlag
     (setq _attackFlag (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get uart_process_2::uart_send :md5sum-) "d112f4a4a5820fb9f88abfc424376903")
(setf (get uart_process_2::uart_send :datatype-) "uart_process_2/uart_send")
(setf (get uart_process_2::uart_send :definition-)
      "float32 curYaw
float32 curPitch
float32 curDistance
uint32  time
float32 predictYaw
float32 predictPitch
uint32  predictLatency
uint8 attackFlag
")



(provide :uart_process_2/uart_send "d112f4a4a5820fb9f88abfc424376903")


