/*
 * pooling.h
 * Copyright (C) 2017 XiaoshuWang <2012wxs@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef POOLING_H
#define POOLING_H

#include <string>
#include "core/ops/operator.h"

namespace dataflow{
class Pooling : public Operator{
 public:
  Pooling() {};
  ~Pooling() {};

  std::string get_op_name() {return "pooling";}
};

}
#endif /* !POOLING_H */
