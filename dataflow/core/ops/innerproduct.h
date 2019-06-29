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

namespace dataflow{
class Innerproduct : public Operator {
 public:
  Innerproduct() {}
  ~Innerproduct() {}
  std::string get_op_name() {return "Innerproduct";}
  void initialize(Node* node) {
    std::cout << "initialize " << node->name_ << std::endl;
  }

 private:
  Node* _node;
};

}

#endif /* !INNERPRODUCT_H*/
