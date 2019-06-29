/*
 * main.cc
 * Copyright (C) 2017 XiaoshuWang <2012wxs@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */
#include <iostream>
#include <fstream>
#include "core/ops/operator.h"
#include "core/ops/conv.h"
#include "core/proto/dataflow.pb.h"
#include "core/graph/proto_parse.h"
#include "core/graph/udf_graph.h"
#include "core/task/task.h"

#include "gflags/include/gflags/gflags.h"
#include "glog/include/glog/logging.h"

DEFINE_string(model_file, "/root/xiaoshu/opensource/pdl/dataflow/models/dnn.txt", "");

int main() {
  // dataflow::Conv* conv;
  // conv = dynamic_cast<dataflow::Conv*>(dataflow::CREATE_OP("conv"));
  // std::cout << conv->get_op_name() << std::endl;
  // LOG(INFO) << conv->get_op_name();
  dataflow::GraphDef graph_def;
  dataflow::PbParse* pb;
  bool res = pb->ReadProtoFromTextFile(FLAGS_model_file.c_str(), &graph_def);
  dataflow::UdfGraph udf_graph(graph_def);
  // std::cout<<"node num = "<<udf_graph.nodes_.size()<<std::endl;
  // std::cout<<"edge num = "<<udf_graph.edges_.size()<<std::endl;
  dataflow::Task<dataflow::UdfGraph> task(udf_graph);
  task.run();
  return 0;
}


