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
    std::cout << "initialize " << node->name_ << std::endl;
    for (int i = 0; i < node->input_x_.size(); ++i) {
      input_name_ = node->input_x_[i];
      std::cout << "input_name = " << input_name_ << std::endl;
    }
  }
  void forward() {
    // auto input_x =
    //   dynamic_cast<dataflow::MatrixBlob*>(dataflow::CREATE_MATRIX_BLOB(input_name_));
    // auto a = registry[input_name_];
  }

 private:
  Node* _node;
  std::string input_name_;
};

}

#endif /* !INNERPRODUCT_H*/
