# Minimun CMake required
cmake_minimum_required (VERSION 3.5)

# projectname is the same as the main-executable
project(dataflow)

add_definitions("-std=c++11")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(dataflow_src_dir ${PROJECT_SOURCE_DIR}/dataflow)
set(dataflow_cmake_dir ${PROJECT_SOURCE_DIR}/cmake)
message("PROJECT_BINARY_DIR " ${PROJECT_BINARY_DIR})

list(APPEND CMAKE_MODULE_PATH ${dataflow_cmake_dir}/third_party)
list(APPEND CMAKE_MODULE_PATH ${dataflow_cmake_dir})
include(third_party)
include(proto2cpp)
include(proto2grpc)

include_directories(
  "${PROJECT_SOURCE_DIR}/dataflow/"
  "${PROJECT_BINARY_DIR}/"
  "${PROJECT_BINARY_DIR}/dataflow"
  "${PROJECT_BINARY_DIR}/third_party"
)

link_directories(
  "${PROJECT_BINARY_DIR}/dataflow/core/base"
  "${PROJECT_BINARY_DIR}/dataflow/core/ops"
  "${PROJECT_BINARY_DIR}/dataflow/core/graph"
  "${PROJECT_BINARY_DIR}/dataflow/core/proto"
)

add_subdirectory(dataflow/core/base)
add_subdirectory(dataflow/core/ops)
add_subdirectory(dataflow/core/graph)
add_subdirectory(dataflow/core/proto)

set(STA_DEPS graph base ops dataflow_proto pthread ${dataflow_third_party_libs})
add_executable(df ${dataflow_src_dir}/core/main.cc)
target_link_libraries(df ${STA_DEPS})
