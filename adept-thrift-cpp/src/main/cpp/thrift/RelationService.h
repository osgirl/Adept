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
#ifndef RelationService_H
#define RelationService_H

#include <thrift/TDispatchProcessor.h>
#include "common_types.h"
#include "ItemService.h"

namespace thrift { namespace adept { namespace common {

class RelationServiceIf : virtual public ItemServiceIf {
 public:
  virtual ~RelationServiceIf() {}
  virtual bool addArgument(const Argument& argument) = 0;
  virtual void getArguments(std::vector<Argument> & _return) = 0;
  virtual double getConfidence() = 0;
  virtual void getRelationType(std::string& _return) = 0;
  virtual void setConfidence(const double confidence) = 0;
};

class RelationServiceIfFactory : virtual public ItemServiceIfFactory {
 public:
  typedef RelationServiceIf Handler;

  virtual ~RelationServiceIfFactory() {}

  virtual RelationServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ItemServiceIf* /* handler */) = 0;
};

class RelationServiceIfSingletonFactory : virtual public RelationServiceIfFactory {
 public:
  RelationServiceIfSingletonFactory(const boost::shared_ptr<RelationServiceIf>& iface) : iface_(iface) {}
  virtual ~RelationServiceIfSingletonFactory() {}

  virtual RelationServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ItemServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<RelationServiceIf> iface_;
};

class RelationServiceNull : virtual public RelationServiceIf , virtual public ItemServiceNull {
 public:
  virtual ~RelationServiceNull() {}
  bool addArgument(const Argument& /* argument */) {
    bool _return = false;
    return _return;
  }
  void getArguments(std::vector<Argument> & /* _return */) {
    return;
  }
  double getConfidence() {
    double _return = (double)0;
    return _return;
  }
  void getRelationType(std::string& /* _return */) {
    return;
  }
  void setConfidence(const double /* confidence */) {
    return;
  }
};

typedef struct _RelationService_addArgument_args__isset {
  _RelationService_addArgument_args__isset() : argument(false) {}
  bool argument;
} _RelationService_addArgument_args__isset;

class RelationService_addArgument_args {
 public:

  RelationService_addArgument_args() {
  }

  virtual ~RelationService_addArgument_args() throw() {}

  Argument argument;

  _RelationService_addArgument_args__isset __isset;

  void __set_argument(const Argument& val) {
    argument = val;
  }

