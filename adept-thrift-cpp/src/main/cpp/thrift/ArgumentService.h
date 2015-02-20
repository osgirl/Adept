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
#ifndef ArgumentService_H
#define ArgumentService_H

#include <thrift/TDispatchProcessor.h>
#include "common_types.h"

namespace thrift { namespace adept { namespace common {

class ArgumentServiceIf {
 public:
  virtual ~ArgumentServiceIf() {}
  virtual bool addArgumentConfidencePair(const ChunkUnion& argument, const double confidence) = 0;
  virtual void getArgumentDistribution(std::map<ChunkUnion, double> & _return) = 0;
  virtual void getArgumentType(std::string& _return) = 0;
  virtual void getBestArgument(ChunkUnion& _return) = 0;
  virtual void setArgumentDistribution(const std::map<ChunkUnion, double> & argumentDistribution) = 0;
};

class ArgumentServiceIfFactory {
 public:
  typedef ArgumentServiceIf Handler;

  virtual ~ArgumentServiceIfFactory() {}

  virtual ArgumentServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ArgumentServiceIf* /* handler */) = 0;
};

class ArgumentServiceIfSingletonFactory : virtual public ArgumentServiceIfFactory {
 public:
  ArgumentServiceIfSingletonFactory(const boost::shared_ptr<ArgumentServiceIf>& iface) : iface_(iface) {}
  virtual ~ArgumentServiceIfSingletonFactory() {}

  virtual ArgumentServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ArgumentServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<ArgumentServiceIf> iface_;
};

class ArgumentServiceNull : virtual public ArgumentServiceIf {
 public:
  virtual ~ArgumentServiceNull() {}
  bool addArgumentConfidencePair(const ChunkUnion& /* argument */, const double /* confidence */) {
    bool _return = false;
    return _return;
  }
  void getArgumentDistribution(std::map<ChunkUnion, double> & /* _return */) {
    return;
  }
  void getArgumentType(std::string& /* _return */) {
    return;
  }
  void getBestArgument(ChunkUnion& /* _return */) {
    return;
  }
  void setArgumentDistribution(const std::map<ChunkUnion, double> & /* argumentDistribution */) {
    return;
  }
};

typedef struct _ArgumentService_addArgumentConfidencePair_args__isset {
  _ArgumentService_addArgumentConfidencePair_args__isset() : argument(false), confidence(false) {}
  bool argument;
  bool confidence;
} _ArgumentService_addArgumentConfidencePair_args__isset;

class ArgumentService_addArgumentConfidencePair_args {
 public:

  ArgumentService_addArgumentConfidencePair_args() : confidence(0) {
  }

  virtual ~ArgumentService_addArgumentConfidencePair_args() throw() {}

  ChunkUnion argument;
  double confidence;

  _ArgumentService_addArgumentConfidencePair_args__isset __isset;

  void __set_argument(const ChunkUnion& val) {
    argument = val;
  }

  void __set_confidence(const double val) {
    confidence = val;
  }

