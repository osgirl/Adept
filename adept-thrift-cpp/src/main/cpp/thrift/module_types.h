/*
* ------
* Adept
* -----
* Copyright (C) 2014 Raytheon BBN Technologies Corp.
* -----
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
* -------
*/

/*
* ------
* Adept
* -----
* Copyright (C) 2014 Raytheon BBN Technologies Corp.
* -----
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
* -------
*/

/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef module_TYPES_H
#define module_TYPES_H

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include "common_types.h"


namespace thrift { namespace adept { namespace module {

typedef struct _ModuleConfig__isset {
  _ModuleConfig__isset() : serialVersionUID(false), properties(false) {}
  bool serialVersionUID;
  bool properties;
} _ModuleConfig__isset;

class ModuleConfig {
 public:

  static const char* ascii_fingerprint; // = "EA43C2C5B2A5C5BBA3A4A188AE9B2302";
  static const uint8_t binary_fingerprint[16]; // = {0xEA,0x43,0xC2,0xC5,0xB2,0xA5,0xC5,0xBB,0xA3,0xA4,0xA1,0x88,0xAE,0x9B,0x23,0x02};

  ModuleConfig() : serialVersionUID(0) {
  }

  virtual ~ModuleConfig() throw() {}

  int64_t serialVersionUID;
  std::map<std::string, std::string>  properties;

  _ModuleConfig__isset __isset;

  void __set_serialVersionUID(const int64_t val) {
    serialVersionUID = val;
  }

  void __set_properties(const std::map<std::string, std::string> & val) {
    properties = val;
  }

  bool operator == (const ModuleConfig & rhs) const
  {
    if (!(serialVersionUID == rhs.serialVersionUID))
      return false;
    if (!(properties == rhs.properties))
      return false;
    return true;
  }
  bool operator != (const ModuleConfig &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ModuleConfig & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(ModuleConfig &a, ModuleConfig &b);

typedef struct _ModuleTraits__isset {
  _ModuleTraits__isset() : schema(false), trait(false), version(false) {}
  bool schema;
  bool trait;
  bool version;
} _ModuleTraits__isset;

class ModuleTraits {
 public:

  static const char* ascii_fingerprint; // = "AB879940BD15B6B25691265F7384B271";
  static const uint8_t binary_fingerprint[16]; // = {0xAB,0x87,0x99,0x40,0xBD,0x15,0xB6,0xB2,0x56,0x91,0x26,0x5F,0x73,0x84,0xB2,0x71};

  ModuleTraits() : schema(), trait(), version() {
  }

  virtual ~ModuleTraits() throw() {}

  std::string schema;
  std::string trait;
  std::string version;

  _ModuleTraits__isset __isset;

  void __set_schema(const std::string& val) {
    schema = val;
  }

  void __set_trait(const std::string& val) {
    trait = val;
  }

  void __set_version(const std::string& val) {
    version = val;
  }

  bool operator == (const ModuleTraits & rhs) const
  {
    if (!(schema == rhs.schema))
      return false;
    if (!(trait == rhs.trait))
      return false;
    if (!(version == rhs.version))
      return false;
    return true;
  }
  bool operator != (const ModuleTraits &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ModuleTraits & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(ModuleTraits &a, ModuleTraits &b);

}}} // namespace

#endif