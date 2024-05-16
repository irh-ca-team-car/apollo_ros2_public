cmake_minimum_required(VERSION 3.5)
project(apollo)


find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(OpenCV 4 REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(apollo_msgs REQUIRED)
find_package(image_transport REQUIRED)
add_executable(
camera_adapter_component
../../../src/main/camera-adapter.cpp
../../../src/component/camera-adapter.cpp)

ament_target_dependencies(camera_adapter_component apollo_msgs rclcpp cv_bridge OpenCV image_transport)
target_link_libraries(
  camera_adapter_component
  common)
target_include_directories(camera_adapter_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/x86_64-linux/include
)
install(TARGETS
  camera_adapter_component
  DESTINATION lib/${PROJECT_NAME})