  bool operator == (const ArgumentService_addArgumentConfidencePair_args & rhs) const
  {
    if (!(argument == rhs.argument))
      return false;
    if (!(confidence == rhs.confidence))
      return false;
    return true;
  }
  bool operator != (const ArgumentService_addArgumentConfidencePair_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ArgumentService_addArgumentConfidencePair_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ArgumentService_addArgumentConfidencePair_pargs {
 public:


  virtual ~ArgumentService_addArgumentConfidencePair_pargs() throw() {}

  const ChunkUnion* argument;
  const double* confidence;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ArgumentService_addArgumentConfidencePair_result__isset {
  _ArgumentService_addArgumentConfidencePair_result__isset() : success(false) {}
  bool success;
} _ArgumentService_addArgumentConfidencePair_result__isset;

class ArgumentService_addArgumentConfidencePair_result {
 public:

  ArgumentService_addArgumentConfidencePair_result() : success(0) {
  }

  virtual ~ArgumentService_addArgumentConfidencePair_result() throw() {}

  bool success;

  _ArgumentService_addArgumentConfidencePair_result__isset __isset;

  void __set_success(const bool val) {
    success = val;
  }

  bool operator == (const ArgumentService_addArgumentConfidencePair_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ArgumentService_addArgumentConfidencePair_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ArgumentService_addArgumentConfidencePair_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ArgumentService_addArgumentConfidencePair_presult__isset {
  _ArgumentService_addArgumentConfidencePair_presult__isset() : success(false) {}
  bool success;
} _ArgumentService_addArgumentConfidencePair_presult__isset;

class ArgumentService_addArgumentConfidencePair_presult {
 public:


  virtual ~ArgumentService_addArgumentConfidencePair_presult() throw() {}

  bool* success;

  _ArgumentService_addArgumentConfidencePair_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class ArgumentService_getArgumentDistribution_args {
 public:

  ArgumentService_getArgumentDistribution_args() {
  }

  virtual ~ArgumentService_getArgumentDistribution_args() throw() {}


  bool operator == (const ArgumentService_getArgumentDistribution_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ArgumentService_getArgumentDistribution_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ArgumentService_getArgumentDistribution_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ArgumentService_getArgumentDistribution_pargs {
 public:


  virtual ~ArgumentService_getArgumentDistribution_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ArgumentService_getArgumentDistribution_result__isset {
  _ArgumentService_getArgumentDistribution_result__isset() : success(false) {}
  bool success;
} _ArgumentService_getArgumentDistribution_result__isset;

class ArgumentService_getArgumentDistribution_result {
 public:

  ArgumentService_getArgumentDistribution_result() {
  }

  virtual ~ArgumentService_getArgumentDistribution_result() throw() {}

  std::map<ChunkUnion, double>  success;

  _ArgumentService_getArgumentDistribution_result__isset __isset;

  void __set_success(const std::map<ChunkUnion, double> & val) {
    success = val;
  }

  bool operator == (const ArgumentService_getArgumentDistribution_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ArgumentService_getArgumentDistribution_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ArgumentService_getArgumentDistribution_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ArgumentService_getArgumentDistribution_presult__isset {
  _ArgumentService_getArgumentDistribution_presult__isset() : success(false) {}
  bool success;
} _ArgumentService_getArgumentDistribution_presult__isset;

class ArgumentService_getArgumentDistribution_presult {
 public:


  virtual ~ArgumentService_getArgumentDistribution_presult() throw() {}

  std::map<ChunkUnion, double> * success;

  _ArgumentService_getArgumentDistribution_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class ArgumentService_getArgumentType_args {
 public:

  ArgumentService_getArgumentType_args() {
  }

  virtual ~ArgumentService_getArgumentType_args() throw() {}


  bool operator == (const ArgumentService_getArgumentType_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ArgumentService_getArgumentType_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ArgumentService_getArgumentType_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ArgumentService_getArgumentType_pargs {
 public:


  virtual ~ArgumentService_getArgumentType_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ArgumentService_getArgumentType_result__isset {
  _ArgumentService_getArgumentType_result__isset() : success(false) {}
  bool success;
} _ArgumentService_getArgumentType_result__isset;

class ArgumentService_getArgumentType_result {
 public:

  ArgumentService_getArgumentType_result() : success() {
  }

  virtual ~ArgumentService_getArgumentType_result() throw() {}

  std::string success;

  _ArgumentService_getArgumentType_result__isset __isset;

  void __set_success(const std::string& val) {
    success = val;
  }

  bool operator == (const ArgumentService_getArgumentType_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ArgumentService_getArgumentType_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ArgumentService_getArgumentType_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ArgumentService_getArgumentType_presult__isset {
  _ArgumentService_getArgumentType_presult__isset() : success(false) {}
  bool success;
} _ArgumentService_getArgumentType_presult__isset;

class ArgumentService_getArgumentType_presult {
 public:


  virtual ~ArgumentService_getArgumentType_presult() throw() {}

  std::string* success;

  _ArgumentService_getArgumentType_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class ArgumentService_getBestArgument_args {
 public:

  ArgumentService_getBestArgument_args() {
  }

  virtual ~ArgumentService_getBestArgument_args() throw() {}


  bool operator == (const ArgumentService_getBestArgument_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ArgumentService_getBestArgument_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ArgumentService_getBestArgument_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ArgumentService_getBestArgument_pargs {
 public:


  virtual ~ArgumentService_getBestArgument_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ArgumentService_getBestArgument_result__isset {
  _ArgumentService_getBestArgument_result__isset() : success(false) {}
  bool success;
} _ArgumentService_getBestArgument_result__isset;

class ArgumentService_getBestArgument_result {
 public:

  ArgumentService_getBestArgument_result() {
  }

  virtual ~ArgumentService_getBestArgument_result() throw() {}

  ChunkUnion success;

  _ArgumentService_getBestArgument_result__isset __isset;

  void __set_success(const ChunkUnion& val) {
    success = val;
  }

  bool operator == (const ArgumentService_getBestArgument_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ArgumentService_getBestArgument_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ArgumentService_getBestArgument_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ArgumentService_getBestArgument_presult__isset {
  _ArgumentService_getBestArgument_presult__isset() : success(false) {}
  bool success;
} _ArgumentService_getBestArgument_presult__isset;

class ArgumentService_getBestArgument_presult {
 public:


  virtual ~ArgumentService_getBestArgument_presult() throw() {}

  ChunkUnion* success;

  _ArgumentService_getBestArgument_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _ArgumentService_setArgumentDistribution_args__isset {
  _ArgumentService_setArgumentDistribution_args__isset() : argumentDistribution(false) {}
  bool argumentDistribution;
} _ArgumentService_setArgumentDistribution_args__isset;

class ArgumentService_setArgumentDistribution_args {
 public:

  ArgumentService_setArgumentDistribution_args() {
  }

  virtual ~ArgumentService_setArgumentDistribution_args() throw() {}

  std::map<ChunkUnion, double>  argumentDistribution;

  _ArgumentService_setArgumentDistribution_args__isset __isset;

  void __set_argumentDistribution(const std::map<ChunkUnion, double> & val) {
    argumentDistribution = val;
  }

  bool operator == (const ArgumentService_setArgumentDistribution_args & rhs) const
  {
    if (!(argumentDistribution == rhs.argumentDistribution))
      return false;
    return true;
  }
  bool operator != (const ArgumentService_setArgumentDistribution_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ArgumentService_setArgumentDistribution_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ArgumentService_setArgumentDistribution_pargs {
 public:


  virtual ~ArgumentService_setArgumentDistribution_pargs() throw() {}

  const std::map<ChunkUnion, double> * argumentDistribution;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ArgumentService_setArgumentDistribution_result {
 public:

  ArgumentService_setArgumentDistribution_result() {
  }

  virtual ~ArgumentService_setArgumentDistribution_result() throw() {}


  bool operator == (const ArgumentService_setArgumentDistribution_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ArgumentService_setArgumentDistribution_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ArgumentService_setArgumentDistribution_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ArgumentService_setArgumentDistribution_presult {
 public:


  virtual ~ArgumentService_setArgumentDistribution_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class ArgumentServiceClient : virtual public ArgumentServiceIf {
 public:
  ArgumentServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  ArgumentServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  bool addArgumentConfidencePair(const ChunkUnion& argument, const double confidence);
  void send_addArgumentConfidencePair(const ChunkUnion& argument, const double confidence);
  bool recv_addArgumentConfidencePair();
  void getArgumentDistribution(std::map<ChunkUnion, double> & _return);
  void send_getArgumentDistribution();
  void recv_getArgumentDistribution(std::map<ChunkUnion, double> & _return);
  void getArgumentType(std::string& _return);
  void send_getArgumentType();
  void recv_getArgumentType(std::string& _return);
  void getBestArgument(ChunkUnion& _return);
  void send_getBestArgument();
  void recv_getBestArgument(ChunkUnion& _return);
  void setArgumentDistribution(const std::map<ChunkUnion, double> & argumentDistribution);
  void send_setArgumentDistribution(const std::map<ChunkUnion, double> & argumentDistribution);
  void recv_setArgumentDistribution();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class ArgumentServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<ArgumentServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (ArgumentServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_addArgumentConfidencePair(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getArgumentDistribution(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getArgumentType(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getBestArgument(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setArgumentDistribution(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  ArgumentServiceProcessor(boost::shared_ptr<ArgumentServiceIf> iface) :
    iface_(iface) {
    processMap_["addArgumentConfidencePair"] = &ArgumentServiceProcessor::process_addArgumentConfidencePair;
    processMap_["getArgumentDistribution"] = &ArgumentServiceProcessor::process_getArgumentDistribution;
    processMap_["getArgumentType"] = &ArgumentServiceProcessor::process_getArgumentType;
    processMap_["getBestArgument"] = &ArgumentServiceProcessor::process_getBestArgument;
    processMap_["setArgumentDistribution"] = &ArgumentServiceProcessor::process_setArgumentDistribution;
  }

  virtual ~ArgumentServiceProcessor() {}
};

class ArgumentServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  ArgumentServiceProcessorFactory(const ::boost::shared_ptr< ArgumentServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< ArgumentServiceIfFactory > handlerFactory_;
};

class ArgumentServiceMultiface : virtual public ArgumentServiceIf {
 public:
  ArgumentServiceMultiface(std::vector<boost::shared_ptr<ArgumentServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~ArgumentServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<ArgumentServiceIf> > ifaces_;
  ArgumentServiceMultiface() {}
  void add(boost::shared_ptr<ArgumentServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  bool addArgumentConfidencePair(const ChunkUnion& argument, const double confidence) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->addArgumentConfidencePair(argument, confidence);
    }
    return ifaces_[i]->addArgumentConfidencePair(argument, confidence);
  }

  void getArgumentDistribution(std::map<ChunkUnion, double> & _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getArgumentDistribution(_return);
    }
    ifaces_[i]->getArgumentDistribution(_return);
    return;
  }

  void getArgumentType(std::string& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getArgumentType(_return);
    }
    ifaces_[i]->getArgumentType(_return);
    return;
  }

  void getBestArgument(ChunkUnion& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getBestArgument(_return);
    }
    ifaces_[i]->getBestArgument(_return);
    return;
  }

  void setArgumentDistribution(const std::map<ChunkUnion, double> & argumentDistribution) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setArgumentDistribution(argumentDistribution);
    }
    ifaces_[i]->setArgumentDistribution(argumentDistribution);
  }

};

}}} // namespace

#endif