/*
 * operator.cc
 * Copyright (C) 2017 XiaoshuWang <2012wxs@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include "core/ops/operator.h"
#include "core/ops/conv.h"
#include "core/ops/pooling.h"
#include "core/ops/lstm.h"

namespace dataflow{
CLASS_REGISTER_IMPLEMENT_REGISTRY(dataflow_op_registry, Operator);
REGISTER_OP("conv", Conv);
REGISTER_OP("pooling", Pooling);
REGISTER_OP("lstm", Lstm);
}

