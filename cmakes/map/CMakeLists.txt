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

file(GLOB_RECURSE SRC_MAP "../../src/modules/map/relative_map/*.cpp")


add_executable(
relative_map_component
../../src/main/relative_map.cpp
../../src/common/utils.cpp
../../src/modules/common/math/math_utils.cpp
../../src/modules/common/math/vec2d.cpp
../../src/modules/prediction/common/prediction_system_gflags.cpp
${SRC_MAP}
../../src/component/relative_map.cpp
)

target_include_directories(relative_map_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>)

ament_target_dependencies(
  relative_map_component
  rclcpp
  apollo_msgs)
target_link_libraries(relative_map_component common )

install(TARGETS
  relative_map_component
  DESTINATION lib/${PROJECT_NAME})
