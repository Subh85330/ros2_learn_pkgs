cmake_minimum_required(VERSION 3.5)
project(cpp_learn_ros2)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)


# for new programe
add_executable(cpp_node src/simple_node.cpp)
ament_target_dependencies(cpp_node rclcpp)

add_executable(cpp_node_oop src/simple_node_oop1.cpp)
ament_target_dependencies(cpp_node_oop rclcpp)


add_executable(robot_news_publisher src/robot_news_publisher.cpp)
ament_target_dependencies(robot_news_publisher rclcpp example_interfaces)

# install node
install(TARGETS
   cpp_node
   cpp_node_oop
   robot_news_publisher
   DESTINATION  lib/${PROJECT_NAME}
)



ament_package()
