/*
 * proto_parse.h
 * Copyright (C) 2017 XiaoshuWang <2012wxs@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef PROTO_PARSE_H
#define PROTO_PARSE_H

#include "google/protobuf/message.h"
#include <fcntl.h> 
#include <unistd.h>

#include <google/protobuf/descriptor.h>
#include <google/protobuf/descriptor.pb.h>
#include <google/protobuf/dynamic_message.h>

#include <google/protobuf/io/coded_stream.h>  
#include <google/protobuf/io/zero_copy_stream_impl.h>  
#include <google/protobuf/text_format.h> 

namespace dataflow{

using google::protobuf::io::FileInputStream;  
using google::protobuf::io::FileOutputStream;  
using google::protobuf::io::ZeroCopyInputStream;  
using google::protobuf::io::CodedInputStream;  
using google::protobuf::io::ZeroCopyOutputStream;  
using google::protobuf::io::CodedOutputStream;  
using google::protobuf::Message;  

using namespace google::protobuf;
using namespace google::protobuf::io;

class PbParse{
 public:
  PbParse() {}
  ~PbParse() {}

  Message* CreateMessage(const std::string& type_name);
  bool ReadProtoFromTextFile(const char* filename,
                             Message* proto);

};


}

#endif /* !PROTO_PARSE_H */
