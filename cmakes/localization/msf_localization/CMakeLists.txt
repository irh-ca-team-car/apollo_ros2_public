cmake_minimum_required(VERSION 3.5)
project(apollo)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH};/opt/libtorch)

EXECUTE_PROCESS( COMMAND uname -m COMMAND tr -d '\n' OUTPUT_VARIABLE ARCHITECTURE )

if( ${ARCHITECTURE} STREQUAL "x86_64" )

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(OpenCV REQUIRED)
find_package(apollo_msgs REQUIRED)

find_package(PCL REQUIRED)
find_package(FastRTPS REQUIRED)
find_package(PROJ4 REQUIRED)
find_package(tf2_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

add_executable(
msf_localization_component
../../../src/component/msf_localization.cpp
../../../src/main/msf_localization.cpp
../../../src/modules/localization/common/localization_gflags.cpp
../../../src/modules/localization/msf/msf_localization.cpp
../../../src/modules/transform/transform_broadcaster.cpp
../../../src/modules/localization/msf/common/util/compression.cpp
../../../src/modules/localization/msf/common/util/file_utility.cpp
../../../src/modules/localization/msf/common/util/frame_transform.cpp
../../../src/modules/localization/msf/local_pyramid_map/base_map/base_map.cpp
../../../src/modules/localization/msf/local_pyramid_map/base_map/base_map_config.cpp
../../../src/modules/localization/msf/local_pyramid_map/base_map/base_map_matrix.cpp
../../../src/modules/localization/msf/local_pyramid_map/base_map/base_map_node.cpp
../../../src/modules/localization/msf/local_pyramid_map/base_map/base_map_node_config.cpp
../../../src/modules/localization/msf/local_pyramid_map/base_map/base_map_node_index.cpp
../../../src/modules/localization/msf/local_pyramid_map/base_map/base_map_pool.cpp
../../../src/modules/localization/msf/local_pyramid_map/pyramid_map/pyramid_map.cpp
../../../src/modules/localization/msf/local_pyramid_map/pyramid_map/pyramid_map_config.cpp
../../../src/modules/localization/msf/local_pyramid_map/pyramid_map/pyramid_map_matrix.cpp
../../../src/modules/localization/msf/local_pyramid_map/pyramid_map/pyramid_map_matrix_handler.cpp
../../../src/modules/localization/msf/local_pyramid_map/pyramid_map/pyramid_map_node.cpp
../../../src/modules/localization/msf/local_pyramid_map/pyramid_map/pyramid_map_node_config.cpp
../../../src/modules/localization/msf/local_pyramid_map/pyramid_map/pyramid_map_pool.cpp
../../../src/modules/localization/msf/local_integ/gnss_msg_transfer.cpp
../../../src/modules/localization/msf/local_integ/lidar_msg_transfer.cpp
../../../src/modules/localization/msf/local_integ/localization_gnss_process.cpp
../../../src/modules/localization/msf/local_integ/localization_integ.cpp
../../../src/modules/localization/msf/local_integ/localization_integ_impl.cpp
../../../src/modules/localization/msf/local_integ/localization_integ_process.cpp
../../../src/modules/localization/msf/local_integ/localization_lidar.cpp
../../../src/modules/localization/msf/local_integ/localization_lidar_process.cpp
../../../src/modules/localization/msf/local_integ/measure_republish_process.cpp
../../../src/modules/localization/msf/local_integ/online_localization_expert.cpp
)

target_include_directories(msf_localization_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/x86_64-linux/include)

ament_target_dependencies(
  msf_localization_component
  rclcpp
  apollo_msgs  tf2_msgs geometry_msgs)

target_link_libraries(msf_localization_component common ${OpenCV_LIBRARIES} ${PCL_LIBRARIES} ${FastRTPS_LIBRARIES} /usr/local/lib/libproj.so.12.0.0 ${CMAKE_CURRENT_SOURCE_DIR}/../../../include/modules/localization/msf/common/liblocalization_msf.so)
target_compile_definitions(msf_localization_component PRIVATE USE_GPU )
install(TARGETS
  msf_localization_component
  DESTINATION lib/${PROJECT_NAME})

endif()