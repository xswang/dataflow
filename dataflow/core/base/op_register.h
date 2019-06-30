//------------------------------------------------------------------------------
// Copyright (c) 2016 by contributors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//------------------------------------------------------------------------------

#ifndef DATAFLOW_BASE_OP_REGISTER_H_
#define DATAFLOW_BASE_OP_REGISTER_H_

#include <map>
#include <string>
#include "core/graph/graph.h"

#define CLASS_REGISTER_DEFINE_REGISTRY(register_name, base_class_name)       \
  class ObjectCreatorRegistry_##register_name {                              \
   public:                                                                   \
   typedef base_class_name* (*Creator)();                                    \
                                                                             \
   ObjectCreatorRegistry_##register_name()                                   \
   : m_default_creator(nullptr) {}                                           \
   ~ObjectCreatorRegistry_##register_name() {}                               \
                                                                             \
   void SetDefaultCreator(Creator creator) {                                 \
     m_default_creator = creator;                                            \
   }                                                                         \
                                                                             \
   void AddCreator(std::string entry_name, Creator creator) {                \
     m_creator_registry[entry_name] = creator;                               \
   }                                                                         \
                                                                             \
   base_class_name* CreateObject(dataflow::Node* node_name);             \
   base_class_name* CreateMatrixBlobObject(const std::string& entry_name);             \
                                                                             \
   private:                                                                  \
   typedef std::map<std::string, Creator> CreatorRegistry;                   \
   Creator m_default_creator;                                                \
   CreatorRegistry m_creator_registry;                                       \
  };                                                                         \
                                                                             \
  inline ObjectCreatorRegistry_##register_name&                              \
  GetRegistry_##register_name() {                                            \
    static ObjectCreatorRegistry_##register_name registry;                   \
    return registry;                                                         \
  }                                                                          \
                                                                             \
  class DefaultObjectCreatorRegister_##register_name {                       \
   public:                                                                   \
   DefaultObjectCreatorRegister_##register_name(                             \
       ObjectCreatorRegistry_##register_name::Creator creator) {             \
     GetRegistry_##register_name().SetDefaultCreator(creator);               \
   }                                                                         \
   ~DefaultObjectCreatorRegister_##register_name() {}                        \
  };                                                                         \
                                                                             \
  class ObjectCreatorRegister_##register_name {                              \
   public:                                                                   \
   ObjectCreatorRegister_##register_name(                                    \
       const std::string& entry_name,                                        \
       ObjectCreatorRegistry_##register_name::Creator creator) {             \
     GetRegistry_##register_name().AddCreator(entry_name,                    \
                                              creator);                      \
   }                                                                         \
   ~ObjectCreatorRegister_##register_name() {}                               \
  };

  #define CLASS_REGISTER_IMPLEMENT_REGISTRY(register_name, base_class_name)  \
  base_class_name* ObjectCreatorRegistry_##register_name::CreateObject(      \
      dataflow::Node* node_name) {                                       \
    Creator creator = m_default_creator;                                     \
    std::string entry_name = node_name->type_; \
    CreatorRegistry::const_iterator it =                                     \
        m_creator_registry.find(entry_name);                                 \
    if (it != m_creator_registry.end()) {                                    \
      creator = it->second;                                                  \
    }                                                                        \
                                                                             \
    if (creator != nullptr) {                                                \
      base_class_name* instance = (*creator)(); \
      instance->initialize(node_name); \
      return instance;                                  \
     } else {                                                                \
      return nullptr;                                                        \
    }                                                                        \
  }

  #define MATRIX_BLOB_REGISTER_IMPLEMENT_REGISTRY(register_name, base_class_name)  \
  base_class_name* ObjectCreatorRegistry_##register_name::CreateMatrixBlobObject(      \
    const std::string& entry_name) {                                       \
    Creator creator = m_default_creator;                                     \
    CreatorRegistry::const_iterator it =                                     \
        m_creator_registry.find(entry_name);                                 \
    if (it != m_creator_registry.end()) {                                    \
      creator = it->second;                                                  \
    }                                                                        \
                                                                             \
    if (creator != nullptr) {                                                \
      return (*creator)();                                                   \
     } else {                                                                \
      return nullptr;                                                        \
    }                                                                        \
  }


#define CLASS_REGISTER_DEFAULT_OBJECT_CREATOR(register_name,                 \
                                              base_class_name,               \
                                              class_name)                    \
  base_class_name* DefaultObjectCreator_##register_name##class_name() {      \
    return new class_name;                                                   \
  }                                                                          \
  DefaultObjectCreatorRegister_##register_name                               \
  g_default_object_creator_register_##register_name##class_name(             \
      DefaultObjectCreator_##register_name##class_name)

#define CLASS_REGISTER_OBJECT_CREATOR(register_name,                         \
                                      base_class_name,                       \
                                      entry_name_as_string,                  \
                                      class_name)                            \
  base_class_name* ObjectCreator_##register_name##class_name() {             \
    return new class_name;                                                   \
  }                                                                          \
  ObjectCreatorRegister_##register_name                                      \
  g_object_creator_register_##register_name##class_name(                     \
      entry_name_as_string,                                                  \
      ObjectCreator_##register_name##class_name)

#define CLASS_REGISTER_CREATE_OBJECT(register_name, entry_name_as_string)    \
  GetRegistry_##register_name().CreateObject(entry_name_as_string)

#define MATRIX_BLOB_REGISTER_CREATE_OBJECT(register_name, entry_name_as_string)    \
  GetRegistry_##register_name().CreateMatrixBlobObject(entry_name_as_string)

#endif  // DATAFLOW_BASE_OP_REGISTER_H_
