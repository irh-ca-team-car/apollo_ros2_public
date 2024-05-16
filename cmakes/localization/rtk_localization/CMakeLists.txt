cmake_minimum_required(VERSION 3.5)
project(apollo)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH};/opt/libtorch)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(apollo_msgs REQUIRED)
find_package(tf2_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

if(OPENMP_FOUND)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

add_executable(
rtk_localization_component
../../../src/component/rtk_localization.cpp
../../../src/main/rtk_localization.cpp
../../../src/modules/localization/rtk/rtk_localization.cpp
../../../src/modules/transform/transform_broadcaster.cpp
)

target_include_directories(rtk_localization_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/x86_64-linux/include)

ament_target_dependencies(
  rtk_localization_component
  rclcpp
  apollo_msgs  tf2_msgs geometry_msgs)
target_link_libraries(rtk_localization_component common  )
target_compile_definitions(rtk_localization_component PRIVATE USE_GPU)
install(TARGETS
  rtk_localization_component
  DESTINATION lib/${PROJECT_NAME})
