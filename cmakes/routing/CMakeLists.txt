cmake_minimum_required(VERSION 3.5)
project(apollo)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(apollo_msgs REQUIRED)

add_executable(
routing_component
../../src/main/routing.cpp
../../src/component/routing.cpp
../../src/modules/routing/routing.cpp
../../src/modules/routing/common/routing_gflags.cpp
../../src/modules/routing/graph/node_with_range.cpp
../../src/modules/routing/graph/sub_topo_graph.cpp
../../src/modules/routing/graph/topo_graph.cpp
../../src/modules/routing/graph/topo_node.cpp
../../src/modules/routing/graph/topo_range_manager.cpp
../../src/modules/routing/graph/topo_range.cpp
../../src/modules/routing/core/black_list_range_generator.cpp
../../src/modules/routing/core/navigator.cpp
../../src/modules/routing/core/result_generator.cpp
../../src/modules/routing/strategy/a_star_strategy.cpp

)

target_link_libraries(
  routing_component
  common hdmap)
ament_target_dependencies(routing_component apollo_msgs rclcpp)

target_include_directories(routing_component
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
    $<INSTALL_INTERFACE:include>
    /usr/local/cuda/targets/x86_64-linux/include)

install(TARGETS
  routing_component
  DESTINATION lib/${PROJECT_NAME})