/*
 * proto_parse.cc
 * Copyright (C) 2017 XiaoshuWang <2012wxs@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include "core/graph/proto_parse.h"

namespace dataflow{

Message* PbParse::CreateMessage(const std::string& type_name) {
  Message* message = NULL;
  const Descriptor* descriptor =
    DescriptorPool::generated_pool()->FindMessageTypeByName(type_name);
  if (descriptor) {
    const Message* proto_type = 
      MessageFactory::generated_factory()->GetPrototype(descriptor);
    if (proto_type) {
      message = proto_type->New();
    }
  }
  return message;
}

bool PbParse::ReadProtoFromTextFile(const char* filename,
                                    Message* proto) {
  int fd = open(filename, O_RDONLY);
  FileInputStream* input = new FileInputStream(fd);
  bool success = google::protobuf::TextFormat::Parse(input, proto);
  delete input;
  close(fd);
  return success;
}

}



