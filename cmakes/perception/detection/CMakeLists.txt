cmake_minimum_required(VERSION 3.5)
project(apollo)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH};/opt/libtorch)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(apollo_msgs REQUIRED)
find_package(CUDA REQUIRED)
find_package(Torch REQUIRED)
find_package(PCL REQUIRED)
find_package(tf2_ros REQUIRED)

set(CUDA_INCLUDE_DIRS ../../../include)

cuda_add_library(culid
../../../src/modules/perception/lidar/lib/detector/point_pillars_detection/preprocess_points_cuda.cu
../../../src/modules/perception/lidar/lib/detector/point_pillars_detection/anchor_mask_cuda.cu
../../../src/modules/perception/lidar/lib/detector/point_pillars_detection/scatter_cuda.cu
../../../src/modules/perception/lidar/lib/detector/point_pillars_detection/postprocess_cuda.cu
../../../src/modules/perception/lidar/lib/detector/point_pillars_detection/nms_cuda.cu
../../../src/modules/perception/lidar/lib/detector/point_pillars_detection/pfe_cuda.cu
)

add_executable(
detection_component
../../../src/main/detection.cpp
../../../src/component/detection.cpp
../../../src/modules/perception/common/sensor_manager/sensor_manager.cpp
../../../src/modules/perception/lidar/app/lidar_obstacle_detection.cpp
../../../src/modules/perception/onboard/transform_wrapper/transform_wrapper.cpp
../../../src/modules/transform/buffer.cpp
../../../src/modules/perception/lidar/lib/detector/point_pillars_detection/point_pillars.cpp
../../../src/modules/perception/common/io/io_util.cpp
../../../src/modules/perception/common/perception_gflags.cpp
../../../src/modules/perception/onboard/common_flags/common_flags.cpp
../../../src/modules/perception/lib/config_manager/config_manager.cpp
../../../src/modules/perception/lidar/lib/pointcloud_preprocessor/pointcloud_preprocessor.cpp
../../../src/modules/perception/lidar/lib/detector/point_pillars_detection/point_pillars_detection.cpp
../../../src/modules/perception/lidar/lib/detector/point_pillars_detection/preprocess_points.cpp
#../../../src/modules/perception/lidar/lib/detector/mask_pillars_detection/mask_pillars_detection.cpp

../../../src/modules/perception/lib/registerer/registerer.cpp

#../../../src/modules/perception/lidar/tools/offline_lidar_obstacle_perception.cpp

)

target_compile_definitions(detection_component PRIVATE USE_GPU)

target_include_directories(detection_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/aarch64-linux/include
    /usr/local/cuda/targets/x86_64-linux/include)

ament_target_dependencies(
  detection_component
  rclcpp
  apollo_msgs
  tf2_ros)

#target_link_libraries(detection_component common culid perception_base perception_internal Eigen3::Eigen ${OpenCV_LIBRARIES} ${CUDA_LIBRARIES}  ${CUDA_CUBLAS_LIBRARIES} Boost::thread "${TORCH_LIBRARIES}" ${PCL_LIBRARIES} nvinfer nvonnxparser fftw3 yaml-cpp absl::base absl::synchronization absl::strings)
target_link_libraries(detection_component common culid perception_base perception_internal "${TORCH_LIBRARIES}" ${PCL_LIBRARIES} nvinfer nvonnxparser)

install(TARGETS
  detection_component
  DESTINATION lib/${PROJECT_NAME})
