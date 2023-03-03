
(cl:in-package :asdf)

(defsystem "sagitari_debug-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :sensor_msgs-msg
)
  :components ((:file "_package")
    (:file "sagitari_img_debug" :depends-on ("_package_sagitari_img_debug"))
    (:file "_package_sagitari_img_debug" :depends-on ("_package"))
  ))