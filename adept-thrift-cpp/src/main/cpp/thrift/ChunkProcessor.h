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
#ifndef ChunkProcessor_H
#define ChunkProcessor_H

#include <thrift/TDispatchProcessor.h>
#include "module_types.h"

namespace thrift { namespace adept { namespace module {

class ChunkProcessorIf {
 public:
  virtual ~ChunkProcessorIf() {}
  virtual void process(std::vector< ::thrift::adept::common::HltContentUnion> & _return, const  ::thrift::adept::common::ChunkUnion& chunk) = 0;
  virtual int64_t processAsync(const  ::thrift::adept::common::ChunkUnion& chunk) = 0;
  virtual bool tryGetResult(const int64_t requestId, const std::vector< ::thrift::adept::common::HltContentUnion> & hltContents) = 0;
};

class ChunkProcessorIfFactory {
 public:
  typedef ChunkProcessorIf Handler;

  virtual ~ChunkProcessorIfFactory() {}

  virtual ChunkProcessorIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ChunkProcessorIf* /* handler */) = 0;
};

class ChunkProcessorIfSingletonFactory : virtual public ChunkProcessorIfFactory {
 public:
  ChunkProcessorIfSingletonFactory(const boost::shared_ptr<ChunkProcessorIf>& iface) : iface_(iface) {}
  virtual ~ChunkProcessorIfSingletonFactory() {}

  virtual ChunkProcessorIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ChunkProcessorIf* /* handler */) {}

 protected:
  boost::shared_ptr<ChunkProcessorIf> iface_;
};

class ChunkProcessorNull : virtual public ChunkProcessorIf {
 public:
  virtual ~ChunkProcessorNull() {}
  void process(std::vector< ::thrift::adept::common::HltContentUnion> & /* _return */, const  ::thrift::adept::common::ChunkUnion& /* chunk */) {
    return;
  }
  int64_t processAsync(const  ::thrift::adept::common::ChunkUnion& /* chunk */) {
    int64_t _return = 0;
    return _return;
  }
  bool tryGetResult(const int64_t /* requestId */, const std::vector< ::thrift::adept::common::HltContentUnion> & /* hltContents */) {
    bool _return = false;
    return _return;
  }
};

typedef struct _ChunkProcessor_process_args__isset {
  _ChunkProcessor_process_args__isset() : chunk(false) {}
  bool chunk;
} _ChunkProcessor_process_args__isset;

class ChunkProcessor_process_args {
 public:

  ChunkProcessor_process_args() {
  }

  virtual ~ChunkProcessor_process_args() throw() {}

   ::thrift::adept::common::ChunkUnion chunk;

  _ChunkProcessor_process_args__isset __isset;

  void __set_chunk(const  ::thrift::adept::common::ChunkUnion& val) {
    chunk = val;
  }

