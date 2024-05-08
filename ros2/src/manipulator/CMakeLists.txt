cmake_minimum_required(VERSION 3.8)
project(manipulator)

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
find_package(std_msgs REQUIRED)
find_package(motor_interface REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

# Build
add_executable(manipulator_write src/pathW.cpp src/pathRW.cpp src/serial.cpp)
ament_target_dependencies(manipulator_write rclcpp std_msgs motor_interface)

add_executable(manipulator_read src/pathR.cpp src/pathRW.cpp src/serial.cpp)
ament_target_dependencies(manipulator_read rclcpp std_msgs motor_interface)

add_executable(manipulator_run src/motor.cpp src/pathRW.cpp src/serial.cpp src/dynamixel_protocols.cpp)
ament_target_dependencies(manipulator_run rclcpp std_msgs motor_interface)

# Install
install (TARGETS
  manipulator_write
  manipulator_read
  manipulator_run
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
