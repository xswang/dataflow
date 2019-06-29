/*
 * conv.h
 * Copyright (C) 2017 XiaoshuWang <2012wxs@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef CONV_H
#define CONV_H
#include <string>

#include "core/ops/operator.h"

namespace dataflow{
class Conv : public Operator {
 public:
  Conv() {}
  ~Conv() {}
  std::string get_op_name() {return "Conv";}

  void initialize(Node* node) {
    std::cout << "initialize " << node->name_ << std::endl;
  }
};

}

#endif /* !CONV_H */
