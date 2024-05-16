cmake_minimum_required(VERSION 3.5)
project(apollo)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH};/opt/libtorch)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(apollo_msgs REQUIRED)
find_package(OpenCV REQUIRED)


if(OPENMP_FOUND)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

add_executable(
third_party_perception_component
../../src/main/third_party_perception.cpp
../../src/component/third_party_perception.cpp
../../src/modules/third_party_perception/third_party_perception_base.cpp
../../src/modules/third_party_perception/third_party_perception_mobileye.cpp
../../src/modules/third_party_perception/common/third_party_perception_gflags.cpp
../../src/modules/third_party_perception/common/third_party_perception_util.cpp
../../src/modules/third_party_perception/tools/conversion_mobileye.cpp
../../src/modules/third_party_perception/tools/conversion_radar.cpp
../../src/modules/third_party_perception/tools/filter.cpp
../../src/modules/third_party_perception/tools/fusion.cpp
)
target_include_directories(third_party_perception_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/x86_64-linux/include)
target_compile_definitions(third_party_perception_component PRIVATE USE_GPU)
ament_target_dependencies(
  third_party_perception_component
  rclcpp
  std_msgs
  apollo_msgs)
target_link_libraries(third_party_perception_component common hdmap)

install(TARGETS
  third_party_perception_component
  DESTINATION lib/${PROJECT_NAME})
