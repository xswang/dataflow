set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/test/proto)
file(GLOB_RECURSE dataflow_src ${PROJECT_SOURCE_DIR}/dataflow/*.*)
foreach(src_file ${dataflow_src})
  if("${src_file}" MATCHES "^${dataflow_src_dir}/.*\\.proto")
    list(APPEND dataflow_pbfiles ${src_file})
  endif()
endforeach()

foreach(pb_file ${dataflow_pbfiles})
  file(RELATIVE_PATH pb_relative_path_file ${PROJECT_SOURCE_DIR} ${pb_file})
  list(APPEND dataflow_rel_pbfiles ${pb_relative_path_file})
endforeach()

RELATIVE_PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS
  ${PROJECT_SOURCE_DIR}
  ${dataflow_rel_pbfiles})
add_library(dataflow_proto ${PROTO_SRCS} ${PROTO_HDRS})
add_dependencies(dataflow_proto ${dataflow_third_party_dependencies})

