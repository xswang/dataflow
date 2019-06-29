set(THIRD_PARTY_DIR "${CMAKE_BINARY_DIR}/third_party"
  CACHE PATH "Location where third party headers and libs will be put.")
mark_as_advanced(THIRD_PARTY_DIR)

message(${THIRD_PARTY_DIR})


include(zlib)
include(protobuf)
include(googletest)
include(glog)
include(gflags)
include(grpc)
include(zeromq)
include(eigen)

set(dataflow_third_party_libs
    ${ZLIB_STATIC_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
    ${GLOG_STATIC_LIBRARIES}
    ${GFLAGS_STATIC_LIBRARIES}
    ${GOOGLETEST_STATIC_LIBRARIES}
    ${PROTOBUF_STATIC_LIBRARIES}
    ${GRPC_STATIC_LIBRARIES}
    ${ZEROMQ_STATIC_LIBRARIES}
)

set(dataflow_third_party_dependencies
  zlib_copy_headers_to_destination
  zlib_copy_libs_to_destination
  gflags_copy_headers_to_destination
  gflags_copy_libs_to_destination
  glog_copy_headers_to_destination
  glog_copy_libs_to_destination
  googletest_copy_headers_to_destination
  googletest_copy_libs_to_destination
  protobuf_copy_headers_to_destination
  protobuf_copy_libs_to_destination
  protobuf_copy_binary_to_destination
  grpc_copy_headers_to_destination
  grpc_copy_libs_to_destination
  grpc_copy_binary_to_destination
  zeromq_copy_headers_to_destination
  zeromq_copy_libs_to_destination
  eigen_copy_headers_to_destination
)

include_directories(
    ${ZLIB_INCLUDE_DIR}
    ${GFLAGS_INCLUDE_DIR}
    ${GLOG_INCLUDE_DIR}
    ${GOOGLETEST_INCLUDE_DIR}
    ${PROTOBUF_INCLUDE_DIR}
    ${GRPC_INCLUDE_DIR}
    ${ZEROMQ_INCLUDE_DIR}
    ${EIGEN_INCLUDE_DIR}
)
