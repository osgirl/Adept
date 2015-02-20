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
#ifndef OpinionService_H
#define OpinionService_H

#include <thrift/TDispatchProcessor.h>
#include "common_types.h"
#include "ChunkService.h"

namespace thrift { namespace adept { namespace common {

class OpinionServiceIf : virtual public ChunkServiceIf {
 public:
  virtual ~OpinionServiceIf() {}
  virtual Polarity::type getPolarity() = 0;
  virtual Subjectivity::type getSubjectivity() = 0;
};

class OpinionServiceIfFactory : virtual public ChunkServiceIfFactory {
 public:
  typedef OpinionServiceIf Handler;

  virtual ~OpinionServiceIfFactory() {}

  virtual OpinionServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ItemServiceIf* /* handler */) = 0;
};

class OpinionServiceIfSingletonFactory : virtual public OpinionServiceIfFactory {
 public:
  OpinionServiceIfSingletonFactory(const boost::shared_ptr<OpinionServiceIf>& iface) : iface_(iface) {}
  virtual ~OpinionServiceIfSingletonFactory() {}

  virtual OpinionServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ItemServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<OpinionServiceIf> iface_;
};

class OpinionServiceNull : virtual public OpinionServiceIf , virtual public ChunkServiceNull {
 public:
  virtual ~OpinionServiceNull() {}
  Polarity::type getPolarity() {
    Polarity::type _return = (Polarity::type)0;
    return _return;
  }
  Subjectivity::type getSubjectivity() {
    Subjectivity::type _return = (Subjectivity::type)0;
    return _return;
  }
};


class OpinionService_getPolarity_args {
 public:

  OpinionService_getPolarity_args() {
  }

  virtual ~OpinionService_getPolarity_args() throw() {}


  bool operator == (const OpinionService_getPolarity_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const OpinionService_getPolarity_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const OpinionService_getPolarity_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class OpinionService_getPolarity_pargs {
 public:


  virtual ~OpinionService_getPolarity_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _OpinionService_getPolarity_result__isset {
  _OpinionService_getPolarity_result__isset() : success(false) {}
  bool success;
} _OpinionService_getPolarity_result__isset;

class OpinionService_getPolarity_result {
 public:

  OpinionService_getPolarity_result() : success((Polarity::type)0) {
  }

  virtual ~OpinionService_getPolarity_result() throw() {}

  Polarity::type success;

  _OpinionService_getPolarity_result__isset __isset;

  void __set_success(const Polarity::type val) {
    success = val;
  }

  bool operator == (const OpinionService_getPolarity_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const OpinionService_getPolarity_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const OpinionService_getPolarity_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _OpinionService_getPolarity_presult__isset {
  _OpinionService_getPolarity_presult__isset() : success(false) {}
  bool success;
} _OpinionService_getPolarity_presult__isset;

class OpinionService_getPolarity_presult {
 public:


  virtual ~OpinionService_getPolarity_presult() throw() {}

  Polarity::type* success;

  _OpinionService_getPolarity_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class OpinionService_getSubjectivity_args {
 public:

  OpinionService_getSubjectivity_args() {
  }

  virtual ~OpinionService_getSubjectivity_args() throw() {}


  bool operator == (const OpinionService_getSubjectivity_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const OpinionService_getSubjectivity_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const OpinionService_getSubjectivity_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class OpinionService_getSubjectivity_pargs {
 public:


  virtual ~OpinionService_getSubjectivity_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _OpinionService_getSubjectivity_result__isset {
  _OpinionService_getSubjectivity_result__isset() : success(false) {}
  bool success;
} _OpinionService_getSubjectivity_result__isset;

class OpinionService_getSubjectivity_result {
 public:

  OpinionService_getSubjectivity_result() : success((Subjectivity::type)0) {
  }

  virtual ~OpinionService_getSubjectivity_result() throw() {}

  Subjectivity::type success;

  _OpinionService_getSubjectivity_result__isset __isset;

  void __set_success(const Subjectivity::type val) {
    success = val;
  }

  bool operator == (const OpinionService_getSubjectivity_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const OpinionService_getSubjectivity_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const OpinionService_getSubjectivity_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _OpinionService_getSubjectivity_presult__isset {
  _OpinionService_getSubjectivity_presult__isset() : success(false) {}
  bool success;
} _OpinionService_getSubjectivity_presult__isset;

class OpinionService_getSubjectivity_presult {
 public:


  virtual ~OpinionService_getSubjectivity_presult() throw() {}

  Subjectivity::type* success;

  _OpinionService_getSubjectivity_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class OpinionServiceClient : virtual public OpinionServiceIf, public ChunkServiceClient {
 public:
  OpinionServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    ChunkServiceClient(prot, prot) {}
  OpinionServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    ChunkServiceClient(iprot, oprot) {}
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  Polarity::type getPolarity();
  void send_getPolarity();
  Polarity::type recv_getPolarity();
  Subjectivity::type getSubjectivity();
  void send_getSubjectivity();
  Subjectivity::type recv_getSubjectivity();
};

class OpinionServiceProcessor : public ChunkServiceProcessor {
 protected:
  boost::shared_ptr<OpinionServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (OpinionServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_getPolarity(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getSubjectivity(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  OpinionServiceProcessor(boost::shared_ptr<OpinionServiceIf> iface) :
    ChunkServiceProcessor(iface),
    iface_(iface) {
    processMap_["getPolarity"] = &OpinionServiceProcessor::process_getPolarity;
    processMap_["getSubjectivity"] = &OpinionServiceProcessor::process_getSubjectivity;
  }

  virtual ~OpinionServiceProcessor() {}
};

class OpinionServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  OpinionServiceProcessorFactory(const ::boost::shared_ptr< OpinionServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< OpinionServiceIfFactory > handlerFactory_;
};

class OpinionServiceMultiface : virtual public OpinionServiceIf, public ChunkServiceMultiface {
 public:
  OpinionServiceMultiface(std::vector<boost::shared_ptr<OpinionServiceIf> >& ifaces) : ifaces_(ifaces) {
    std::vector<boost::shared_ptr<OpinionServiceIf> >::iterator iter;
    for (iter = ifaces.begin(); iter != ifaces.end(); ++iter) {
      ChunkServiceMultiface::add(*iter);
    }
  }
  virtual ~OpinionServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<OpinionServiceIf> > ifaces_;
  OpinionServiceMultiface() {}
  void add(boost::shared_ptr<OpinionServiceIf> iface) {
    ChunkServiceMultiface::add(iface);
    ifaces_.push_back(iface);
  }
 public:
  Polarity::type getPolarity() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getPolarity();
    }
    return ifaces_[i]->getPolarity();
  }

  Subjectivity::type getSubjectivity() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getSubjectivity();
    }
    return ifaces_[i]->getSubjectivity();
  }

};

}}} // namespace

#endif