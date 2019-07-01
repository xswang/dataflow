/*
 * blob_matrix.h
 * Copyright (C) 2019 XiaoshuWang <2012wxs@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef MATRIX_BLOB_H
#define MATRIX_BLOB_H

#include "eigen/include/eigen/Core"
#include "core/base/op_register.h"
#include "core/graph/graph.h"

namespace dataflow {

class MatrixBlob {
 public:
  MatrixBlob() {}
  virtual ~MatrixBlob() = default;

  // void initialize(Node* node) {}
  virtual Eigen::MatrixXf& value() {
    return value_;
  }
  virtual Eigen::MatrixXf& gradient() {
    return gradient_;
  }
  virtual bool& need_bp_gradient() {
    return need_bp_gradient_;
  }
  virtual bool& has_bp_gradient() {
    return has_bp_gradient_;
  }

  bool need_bp_gradient_ = false;
  bool has_bp_gradient_ = false;
  Eigen::MatrixXf value_, gradient_;
};

CLASS_REGISTER_DEFINE_REGISTRY(dataflow_matrixblob_registry, MatrixBlob);

#define REGISTER_MATRIX_BLOB(format_name, op_name)             \
   CLASS_REGISTER_OBJECT_CREATOR(                              \
     dataflow_matrixblob_registry,                             \
     MatrixBlob,                                               \
     format_name,                                              \
     op_name)

#define CREATE_MATRIX_BLOB(format_name)                        \
   MATRIX_BLOB_REGISTER_CREATE_OBJECT(                         \
     dataflow_matrixblob_registry,                             \
     format_name)

}

#endif /* !MATRIX_BLOB_H */
