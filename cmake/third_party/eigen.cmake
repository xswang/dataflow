include (ExternalProject)

set(EIGEN_INCLUDE_DIR ${THIRD_PARTY_DIR}/eigen/include)

set(eigen_URL https://github.com/eigenteam/eigen-git-mirror.git)
# set(eigen_URL https://github.com/artsy/eigen.git)
# set(eigen_TAG 11a3c93ee327dd2be34bc56bc04a5ebcb3340256)
set(eigen_TAG acb5144eea3f4986c5bf855d33a937864da62737)
set(eigen_HEADERS_DIR ${CMAKE_CURRENT_BINARY_DIR}/eigen/src/eigen/Eigen)

ExternalProject_Add(eigen
    PREFIX eigen
    GIT_REPOSITORY ${eigen_URL}
    GIT_TAG ${eigen_TAG}
    CMAKE_CACHE_ARGS
    -DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}
    -DBUILD_SHARED_LIBS:BOOL=OFF
    -DCMAKE_CXX_FLAGS:STRING=${CMAKE_CXX_FLAGS}
    -DCMAKE_CXX_FLAGS_DEBUG:STRING=${CMAKE_CXX_FLAGS_DEBUG}
    -DCMAKE_CXX_FLAGS_RELEASE:STRING=${CMAKE_CXX_FLAGS_RELEASE}
    -DBUILD_TESTING:BOOL=OFF
    -DWITH_GFLAGS:BOOL=OFF
    )


add_custom_target(eigen_create_header_dir
  COMMAND ${CMAKE_COMMAND} -E make_directory ${EIGEN_INCLUDE_DIR}/eigen
  DEPENDS eigen)

add_custom_target(eigen_copy_headers_to_destination
  DEPENDS eigen_create_header_dir)

add_custom_command(TARGET eigen_copy_headers_to_destination PRE_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${eigen_HEADERS_DIR} ${EIGEN_INCLUDE_DIR}/eigen)
