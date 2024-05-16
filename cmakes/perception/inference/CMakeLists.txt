cmake_minimum_required(VERSION 3.5)
project(apollo)

EXECUTE_PROCESS( COMMAND uname -m COMMAND tr -d '\n' OUTPUT_VARIABLE ARCHITECTURE )

if( ${ARCHITECTURE} STREQUAL "aarch64" )

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH};/opt/libtorch)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(apollo_msgs REQUIRED)
find_package(Torch REQUIRED)
find_package(CUDA REQUIRED)
message("CUDA STRING:[${CUDA_NVCC_FLAGS}]")
cuda_add_library(perception_inference_cuda
../../../src/modules/perception/inference/operators/roipooling_layer.cu
../../../src/modules/perception/inference/utils/gemm.cu
../../../src/modules/perception/inference/utils/util.cu
../../../src/modules/perception/inference/utils/resize.cu
../../../src/modules/perception/inference/utils/cuda_util.cu
../../../src/modules/perception/inference/tensorrt/plugins/slice_plugin.cu
../../../src/modules/perception/inference/tensorrt/plugins/rpn_proposal_ssd_plugin.cu
../../../src/modules/perception/inference/tensorrt/plugins/rcnn_proposal_plugin.cu
../../../src/modules/perception/inference/tensorrt/plugins/nms_cuda.cu
../../../src/modules/perception/inference/tensorrt/plugins/leakyReLU_plugin.cu
../../../src/modules/perception/inference/tensorrt/plugins/argmax_plugin.cu
../../../src/modules/perception/inference/tensorrt/plugins/kernels.cu
../../../src/modules/perception/inference/tensorrt/plugins/softmax_plugin.cu
../../../src/modules/perception/inference/tensorrt/plugins/dfmb_psroi_align_plugin.cu
)


file(GLOB_RECURSE SRC_PERCEPTION_INFERENCE "../../../src/modules/perception/inference/*.cpp")

add_library(
perception_inference
../../../src/modules/perception/inference/inference.cpp
${SRC_PERCEPTION_INFERENCE}
)

target_compile_definitions(perception_inference PRIVATE USE_GPU)
target_compile_definitions(perception_inference_cuda PRIVATE NVVC)
target_compile_definitions(perception_inference_cuda PRIVATE USE_GPU)
target_compile_definitions(perception_inference_cuda PRIVATE USE_CUDA)


target_include_directories(perception_inference_cuda
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/aarch64-linux/include
    /usr/local/cuda/targets/x86_64-linux/include)

target_include_directories(perception_inference
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/aarch64-linux/include
    /usr/local/cuda/targets/x86_64-linux/include)
    
ament_target_dependencies(
  perception_inference
  rclcpp
  apollo_msgs)
list(REMOVE_ITEM CUDA_npp_LIBRARY CUDA_nppicom_LIBRARY-NOTFOUND)
target_link_libraries(perception_inference_cuda absl::base absl::synchronization absl::strings Eigen3::Eigen ${CUDA_CUBLAS_LIBRARIES} libnvinfer.so)
list(REMOVE_ITEM TORCH_LIBRARIES kineto_LIBRARY-NOTFOUND)
target_link_libraries(perception_inference common cutil perception_base ${TORCH_LIBRARIES} ${CUDA_LIBRARIES}  ${CUDA_CUBLAS_LIBRARIES} ${CUDA_npp_LIBRARY} ${TORCH_LIBRARIES} perception_inference_cuda)

endif()