  bool operator == (const ChunkProcessor_process_args & rhs) const
  {
    if (!(chunk == rhs.chunk))
      return false;
    return true;
  }
  bool operator != (const ChunkProcessor_process_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ChunkProcessor_process_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ChunkProcessor_process_pargs {
 public:


  virtual ~ChunkProcessor_process_pargs() throw() {}

  const  ::thrift::adept::common::ChunkUnion* chunk;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ChunkProcessor_process_result__isset {
  _ChunkProcessor_process_result__isset() : success(false) {}
  bool success;
} _ChunkProcessor_process_result__isset;

class ChunkProcessor_process_result {
 public:

  ChunkProcessor_process_result() {
  }

  virtual ~ChunkProcessor_process_result() throw() {}

  std::vector< ::thrift::adept::common::HltContentUnion>  success;

  _ChunkProcessor_process_result__isset __isset;

  void __set_success(const std::vector< ::thrift::adept::common::HltContentUnion> & val) {
    success = val;
  }

  bool operator == (const ChunkProcessor_process_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ChunkProcessor_process_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ChunkProcessor_process_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ChunkProcessor_process_presult__isset {
  _ChunkProcessor_process_presult__isset() : success(false) {}
  bool success;
} _ChunkProcessor_process_presult__isset;

class ChunkProcessor_process_presult {
 public:


  virtual ~ChunkProcessor_process_presult() throw() {}

  std::vector< ::thrift::adept::common::HltContentUnion> * success;

  _ChunkProcessor_process_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _ChunkProcessor_processAsync_args__isset {
  _ChunkProcessor_processAsync_args__isset() : chunk(false) {}
  bool chunk;
} _ChunkProcessor_processAsync_args__isset;

class ChunkProcessor_processAsync_args {
 public:

  ChunkProcessor_processAsync_args() {
  }

  virtual ~ChunkProcessor_processAsync_args() throw() {}

   ::thrift::adept::common::ChunkUnion chunk;

  _ChunkProcessor_processAsync_args__isset __isset;

  void __set_chunk(const  ::thrift::adept::common::ChunkUnion& val) {
    chunk = val;
  }

  bool operator == (const ChunkProcessor_processAsync_args & rhs) const
  {
    if (!(chunk == rhs.chunk))
      return false;
    return true;
  }
  bool operator != (const ChunkProcessor_processAsync_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ChunkProcessor_processAsync_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ChunkProcessor_processAsync_pargs {
 public:


  virtual ~ChunkProcessor_processAsync_pargs() throw() {}

  const  ::thrift::adept::common::ChunkUnion* chunk;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ChunkProcessor_processAsync_result__isset {
  _ChunkProcessor_processAsync_result__isset() : success(false) {}
  bool success;
} _ChunkProcessor_processAsync_result__isset;

class ChunkProcessor_processAsync_result {
 public:

  ChunkProcessor_processAsync_result() : success(0) {
  }

  virtual ~ChunkProcessor_processAsync_result() throw() {}

  int64_t success;

  _ChunkProcessor_processAsync_result__isset __isset;

  void __set_success(const int64_t val) {
    success = val;
  }

  bool operator == (const ChunkProcessor_processAsync_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ChunkProcessor_processAsync_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ChunkProcessor_processAsync_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ChunkProcessor_processAsync_presult__isset {
  _ChunkProcessor_processAsync_presult__isset() : success(false) {}
  bool success;
} _ChunkProcessor_processAsync_presult__isset;

class ChunkProcessor_processAsync_presult {
 public:


  virtual ~ChunkProcessor_processAsync_presult() throw() {}

  int64_t* success;

  _ChunkProcessor_processAsync_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _ChunkProcessor_tryGetResult_args__isset {
  _ChunkProcessor_tryGetResult_args__isset() : requestId(false), hltContents(false) {}
  bool requestId;
  bool hltContents;
} _ChunkProcessor_tryGetResult_args__isset;

class ChunkProcessor_tryGetResult_args {
 public:

  ChunkProcessor_tryGetResult_args() : requestId(0) {
  }

  virtual ~ChunkProcessor_tryGetResult_args() throw() {}

  int64_t requestId;
  std::vector< ::thrift::adept::common::HltContentUnion>  hltContents;

  _ChunkProcessor_tryGetResult_args__isset __isset;

  void __set_requestId(const int64_t val) {
    requestId = val;
  }

  void __set_hltContents(const std::vector< ::thrift::adept::common::HltContentUnion> & val) {
    hltContents = val;
  }

  bool operator == (const ChunkProcessor_tryGetResult_args & rhs) const
  {
    if (!(requestId == rhs.requestId))
      return false;
    if (!(hltContents == rhs.hltContents))
      return false;
    return true;
  }
  bool operator != (const ChunkProcessor_tryGetResult_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ChunkProcessor_tryGetResult_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ChunkProcessor_tryGetResult_pargs {
 public:


  virtual ~ChunkProcessor_tryGetResult_pargs() throw() {}

  const int64_t* requestId;
  const std::vector< ::thrift::adept::common::HltContentUnion> * hltContents;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ChunkProcessor_tryGetResult_result__isset {
  _ChunkProcessor_tryGetResult_result__isset() : success(false) {}
  bool success;
} _ChunkProcessor_tryGetResult_result__isset;

class ChunkProcessor_tryGetResult_result {
 public:

  ChunkProcessor_tryGetResult_result() : success(0) {
  }

  virtual ~ChunkProcessor_tryGetResult_result() throw() {}

  bool success;

  _ChunkProcessor_tryGetResult_result__isset __isset;

  void __set_success(const bool val) {
    success = val;
  }

  bool operator == (const ChunkProcessor_tryGetResult_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ChunkProcessor_tryGetResult_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ChunkProcessor_tryGetResult_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ChunkProcessor_tryGetResult_presult__isset {
  _ChunkProcessor_tryGetResult_presult__isset() : success(false) {}
  bool success;
} _ChunkProcessor_tryGetResult_presult__isset;

class ChunkProcessor_tryGetResult_presult {
 public:


  virtual ~ChunkProcessor_tryGetResult_presult() throw() {}

  bool* success;

  _ChunkProcessor_tryGetResult_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class ChunkProcessorClient : virtual public ChunkProcessorIf {
 public:
  ChunkProcessorClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  ChunkProcessorClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
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
  void process(std::vector< ::thrift::adept::common::HltContentUnion> & _return, const  ::thrift::adept::common::ChunkUnion& chunk);
  void send_process(const  ::thrift::adept::common::ChunkUnion& chunk);
  void recv_process(std::vector< ::thrift::adept::common::HltContentUnion> & _return);
  int64_t processAsync(const  ::thrift::adept::common::ChunkUnion& chunk);
  void send_processAsync(const  ::thrift::adept::common::ChunkUnion& chunk);
  int64_t recv_processAsync();
  bool tryGetResult(const int64_t requestId, const std::vector< ::thrift::adept::common::HltContentUnion> & hltContents);
  void send_tryGetResult(const int64_t requestId, const std::vector< ::thrift::adept::common::HltContentUnion> & hltContents);
  bool recv_tryGetResult();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class ChunkProcessorProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<ChunkProcessorIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (ChunkProcessorProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_process(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_processAsync(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_tryGetResult(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  ChunkProcessorProcessor(boost::shared_ptr<ChunkProcessorIf> iface) :
    iface_(iface) {
    processMap_["process"] = &ChunkProcessorProcessor::process_process;
    processMap_["processAsync"] = &ChunkProcessorProcessor::process_processAsync;
    processMap_["tryGetResult"] = &ChunkProcessorProcessor::process_tryGetResult;
  }

  virtual ~ChunkProcessorProcessor() {}
};

class ChunkProcessorProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  ChunkProcessorProcessorFactory(const ::boost::shared_ptr< ChunkProcessorIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< ChunkProcessorIfFactory > handlerFactory_;
};

class ChunkProcessorMultiface : virtual public ChunkProcessorIf {
 public:
  ChunkProcessorMultiface(std::vector<boost::shared_ptr<ChunkProcessorIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~ChunkProcessorMultiface() {}
 protected:
  std::vector<boost::shared_ptr<ChunkProcessorIf> > ifaces_;
  ChunkProcessorMultiface() {}
  void add(boost::shared_ptr<ChunkProcessorIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void process(std::vector< ::thrift::adept::common::HltContentUnion> & _return, const  ::thrift::adept::common::ChunkUnion& chunk) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->process(_return, chunk);
    }
    ifaces_[i]->process(_return, chunk);
    return;
  }

  int64_t processAsync(const  ::thrift::adept::common::ChunkUnion& chunk) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->processAsync(chunk);
    }
    return ifaces_[i]->processAsync(chunk);
  }

  bool tryGetResult(const int64_t requestId, const std::vector< ::thrift::adept::common::HltContentUnion> & hltContents) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->tryGetResult(requestId, hltContents);
    }
    return ifaces_[i]->tryGetResult(requestId, hltContents);
  }

};

}}} // namespace

#endif