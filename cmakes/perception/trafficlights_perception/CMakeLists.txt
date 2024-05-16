cmake_minimum_required(VERSION 3.5)
project(apollo)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH};/opt/libtorch)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(apollo_msgs REQUIRED)
find_package(CUDA REQUIRED)
find_package(Torch REQUIRED)

set(CUDA_INCLUDE_DIRS ../../../include)

cuda_add_library(trafficlights_perception_component_cuda ../../../src/modules/perception/inference/utils/resize.cu)

add_executable(
trafficlights_perception_component
#../../../src/main/trafficlights_perception.cpp
#../../../src/component/trafficlights_perception.cpp
#../../../src/modules/perception/camera/app/traffic_light_camera_perception.cpp
../../../src/modules/perception/camera/common/data_provider.cpp
#../../../src/modules/perception/camera/common/undistortion_handler.cpp
#../../../src/modules/perception/camera/common/util.cpp
#../../../src/modules/perception/camera/lib/traffic_light/detector/detection/cropbox.cpp
#../../../src/modules/perception/camera/lib/traffic_light/detector/detection/detection.cpp
#../../../src/modules/perception/camera/lib/traffic_light/detector/detection/select.cpp
#../../../src/modules/perception/camera/lib/traffic_light/detector/recognition/classify.cpp
#../../../src/modules/perception/camera/lib/traffic_light/detector/recognition/recognition.cpp
#../../../src/modules/perception/camera/lib/traffic_light/preprocessor/multi_camera_projection.cpp
#../../../src/modules/perception/camera/lib/traffic_light/preprocessor/pose.cpp
#../../../src/modules/perception/camera/lib/traffic_light/preprocessor/tl_preprocessor.cpp
#../../../src/modules/perception/camera/lib/traffic_light/tracker/semantic_decision.cpp
#../../../src/modules/perception/common/io/io_util.cpp
#../../../src/modules/perception/common/perception_gflags.cpp
#../../../src/modules/perception/common/sensor_manager/sensor_manager.cpp
#../../../src/modules/perception/inference/inference.cpp
#../../../src/modules/perception/inference/inference_factory.cpp
#../../../src/modules/perception/inference/libtorch/torch_det.cpp
#../../../src/modules/perception/inference/libtorch/torch_net.cpp
#../../../src/modules/perception/inference/utils/util.cpp
#../../../src/modules/perception/lib/config_manager/config_manager.cpp
#../../../src/modules/perception/lib/registerer/registerer.cpp
#../../../src/modules/perception/onboard/common_flags/common_flags.cpp
#../../../src/modules/perception/onboard/transform_wrapper/transform_wrapper.cpp
../../../src/modules/transform/buffer.cpp
#../../../src/modules/v2x/common/v2x_proxy_gflags.cpp
)
list(REMOVE_ITEM CUDA_npp_LIBRARY CUDA_nppicom_LIBRARY-NOTFOUND)

target_include_directories(trafficlights_perception_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/aarch64-linux/include
    /usr/local/cuda/targets/x86_64-linux/include)
target_compile_definitions(segmentation_component PRIVATE USE_GPU)
ament_target_dependencies(
  trafficlights_perception_component
  rclcpp
  apollo_msgs)
target_link_libraries(trafficlights_perception_component_cuda absl::base absl::synchronization absl::strings  )

target_link_libraries(trafficlights_perception_component common hdmap perception_base trafficlights_perception_component_cuda "${TORCH_LIBRARIES}" ${CUDA_LIBRARIES} ${CUDA_npp_LIBRARY} ${CUDA_CUBLAS_LIBRARIES} )

install(TARGETS
  trafficlights_perception_component
  DESTINATION lib/${PROJECT_NAME})
