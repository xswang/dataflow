include (ExternalProject)

set(ZEROMQ_INCLUDE_DIR ${THIRD_PARTY_DIR}/zeromq/include)
set(ZEROMQ_LIBRARY_DIR ${THIRD_PARTY_DIR}/zeromq/lib)

set(zeromq_HEADERS_DIR ${CMAKE_CURRENT_BINARY_DIR}/zeromq/src/zeromq/include)
set(zeromq_LIB_DIR ${CMAKE_CURRENT_BINARY_DIR}/zeromq/src/zeromq/lib)
set(zeromq_URL https://github.com/zeromq/libzmq.git)
set(zeromq_TAG d062edd8c142384792955796329baf1e5a3377cd)

set(ZEROMQ_BUILD_LIBRARY_DIR ${zeromq_LIB_DIR})
set(ZEROMQ_LIBRARY_NAMES libzmq.a)

foreach(LIBRARY_NAME ${ZEROMQ_LIBRARY_NAMES})
  list(APPEND ZEROMQ_STATIC_LIBRARIES ${ZEROMQ_LIBRARY_DIR}/${LIBRARY_NAME})
  list(APPEND ZEROMQ_BUILD_STATIC_LIBRARIES ${ZEROMQ_BUILD_LIBRARY_DIR}/${LIBRARY_NAME})
endforeach()

ExternalProject_Add(zeromq
    PREFIX zeromq
    GIT_REPOSITORY ${zeromq_URL}
    GIT_TAG ${zeromq_TAG}
    BUILD_IN_SOURCE 1
    INSTALL_COMMAND ""
    CMAKE_CACHE_ARGS
        -DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}
        -DCMAKE_CXX_FLAGS_DEBUG:STRING=${CMAKE_CXX_FLAGS_DEBUG}
        -DCMAKE_CXX_FLAGS_RELEASE:STRING=${CMAKE_CXX_FLAGS_RELEASE}
)

add_custom_target(zeromq_create_header_dir
  COMMAND ${CMAKE_COMMAND} -E make_directory ${ZEROMQ_INCLUDE_DIR}
  DEPENDS zeromq)

add_custom_target(zeromq_copy_headers_to_destination
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${zeromq_HEADERS_DIR} ${ZEROMQ_INCLUDE_DIR}
    DEPENDS zeromq_create_header_dir)

add_custom_target(zeromq_create_library_dir
  COMMAND ${CMAKE_COMMAND} -E make_directory ${ZEROMQ_LIBRARY_DIR}
  DEPENDS zeromq)

add_custom_target(zeromq_copy_libs_to_destination
  COMMAND ${CMAKE_COMMAND} -E copy_if_different ${ZEROMQ_BUILD_STATIC_LIBRARIES} ${ZEROMQ_LIBRARY_DIR}
  DEPENDS zeromq_create_library_dir)
