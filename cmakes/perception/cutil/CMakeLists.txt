cmake_minimum_required(VERSION 3.5)
project(apollo)

find_package(CUDA REQUIRED)
find_package(Boost REQUIRED COMPONENTS thread)

set(CUDA_INCLUDE_DIRS ../../../include)

cuda_add_library(cutil ../../../src/modules/perception/inference/utils/cuda_util.cu)

target_link_libraries(cutil Boost::thread  )