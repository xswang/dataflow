/*
 * graphviz.h
 * Copyright (C) 2017 wangxiaoshu <2012wxs@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef GRAPHVIZ_H
#define GRAPHVIZ_H

#include "core/graph/graph.h"
#include "core/graph/graph_iter.h"

namespace dataflow {

template<typename Graph>
class GraphViz {
 public:
  GraphViz(Graph graph);
  ~GraphViz() {}

  inline void GraphToDotFileByEdges(std::string& dotfile) {
    std::fstream dotf;
    dotf.open(dotfile, std::fstream::out);
    dotf<<"digraph { "<<std::endl;
    dotf<<"node [shape=plaintext]"<<std::endl;

    for(Edge* e : graph_.edges_) {
      std::cout<<e->src_->name_<<":"<<e->src_->input_num_<<" -> "<<e->dst_->name_<<":"<<e->dst_->input_num_<<std::endl; 
      dotf<<e->src_->name_<<" -> "<<e->dst_->name_<<std::endl;
    } 
    dotf<<"} "<<std::endl;
    dotf.close();
  }

  inline void GraphToDotFileByNodes(std::string& dotfile) {
    std::cout<<"indegree:"<<std::endl;
    for(Node* n : graph_.nodes_) {
      std::cout<<n->name_<<":"<<n->input_num_<<std::endl;
    }

    GraphIter<Graph> graph_iter(graph_);
    for(graph_iter.First(); !graph_iter.End(); graph_iter.Next()){
      Node* n = graph_iter.current_;
      std::cout<<"node name: "<<n->id_<<std::endl; 
    }
  }

 private: 
  Graph graph_;
};

template<typename Graph>
GraphViz<Graph>::GraphViz(Graph graph) : graph_(graph) {}

}

#endif /* !GRAPHVIZ_H */
