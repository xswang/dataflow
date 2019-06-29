/*
 * blob_matrix.h
 * Copyright (C) 2019 XiaoshuWang <2012wxs@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef BLOB_MATRIX_H
#define BLOB_MATRIX_H

#include "eigen/include/eigen/Core"

namespace dataflow {
class BlobMatrix {
 public:
  Eigen::MatrixXf& data() {
    return _data;
  }
  Eigen::MatrixXf& gradient() {
    return _gradient;
  }
  bool& need_gradient() {
    return _need_gradient;
  }
  bool& has_gradient() {
    return _has_gradient;
  }
 private:
  bool _need_gradient = false;
  bool _has_gradient = false;
  Eigen::MatrixXf _data, _gradient;
};

}
#endif /* !BLOB_MATRIX_H */
