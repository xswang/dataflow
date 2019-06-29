/*
 * udf_graph.h
 * Copyright (C) 2017 wangxiaoshu <2012wxs@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef UDF_GRAPH_H
#define UDF_GRAPH_H


#include "core/graph/graph.h"
#include "core/proto/dataflow.pb.h"

namespace dataflow {

class UdfGraph : public Graph {
 public:
  UdfGraph(dataflow::GraphDef& graph_def);
  ~UdfGraph();

  void GraphBuilder();
  void BuildNode(const NodeDef node_def);
  Node* AddNode(const std::string& name);
  Edge* AddEdge(Node* src, Node* dst);

 public:
  GraphDef graph_def_;
  std::set<Node*> nodes_;
  std::set<Edge*> edges_;
};

}

#endif /* !UDF_GRAPH_H */
