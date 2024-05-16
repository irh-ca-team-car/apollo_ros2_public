cmake_minimum_required(VERSION 3.5)
project(apollo)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH};/opt/libtorch)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(apollo_msgs REQUIRED)
find_package(CUDA REQUIRED)
find_package(tf2_ros REQUIRED)

if(OPENMP_FOUND)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

add_executable(
radar_detection_component
../../../src/main/radar_detection.cpp
../../../src/component/radar_detection.cpp
../../../src/modules/perception/onboard/msg_buffer/msg_buffer.cpp
../../../src/modules/perception/common/sensor_manager/sensor_manager.cpp
../../../src/modules/perception/onboard/transform_wrapper/transform_wrapper.cpp
../../../src/modules/transform/buffer.cpp
../../../src/modules/perception/onboard/common_flags/common_flags.cpp
../../../src/modules/perception/lib/registerer/registerer.cpp
../../../src/modules/perception/common/io/io_util.cpp
../../../src/modules/perception/common/perception_gflags.cpp
../../../src/modules/perception/lib/config_manager/config_manager.cpp
../../../src/modules/perception/radar/lib/tracker/filter/adaptive_kalman_filter.cpp
../../../src/modules/perception/radar/app/radar_obstacle_perception.cpp
../../../src/modules/perception/radar/lib/detector/conti_ars_detector/conti_ars_detector.cpp
../../../src/modules/perception/radar/lib/preprocessor/conti_ars_preprocessor/conti_ars_preprocessor.cpp
../../../src/modules/perception/radar/lib/tracker/conti_ars_tracker/conti_ars_tracker.cpp
../../../src/modules/perception/radar/lib/roi_filter/hdmap_radar_roi_filter/hdmap_radar_roi_filter.cpp
../../../src/modules/perception/radar/lib/tracker/matcher/hm_matcher.cpp
../../../src/modules/perception/radar/lib/tracker/common/radar_track.cpp
../../../src/modules/perception/radar/lib/tracker/common/radar_track_manager.cpp
../../../src/modules/perception/radar/common/radar_util.cpp
../../../src/modules/perception/common/graph/connected_component_analysis.cpp
../../../src/modules/perception/radar/lib/interface/base_matcher.cpp
../../../src/modules/perception/common/geometry/roi_filter.cpp
../../../src/modules/perception/common/graph/disjoint_set.cpp
../../../src/modules/perception/common/graph/graph_segmentor.cpp
)

target_include_directories(radar_detection_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/aarch64-linux/include
    /usr/local/cuda/targets/x86_64-linux/include)
target_compile_definitions(radar_detection_component PRIVATE USE_GPU)
ament_target_dependencies(
  radar_detection_component
  rclcpp
  apollo_msgs tf2_ros)
list(REMOVE_ITEM CUDA_npp_LIBRARY CUDA_nppicom_LIBRARY-NOTFOUND)
list(REMOVE_ITEM TORCH_LIBRARIES kineto_LIBRARY-NOTFOUND)

target_link_libraries(radar_detection_component common hdmap perception_base perception_internal ${TORCH_LIBRARIES} ${CUDA_LIBRARIES} ${CUDA_npp_LIBRARY} ${CUDA_CUBLAS_LIBRARIES})

install(TARGETS
  radar_detection_component
  DESTINATION lib/${PROJECT_NAME})
