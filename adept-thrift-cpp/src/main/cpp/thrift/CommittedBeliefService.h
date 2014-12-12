/*******************************************************************************
 * Raytheon BBN Technologies Corp., December 2014
 * 
 * THIS CODE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS
 * OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 * 
 * Copyright 2014 Raytheon BBN Technologies Corp.  All Rights Reserved.
 ******************************************************************************/
/**
 * 
 */

/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef CommittedBeliefService_H
#define CommittedBeliefService_H

#include <thrift/TDispatchProcessor.h>
#include "common_types.h"
#include "ChunkService.h"

namespace thrift { namespace adept { namespace common {

class CommittedBeliefServiceIf : virtual public ChunkServiceIf {
 public:
  virtual ~CommittedBeliefServiceIf() {}
  virtual Modality::type getModality() = 0;
  virtual int64_t getSequenceId() = 0;
};

class CommittedBeliefServiceIfFactory : virtual public ChunkServiceIfFactory {
 public:
  typedef CommittedBeliefServiceIf Handler;

  virtual ~CommittedBeliefServiceIfFactory() {}

  virtual CommittedBeliefServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ItemServiceIf* /* handler */) = 0;
};

class CommittedBeliefServiceIfSingletonFactory : virtual public CommittedBeliefServiceIfFactory {
 public:
  CommittedBeliefServiceIfSingletonFactory(const boost::shared_ptr<CommittedBeliefServiceIf>& iface) : iface_(iface) {}
  virtual ~CommittedBeliefServiceIfSingletonFactory() {}

  virtual CommittedBeliefServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ItemServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<CommittedBeliefServiceIf> iface_;
};

class CommittedBeliefServiceNull : virtual public CommittedBeliefServiceIf , virtual public ChunkServiceNull {
 public:
  virtual ~CommittedBeliefServiceNull() {}
  Modality::type getModality() {
    Modality::type _return = (Modality::type)0;
    return _return;
  }
  int64_t getSequenceId() {
    int64_t _return = 0;
    return _return;
  }
};


class CommittedBeliefService_getModality_args {
 public:

  CommittedBeliefService_getModality_args() {
  }

  virtual ~CommittedBeliefService_getModality_args() throw() {}


  bool operator == (const CommittedBeliefService_getModality_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const CommittedBeliefService_getModality_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const CommittedBeliefService_getModality_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class CommittedBeliefService_getModality_pargs {
 public:


  virtual ~CommittedBeliefService_getModality_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _CommittedBeliefService_getModality_result__isset {
  _CommittedBeliefService_getModality_result__isset() : success(false) {}
  bool success;
} _CommittedBeliefService_getModality_result__isset;

class CommittedBeliefService_getModality_result {
 public:

  CommittedBeliefService_getModality_result() : success((Modality::type)0) {
  }

  virtual ~CommittedBeliefService_getModality_result() throw() {}

  Modality::type success;

  _CommittedBeliefService_getModality_result__isset __isset;

  void __set_success(const Modality::type val) {
    success = val;
  }

  bool operator == (const CommittedBeliefService_getModality_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const CommittedBeliefService_getModality_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const CommittedBeliefService_getModality_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _CommittedBeliefService_getModality_presult__isset {
  _CommittedBeliefService_getModality_presult__isset() : success(false) {}
  bool success;
} _CommittedBeliefService_getModality_presult__isset;

class CommittedBeliefService_getModality_presult {
 public:


  virtual ~CommittedBeliefService_getModality_presult() throw() {}

  Modality::type* success;

  _CommittedBeliefService_getModality_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class CommittedBeliefService_getSequenceId_args {
 public:

  CommittedBeliefService_getSequenceId_args() {
  }

  virtual ~CommittedBeliefService_getSequenceId_args() throw() {}


  bool operator == (const CommittedBeliefService_getSequenceId_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const CommittedBeliefService_getSequenceId_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const CommittedBeliefService_getSequenceId_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class CommittedBeliefService_getSequenceId_pargs {
 public:


  virtual ~CommittedBeliefService_getSequenceId_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _CommittedBeliefService_getSequenceId_result__isset {
  _CommittedBeliefService_getSequenceId_result__isset() : success(false) {}
  bool success;
} _CommittedBeliefService_getSequenceId_result__isset;

class CommittedBeliefService_getSequenceId_result {
 public:

  CommittedBeliefService_getSequenceId_result() : success(0) {
  }

  virtual ~CommittedBeliefService_getSequenceId_result() throw() {}

  int64_t success;

  _CommittedBeliefService_getSequenceId_result__isset __isset;

  void __set_success(const int64_t val) {
    success = val;
  }

  bool operator == (const CommittedBeliefService_getSequenceId_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const CommittedBeliefService_getSequenceId_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const CommittedBeliefService_getSequenceId_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _CommittedBeliefService_getSequenceId_presult__isset {
  _CommittedBeliefService_getSequenceId_presult__isset() : success(false) {}
  bool success;
} _CommittedBeliefService_getSequenceId_presult__isset;

class CommittedBeliefService_getSequenceId_presult {
 public:


  virtual ~CommittedBeliefService_getSequenceId_presult() throw() {}

  int64_t* success;

  _CommittedBeliefService_getSequenceId_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class CommittedBeliefServiceClient : virtual public CommittedBeliefServiceIf, public ChunkServiceClient {
 public:
  CommittedBeliefServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    ChunkServiceClient(prot, prot) {}
  CommittedBeliefServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    ChunkServiceClient(iprot, oprot) {}
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  Modality::type getModality();
  void send_getModality();
  Modality::type recv_getModality();
  int64_t getSequenceId();
  void send_getSequenceId();
  int64_t recv_getSequenceId();
};

class CommittedBeliefServiceProcessor : public ChunkServiceProcessor {
 protected:
  boost::shared_ptr<CommittedBeliefServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (CommittedBeliefServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_getModality(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getSequenceId(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  CommittedBeliefServiceProcessor(boost::shared_ptr<CommittedBeliefServiceIf> iface) :
    ChunkServiceProcessor(iface),
    iface_(iface) {
    processMap_["getModality"] = &CommittedBeliefServiceProcessor::process_getModality;
    processMap_["getSequenceId"] = &CommittedBeliefServiceProcessor::process_getSequenceId;
  }

  virtual ~CommittedBeliefServiceProcessor() {}
};

class CommittedBeliefServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  CommittedBeliefServiceProcessorFactory(const ::boost::shared_ptr< CommittedBeliefServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< CommittedBeliefServiceIfFactory > handlerFactory_;
};

class CommittedBeliefServiceMultiface : virtual public CommittedBeliefServiceIf, public ChunkServiceMultiface {
 public:
  CommittedBeliefServiceMultiface(std::vector<boost::shared_ptr<CommittedBeliefServiceIf> >& ifaces) : ifaces_(ifaces) {
    std::vector<boost::shared_ptr<CommittedBeliefServiceIf> >::iterator iter;
    for (iter = ifaces.begin(); iter != ifaces.end(); ++iter) {
      ChunkServiceMultiface::add(*iter);
    }
  }
  virtual ~CommittedBeliefServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<CommittedBeliefServiceIf> > ifaces_;
  CommittedBeliefServiceMultiface() {}
  void add(boost::shared_ptr<CommittedBeliefServiceIf> iface) {
    ChunkServiceMultiface::add(iface);
    ifaces_.push_back(iface);
  }
 public:
  Modality::type getModality() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getModality();
    }
    return ifaces_[i]->getModality();
  }

  int64_t getSequenceId() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getSequenceId();
    }
    return ifaces_[i]->getSequenceId();
  }

};

}}} // namespace

#endif
