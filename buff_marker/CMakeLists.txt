cmake_minimum_required(VERSION 3.5)
project(buff_marker)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(example_interfaces REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(rcutils REQUIRED)
find_package(std_msgs REQUIRED)
find_package(OpenCV REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(image_transport REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(gimbal_msgs REQUIRED)
find_package(debug_msgs REQUIRED)

if(BUILD_TESTING) 
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

include_directories(include)

# create ament index resource which references the libraries in the binary dir
set(node_plugins "")

# File camera
add_library(buff_marker SHARED
  src/buff.cpp
  src/getAngle.cpp
  src/buff_node.cpp
  src/targetTo.cpp
)
target_compile_definitions(buff_marker
  PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(buff_marker
  "rclcpp"
  "rclcpp_components"
  "OpenCV"
  "cv_bridge"
  "std_msgs"
  "sensor_msgs"
  "image_transport"
  "gimbal_msgs"
  "debug_msgs"
  )
rclcpp_components_register_nodes(buff_marker "buff_::Buff")
set(node_plugins "${node_plugins}buff_::Buff;$<TARGET_FILE:buff_marker>\n")

install(TARGETS
  buff_marker
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

install(TARGETS
  DESTINATION lib/${PROJECT_NAME})

# Install launch files.
install(DIRECTORY
  #launch
  DESTINATION share/${PROJECT_NAME}
)


ament_package()
