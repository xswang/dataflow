/*
 * sigmoid.h
 * Copyright (C) 2019 XiaoshuWang <2012wxs@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef SIGMOID_H
#define SIGMOID_H
#include <string>
#include <memory>

#include "core/ops/operator.h"
#include "core/ops/matrix_blob.h"

namespace dataflow{
class Sigmoid : public Operator {
 public:
  Sigmoid() {}
  ~Sigmoid() {}
  std::string get_op_name() {return "Sigmoid";}
  void initialize(Node* node) {
    std::cout << node->name_ << std::endl;
    for (int i = 0; i < node->input_x_.size(); ++i) {
      input_name_ = node->input_x_[i];
      std::cout << "input: " << input_name_ << std::endl;
    }
    for (int i = 0; i < node->output_.size(); ++i) {
      output_name_ = node->output_[i];
      std::cout << "output: " << output_name_ << std::endl;
    }
    std::cout << "==================================" << std::endl;
  }

  void forward() override {
    if (input_name_ != "") {
      input_ = CREATE_MATRIX_BLOB(input_name_);
    }
    if (output_name_ != "") {
      output_ = CREATE_MATRIX_BLOB(output_name_);
    }
    X_ = input_->value();
    Y_ = output_->value();
    Y_.resizeLike(X_);
    if (input_->need_bp_gradient()) {
      for (size_t i = 0; i < X_.size(); ++i) {
         Y_.data()[i] = 1.0 / (1.0 + std::exp(X_.data()[i]));
      }
    }
    output_->has_bp_gradient() = false;
    output_->need_bp_gradient() = input_->need_bp_gradient();
  }
  void backward() override {
    if (input_->need_bp_gradient() && output_->has_bp_gradient()) {
      dX_ = input_->gradient();
      dY_ = output_->gradient();
      if (input_->has_bp_gradient()) {
        for (size_t i = 0; i < dX_.size(); ++i) {
          dX_.data()[i] += dY_.data()[i] * ((1.0 - Y_.data()[i]) * Y_.data()[i]);
        }
      } else {
        for (size_t i = 0; i < dX_.size(); ++i) {
          dX_.data()[i] = dY_.data()[i] * ((1.0 - Y_.data()[i]) * Y_.data()[i]);
        }
      }
      input_->has_bp_gradient() = true;
    }
  }
 private:
  Node* node_;
  std::string input_name_;
  std::string output_name_;
  std::shared_ptr<MatrixBlob> input_;
  std::shared_ptr<MatrixBlob> output_;
  Eigen::MatrixXf X_;
  Eigen::MatrixXf dX_;
  Eigen::MatrixXf Y_;
  Eigen::MatrixXf dY_;
};

}

#endif /* !SIGMOID_H */
