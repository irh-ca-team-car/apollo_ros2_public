cmake_minimum_required(VERSION 3.5)
project(apollo)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH};/opt/libtorch)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(OpenCV REQUIRED)
find_package(apollo_msgs REQUIRED)

find_package(PCL REQUIRED)

add_executable(
online_visualizer_component
../../../src/component/online_visualizer.cpp
../../../src/main/online_visualizer.cpp
../../../src/modules/localization/msf/local_tool/local_visualization/engine/visualization_manager.cpp
../../../src/modules/localization/common/localization_gflags.cpp
../../../src/modules/localization/msf/common/io/velodyne_utility.cpp
../../../src/modules/localization/msf/local_pyramid_map/base_map/base_map_config.cpp
../../../src/modules/localization/msf/local_tool/local_visualization/engine/visualization_engine.cpp
)

target_include_directories(online_visualizer_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/x86_64-linux/include)

ament_target_dependencies(
  online_visualizer_component
  rclcpp
  apollo_msgs)
target_link_libraries(online_visualizer_component common ${OpenCV_LIBRARIES} ${PCL_LIBRARIES})
target_compile_definitions(online_visualizer_component PRIVATE USE_GPU)
install(TARGETS
  online_visualizer_component
  DESTINATION lib/${PROJECT_NAME})
