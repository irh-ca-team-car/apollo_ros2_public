cmake_minimum_required(VERSION 3.5)
project(apollo)


find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(OpenCV 4 REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(apollo_msgs REQUIRED)

add_executable(
camera_component
../../../src/main/camera.cpp
../../../src/cyber/common/file.cpp
../../../src/component/camera.cpp
../../../src/common/utils.cpp)

ament_target_dependencies(camera_component apollo_msgs rclcpp cv_bridge OpenCV)
target_link_libraries(
  camera_component
  common)
target_include_directories(camera_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/x86_64-linux/include
)
install(TARGETS
  camera_component
  DESTINATION lib/${PROJECT_NAME})