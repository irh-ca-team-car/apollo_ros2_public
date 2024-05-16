cmake_minimum_required(VERSION 3.5)
project(apollo)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

set(CMAKE_PREFIX_PATH /opt/libtorch;${CMAKE_PREFIX_PATH})

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  #add_compile_options(-Wall -Wextra -Wpedantic)
  add_compile_options(-Wall -Wextra)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(apollo_msgs REQUIRED)
find_package(CUDA REQUIRED)
find_package(PCL REQUIRED)
find_package(OpenMP REQUIRED)
find_package(Torch REQUIRED)
find_package(tf2_ros REQUIRED)

cuda_add_library(perception_seg_feature_generator
../../../src/modules/perception/lidar/lib/detector/cnn_segmentation/feature_generator.cu
)
target_compile_definitions(perception_seg_feature_generator PRIVATE NVVC)
target_compile_definitions(perception_seg_feature_generator PRIVATE USE_GPU)
target_compile_definitions(perception_seg_feature_generator PRIVATE USE_CUDA)

add_executable(
segmentation_component
../../../src/main/segmentation.cpp
../../../src/component/segmentation.cpp
../../../src/modules/perception/common/sensor_manager/sensor_manager.cpp
../../../src/modules/perception/common/perception_gflags.cpp
../../../src/modules/perception/onboard/common_flags/common_flags.cpp
../../../src/modules/perception/lidar/app/lidar_obstacle_segmentation.cpp
../../../src/modules/perception/onboard/transform_wrapper/transform_wrapper.cpp
../../../src/modules/transform/buffer.cpp
../../../src/modules/perception/common/io/io_util.cpp
../../../src/modules/perception/lib/config_manager/config_manager.cpp
../../../src/modules/perception/lidar/lib/scene_manager/scene_manager.cpp
../../../src/modules/perception/lidar/lib/map_manager/map_manager.cpp
../../../src/modules/perception/lidar/lib/pointcloud_preprocessor/pointcloud_preprocessor.cpp
../../../src/modules/perception/lidar/lib/object_filter_bank/object_filter_bank.cpp
../../../src/modules/perception/lidar/lib/object_builder/object_builder.cpp
../../../src/modules/perception/lib/registerer/registerer.cpp
../../../src/modules/perception/lidar/lib/detector/ncut_segmentation/common/flood_fill.cpp
../../../src/modules/perception/lidar/lib/detector/ncut_segmentation/ncut.cpp
../../../src/modules/perception/lidar/lib/detector/ncut_segmentation/ncut_segmentation.cpp
../../../src/modules/perception/lidar/lib/ground_detector/ground_service_detector/ground_service_detector.cpp
../../../src/modules/perception/lidar/lib/roi_filter/roi_service_filter/roi_service_filter.cpp
../../../src/modules/perception/lib/thread/thread_worker.cpp
../../../src/modules/perception/lidar/lib/object_filter_bank/roi_boundary_filter/roi_boundary_filter.cpp
../../../src/modules/perception/lidar/lib/scene_manager/ground_service/ground_service.cpp
../../../src/modules/perception/lidar/lib/scene_manager/roi_service/roi_service.cpp
../../../src/modules/perception/lidar/lib/roi_filter/hdmap_roi_filter/hdmap_roi_filter.cpp
../../../src/modules/perception/lidar/lib/roi_filter/hdmap_roi_filter/bitmap2d.cpp
../../../src/modules/perception/lidar/lib/detector/cnn_segmentation/cnn_segmentation.cpp
../../../src/modules/perception/lidar/lib/detector/cnn_segmentation/feature_generator.cpp
../../../src/modules/perception/lidar/common/cloud_mask.cpp
../../../src/modules/perception/lidar/lib/detector/cnn_segmentation/spp_engine/spp_label_image.cpp
../../../src/modules/perception/lidar/lib/detector/cnn_segmentation/spp_engine/spp_pool_types.cpp
../../../src/modules/perception/lidar/lib/detector/cnn_segmentation/spp_engine/spp_struct.cpp
../../../src/modules/perception/lidar/lib/detector/cnn_segmentation/spp_engine/spp_seg_cc_2d.cpp
../../../src/modules/perception/lidar/lib/detector/cnn_segmentation/spp_engine/spp_cluster_list.cpp
../../../src/modules/perception/lidar/lib/detector/cnn_segmentation/spp_engine/spp_engine.cpp
../../../src/modules/perception/common/i_lib/pc/i_ground.cpp
../../../src/modules/perception/lidar/lib/ground_detector/spatio_temporal_ground_detector/spatio_temporal_ground_detector.cpp

)
target_compile_definitions(perception_seg_feature_generator PRIVATE USE_GPU)
target_include_directories(perception_seg_feature_generator
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/aarch64-linux/include
    /usr/local/cuda/targets/x86_64-linux/include)
target_include_directories(segmentation_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/aarch64-linux/include
    /usr/local/cuda/targets/x86_64-linux/include)

ament_target_dependencies(
  segmentation_component
  rclcpp
  apollo_msgs tf2_ros)
list(REMOVE_ITEM CUDA_npp_LIBRARY CUDA_nppicom_LIBRARY-NOTFOUND)
target_link_libraries(perception_seg_feature_generator absl::base absl::synchronization absl::strings Eigen3::Eigen)

target_link_libraries(segmentation_component perception_seg_feature_generator perception_inference perception_inference_cuda perception_base common hdmap perception_base perception_internal ${CUDA_LIBRARIES} ${CUDA_CUBLAS_LIBRARIES} ${CUDA_npp_LIBRARY} ${PCL_LIBRARIES} OpenMP::OpenMP_CXX)

target_compile_definitions(segmentation_component PRIVATE USE_GPU)
install(TARGETS
  segmentation_component
  DESTINATION lib/${PROJECT_NAME})
