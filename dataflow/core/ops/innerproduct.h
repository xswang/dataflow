/*
 * innerproduct.h
 * Copyright (C) 2019 XiaoshuWang <2012wxs@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef INNERPRODUCT_H
#define INNERPRODUCT_H 
#include <string>

#include "core/ops/operator.h"
#include "core/ops/matrix_blob.h"

namespace dataflow{
class Innerproduct : public Operator {
 public:
  Innerproduct() {}
  ~Innerproduct() {}
  std::string get_op_name() {return "Innerproduct";}
  void initialize(Node* node) {
    std::cout << node->name_ << std::endl;
    size_t index = 0;
    input_name_ = "";
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
  void forward() {
    if (input_name_ != "") {
      auto input_x =
        dynamic_cast<dataflow::MatrixBlob*>(dataflow::CREATE_MATRIX_BLOB(input_name_));
    }
  }

 private:
  Node* _node;
  std::string input_name_;
  std::string output_name_;
};

}

#endif /* !INNERPRODUCT_H*/
