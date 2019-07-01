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
    size_t index = 0;
    for (int i = 0; i < node->input_x_.size(); ++i) {
      input_name_ = node->input_x_[i];
      index = input_name_.find("/", index);
      input_name_.replace(index, 1, "_");
      std::cout << "input: " << input_name_ << std::endl;
    }
    index = 0;
    for (int i = 0; i < node->output_.size(); ++i) {
      output_name_ = node->output_[i];
      index = output_name_.find("/", index);
      output_name_.replace(index, 1, "_");
      std::cout << "output: " << output_name_ << std::endl;
    }
    std::cout << "==================================" << std::endl;
  }
 private:
  Node* _node;
  std::string input_name_;
  std::string output_name_;
  std::shared_ptr<MatrixBlob> _input;
};

}

#endif /* !SIGMOID_H */
