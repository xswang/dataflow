/*
 * Reader.h
 * Copyright (C) 2019 XiaoshuWang <2012wxs@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef READER_H
#define READER_H
#include <string>

#include "core/ops/operator.h"
#include "core/ops/matrix_blob.h"

namespace dataflow{
class Reader : public Operator {
 public:
  Reader() {}
  ~Reader() {}
  std::string get_op_name() {return "Reader";}
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

  void forward() {
    if (input_name_ != "") {
      auto input_x = dataflow::CREATE_MATRIX_BLOB(input_name_);
    }
    auto output = dataflow::CREATE_MATRIX_BLOB(output_name_);

    std::cout << "use_count = " << output.use_count() << std::endl;

    if (output == nullptr) std::cout << "NULL" << std::endl;
    output->need_bp_gradient_ = true;
    std::cout << "need_bp_gradient = " << output->need_bp_gradient_ << std::endl;

    Eigen::MatrixXf matA(2, 2);
    Eigen::MatrixXf& out_val = output->value();
    out_val.resizeLike(matA);
    out_val << 1, 2, 3, 4;
  }

 private:
  Node* node_;
  std::string input_name_;
  std::string output_name_;
};

}

#endif /* !READER_H */