  bool operator == (const RelationService_addArgument_args & rhs) const
  {
    if (!(argument == rhs.argument))
      return false;
    return true;
  }
  bool operator != (const RelationService_addArgument_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RelationService_addArgument_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class RelationService_addArgument_pargs {
 public:


  virtual ~RelationService_addArgument_pargs() throw() {}

  const Argument* argument;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RelationService_addArgument_result__isset {
  _RelationService_addArgument_result__isset() : success(false) {}
  bool success;
} _RelationService_addArgument_result__isset;

class RelationService_addArgument_result {
 public:

  RelationService_addArgument_result() : success(0) {
  }

  virtual ~RelationService_addArgument_result() throw() {}

  bool success;

  _RelationService_addArgument_result__isset __isset;

  void __set_success(const bool val) {
    success = val;
  }

  bool operator == (const RelationService_addArgument_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const RelationService_addArgument_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RelationService_addArgument_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RelationService_addArgument_presult__isset {
  _RelationService_addArgument_presult__isset() : success(false) {}
  bool success;
} _RelationService_addArgument_presult__isset;

class RelationService_addArgument_presult {
 public:


  virtual ~RelationService_addArgument_presult() throw() {}

  bool* success;

  _RelationService_addArgument_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class RelationService_getArguments_args {
 public:

  RelationService_getArguments_args() {
  }

  virtual ~RelationService_getArguments_args() throw() {}


  bool operator == (const RelationService_getArguments_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const RelationService_getArguments_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RelationService_getArguments_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class RelationService_getArguments_pargs {
 public:


  virtual ~RelationService_getArguments_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RelationService_getArguments_result__isset {
  _RelationService_getArguments_result__isset() : success(false) {}
  bool success;
} _RelationService_getArguments_result__isset;

class RelationService_getArguments_result {
 public:

  RelationService_getArguments_result() {
  }

  virtual ~RelationService_getArguments_result() throw() {}

  std::vector<Argument>  success;

  _RelationService_getArguments_result__isset __isset;

  void __set_success(const std::vector<Argument> & val) {
    success = val;
  }

  bool operator == (const RelationService_getArguments_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const RelationService_getArguments_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RelationService_getArguments_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RelationService_getArguments_presult__isset {
  _RelationService_getArguments_presult__isset() : success(false) {}
  bool success;
} _RelationService_getArguments_presult__isset;

class RelationService_getArguments_presult {
 public:


  virtual ~RelationService_getArguments_presult() throw() {}

  std::vector<Argument> * success;

  _RelationService_getArguments_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class RelationService_getConfidence_args {
 public:

  RelationService_getConfidence_args() {
  }

  virtual ~RelationService_getConfidence_args() throw() {}


  bool operator == (const RelationService_getConfidence_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const RelationService_getConfidence_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RelationService_getConfidence_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class RelationService_getConfidence_pargs {
 public:


  virtual ~RelationService_getConfidence_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RelationService_getConfidence_result__isset {
  _RelationService_getConfidence_result__isset() : success(false) {}
  bool success;
} _RelationService_getConfidence_result__isset;

class RelationService_getConfidence_result {
 public:

  RelationService_getConfidence_result() : success(0) {
  }

  virtual ~RelationService_getConfidence_result() throw() {}

  double success;

  _RelationService_getConfidence_result__isset __isset;

  void __set_success(const double val) {
    success = val;
  }

  bool operator == (const RelationService_getConfidence_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const RelationService_getConfidence_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RelationService_getConfidence_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RelationService_getConfidence_presult__isset {
  _RelationService_getConfidence_presult__isset() : success(false) {}
  bool success;
} _RelationService_getConfidence_presult__isset;

class RelationService_getConfidence_presult {
 public:


  virtual ~RelationService_getConfidence_presult() throw() {}

  double* success;

  _RelationService_getConfidence_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class RelationService_getRelationType_args {
 public:

  RelationService_getRelationType_args() {
  }

  virtual ~RelationService_getRelationType_args() throw() {}


  bool operator == (const RelationService_getRelationType_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const RelationService_getRelationType_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RelationService_getRelationType_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class RelationService_getRelationType_pargs {
 public:


  virtual ~RelationService_getRelationType_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RelationService_getRelationType_result__isset {
  _RelationService_getRelationType_result__isset() : success(false) {}
  bool success;
} _RelationService_getRelationType_result__isset;

class RelationService_getRelationType_result {
 public:

  RelationService_getRelationType_result() : success() {
  }

  virtual ~RelationService_getRelationType_result() throw() {}

  std::string success;

  _RelationService_getRelationType_result__isset __isset;

  void __set_success(const std::string& val) {
    success = val;
  }

  bool operator == (const RelationService_getRelationType_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const RelationService_getRelationType_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RelationService_getRelationType_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RelationService_getRelationType_presult__isset {
  _RelationService_getRelationType_presult__isset() : success(false) {}
  bool success;
} _RelationService_getRelationType_presult__isset;

class RelationService_getRelationType_presult {
 public:


  virtual ~RelationService_getRelationType_presult() throw() {}

  std::string* success;

  _RelationService_getRelationType_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _RelationService_setConfidence_args__isset {
  _RelationService_setConfidence_args__isset() : confidence(false) {}
  bool confidence;
} _RelationService_setConfidence_args__isset;

class RelationService_setConfidence_args {
 public:

  RelationService_setConfidence_args() : confidence(0) {
  }

  virtual ~RelationService_setConfidence_args() throw() {}

  double confidence;

  _RelationService_setConfidence_args__isset __isset;

  void __set_confidence(const double val) {
    confidence = val;
  }

  bool operator == (const RelationService_setConfidence_args & rhs) const
  {
    if (!(confidence == rhs.confidence))
      return false;
    return true;
  }
  bool operator != (const RelationService_setConfidence_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RelationService_setConfidence_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class RelationService_setConfidence_pargs {
 public:


  virtual ~RelationService_setConfidence_pargs() throw() {}

  const double* confidence;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class RelationService_setConfidence_result {
 public:

  RelationService_setConfidence_result() {
  }

  virtual ~RelationService_setConfidence_result() throw() {}


  bool operator == (const RelationService_setConfidence_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const RelationService_setConfidence_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RelationService_setConfidence_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class RelationService_setConfidence_presult {
 public:


  virtual ~RelationService_setConfidence_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class RelationServiceClient : virtual public RelationServiceIf, public ItemServiceClient {
 public:
  RelationServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    ItemServiceClient(prot, prot) {}
  RelationServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    ItemServiceClient(iprot, oprot) {}
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  bool addArgument(const Argument& argument);
  void send_addArgument(const Argument& argument);
  bool recv_addArgument();
  void getArguments(std::vector<Argument> & _return);
  void send_getArguments();
  void recv_getArguments(std::vector<Argument> & _return);
  double getConfidence();
  void send_getConfidence();
  double recv_getConfidence();
  void getRelationType(std::string& _return);
  void send_getRelationType();
  void recv_getRelationType(std::string& _return);
  void setConfidence(const double confidence);
  void send_setConfidence(const double confidence);
  void recv_setConfidence();
};

class RelationServiceProcessor : public ItemServiceProcessor {
 protected:
  boost::shared_ptr<RelationServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (RelationServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_addArgument(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getArguments(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getConfidence(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getRelationType(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setConfidence(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  RelationServiceProcessor(boost::shared_ptr<RelationServiceIf> iface) :
    ItemServiceProcessor(iface),
    iface_(iface) {
    processMap_["addArgument"] = &RelationServiceProcessor::process_addArgument;
    processMap_["getArguments"] = &RelationServiceProcessor::process_getArguments;
    processMap_["getConfidence"] = &RelationServiceProcessor::process_getConfidence;
    processMap_["getRelationType"] = &RelationServiceProcessor::process_getRelationType;
    processMap_["setConfidence"] = &RelationServiceProcessor::process_setConfidence;
  }

  virtual ~RelationServiceProcessor() {}
};

class RelationServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  RelationServiceProcessorFactory(const ::boost::shared_ptr< RelationServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< RelationServiceIfFactory > handlerFactory_;
};

class RelationServiceMultiface : virtual public RelationServiceIf, public ItemServiceMultiface {
 public:
  RelationServiceMultiface(std::vector<boost::shared_ptr<RelationServiceIf> >& ifaces) : ifaces_(ifaces) {
    std::vector<boost::shared_ptr<RelationServiceIf> >::iterator iter;
    for (iter = ifaces.begin(); iter != ifaces.end(); ++iter) {
      ItemServiceMultiface::add(*iter);
    }
  }
  virtual ~RelationServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<RelationServiceIf> > ifaces_;
  RelationServiceMultiface() {}
  void add(boost::shared_ptr<RelationServiceIf> iface) {
    ItemServiceMultiface::add(iface);
    ifaces_.push_back(iface);
  }
 public:
  bool addArgument(const Argument& argument) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->addArgument(argument);
    }
    return ifaces_[i]->addArgument(argument);
  }

  void getArguments(std::vector<Argument> & _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getArguments(_return);
    }
    ifaces_[i]->getArguments(_return);
    return;
  }

  double getConfidence() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getConfidence();
    }
    return ifaces_[i]->getConfidence();
  }

  void getRelationType(std::string& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getRelationType(_return);
    }
    ifaces_[i]->getRelationType(_return);
    return;
  }

  void setConfidence(const double confidence) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setConfidence(confidence);
    }
    ifaces_[i]->setConfidence(confidence);
  }

};

}}} // namespace

#endif