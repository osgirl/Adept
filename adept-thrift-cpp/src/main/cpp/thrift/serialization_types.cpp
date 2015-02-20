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
#include "serialization_types.h"

#include <algorithm>

namespace thrift { namespace adept { namespace serialization {

int _kSerializationTypeValues[] = {
  SerializationType::BINARY,
  SerializationType::XML,
  SerializationType::JSON
};
const char* _kSerializationTypeNames[] = {
  "BINARY",
  "XML",
  "JSON"
};
const std::map<int, const char*> _SerializationType_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(3, _kSerializationTypeValues, _kSerializationTypeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

}}} // namespace