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
#ifndef PassagePairProcessor_H
#define PassagePairProcessor_H

#include <thrift/TDispatchProcessor.h>
#include "module_types.h"

namespace thrift { namespace adept { namespace module {

class PassagePairProcessorIf {
 public:
  virtual ~PassagePairProcessorIf() {}
  virtual void process(std::vector< ::thrift::adept::common::HltContentUnion> & _return, const  ::thrift::adept::common::Passage& passage1, const  ::thrift::adept::common::Passage& passage2) = 0;
  virtual int64_t processAsync(const  ::thrift::adept::common::Passage& passage1, const  ::thrift::adept::common::Passage& passage2) = 0;
  virtual bool tryGetResult(const int64_t requestId, const std::vector< ::thrift::adept::common::HltContentUnion> & metaContents) = 0;
};

class PassagePairProcessorIfFactory {
 public:
  typedef PassagePairProcessorIf Handler;

  virtual ~PassagePairProcessorIfFactory() {}

  virtual PassagePairProcessorIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(PassagePairProcessorIf* /* handler */) = 0;
};

class PassagePairProcessorIfSingletonFactory : virtual public PassagePairProcessorIfFactory {
 public:
  PassagePairProcessorIfSingletonFactory(const boost::shared_ptr<PassagePairProcessorIf>& iface) : iface_(iface) {}
  virtual ~PassagePairProcessorIfSingletonFactory() {}

  virtual PassagePairProcessorIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(PassagePairProcessorIf* /* handler */) {}

 protected:
  boost::shared_ptr<PassagePairProcessorIf> iface_;
};

class PassagePairProcessorNull : virtual public PassagePairProcessorIf {
 public:
  virtual ~PassagePairProcessorNull() {}
  void process(std::vector< ::thrift::adept::common::HltContentUnion> & /* _return */, const  ::thrift::adept::common::Passage& /* passage1 */, const  ::thrift::adept::common::Passage& /* passage2 */) {
    return;
  }
  int64_t processAsync(const  ::thrift::adept::common::Passage& /* passage1 */, const  ::thrift::adept::common::Passage& /* passage2 */) {
    int64_t _return = 0;
    return _return;
  }
  bool tryGetResult(const int64_t /* requestId */, const std::vector< ::thrift::adept::common::HltContentUnion> & /* metaContents */) {
    bool _return = false;
    return _return;
  }
};

typedef struct _PassagePairProcessor_process_args__isset {
  _PassagePairProcessor_process_args__isset() : passage1(false), passage2(false) {}
  bool passage1;
  bool passage2;
} _PassagePairProcessor_process_args__isset;

class PassagePairProcessor_process_args {
 public:

  PassagePairProcessor_process_args() {
  }

  virtual ~PassagePairProcessor_process_args() throw() {}

   ::thrift::adept::common::Passage passage1;
   ::thrift::adept::common::Passage passage2;

  _PassagePairProcessor_process_args__isset __isset;

  void __set_passage1(const  ::thrift::adept::common::Passage& val) {
    passage1 = val;
  }

  void __set_passage2(const  ::thrift::adept::common::Passage& val) {
    passage2 = val;
  }

  bool operator == (const PassagePairProcessor_process_args & rhs) const
  {
    if (!(passage1 == rhs.passage1))
      return false;
    if (!(passage2 == rhs.passage2))
      return false;
    return true;
  }
  bool operator != (const PassagePairProcessor_process_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PassagePairProcessor_process_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class PassagePairProcessor_process_pargs {
 public:


  virtual ~PassagePairProcessor_process_pargs() throw() {}

  const  ::thrift::adept::common::Passage* passage1;
  const  ::thrift::adept::common::Passage* passage2;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _PassagePairProcessor_process_result__isset {
  _PassagePairProcessor_process_result__isset() : success(false) {}
  bool success;
} _PassagePairProcessor_process_result__isset;

class PassagePairProcessor_process_result {
 public:

  PassagePairProcessor_process_result() {
  }

  virtual ~PassagePairProcessor_process_result() throw() {}

  std::vector< ::thrift::adept::common::HltContentUnion>  success;

  _PassagePairProcessor_process_result__isset __isset;

  void __set_success(const std::vector< ::thrift::adept::common::HltContentUnion> & val) {
    success = val;
  }

  bool operator == (const PassagePairProcessor_process_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const PassagePairProcessor_process_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PassagePairProcessor_process_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _PassagePairProcessor_process_presult__isset {
  _PassagePairProcessor_process_presult__isset() : success(false) {}
  bool success;
} _PassagePairProcessor_process_presult__isset;

class PassagePairProcessor_process_presult {
 public:


  virtual ~PassagePairProcessor_process_presult() throw() {}

  std::vector< ::thrift::adept::common::HltContentUnion> * success;

  _PassagePairProcessor_process_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _PassagePairProcessor_processAsync_args__isset {
  _PassagePairProcessor_processAsync_args__isset() : passage1(false), passage2(false) {}
  bool passage1;
  bool passage2;
} _PassagePairProcessor_processAsync_args__isset;

class PassagePairProcessor_processAsync_args {
 public:

  PassagePairProcessor_processAsync_args() {
  }

  virtual ~PassagePairProcessor_processAsync_args() throw() {}

   ::thrift::adept::common::Passage passage1;
   ::thrift::adept::common::Passage passage2;

  _PassagePairProcessor_processAsync_args__isset __isset;

  void __set_passage1(const  ::thrift::adept::common::Passage& val) {
    passage1 = val;
  }

  void __set_passage2(const  ::thrift::adept::common::Passage& val) {
    passage2 = val;
  }

  bool operator == (const PassagePairProcessor_processAsync_args & rhs) const
  {
    if (!(passage1 == rhs.passage1))
      return false;
    if (!(passage2 == rhs.passage2))
      return false;
    return true;
  }
  bool operator != (const PassagePairProcessor_processAsync_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PassagePairProcessor_processAsync_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class PassagePairProcessor_processAsync_pargs {
 public:


  virtual ~PassagePairProcessor_processAsync_pargs() throw() {}

  const  ::thrift::adept::common::Passage* passage1;
  const  ::thrift::adept::common::Passage* passage2;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _PassagePairProcessor_processAsync_result__isset {
  _PassagePairProcessor_processAsync_result__isset() : success(false) {}
  bool success;
} _PassagePairProcessor_processAsync_result__isset;

class PassagePairProcessor_processAsync_result {
 public:

  PassagePairProcessor_processAsync_result() : success(0) {
  }

  virtual ~PassagePairProcessor_processAsync_result() throw() {}

  int64_t success;

  _PassagePairProcessor_processAsync_result__isset __isset;

  void __set_success(const int64_t val) {
    success = val;
  }

  bool operator == (const PassagePairProcessor_processAsync_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const PassagePairProcessor_processAsync_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PassagePairProcessor_processAsync_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _PassagePairProcessor_processAsync_presult__isset {
  _PassagePairProcessor_processAsync_presult__isset() : success(false) {}
  bool success;
} _PassagePairProcessor_processAsync_presult__isset;

class PassagePairProcessor_processAsync_presult {
 public:


  virtual ~PassagePairProcessor_processAsync_presult() throw() {}

  int64_t* success;

  _PassagePairProcessor_processAsync_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _PassagePairProcessor_tryGetResult_args__isset {
  _PassagePairProcessor_tryGetResult_args__isset() : requestId(false), metaContents(false) {}
  bool requestId;
  bool metaContents;
} _PassagePairProcessor_tryGetResult_args__isset;

class PassagePairProcessor_tryGetResult_args {
 public:

  PassagePairProcessor_tryGetResult_args() : requestId(0) {
  }

  virtual ~PassagePairProcessor_tryGetResult_args() throw() {}

  int64_t requestId;
  std::vector< ::thrift::adept::common::HltContentUnion>  metaContents;

  _PassagePairProcessor_tryGetResult_args__isset __isset;

  void __set_requestId(const int64_t val) {
    requestId = val;
  }

  void __set_metaContents(const std::vector< ::thrift::adept::common::HltContentUnion> & val) {
    metaContents = val;
  }

  bool operator == (const PassagePairProcessor_tryGetResult_args & rhs) const
  {
    if (!(requestId == rhs.requestId))
      return false;
    if (!(metaContents == rhs.metaContents))
      return false;
    return true;
  }
  bool operator != (const PassagePairProcessor_tryGetResult_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PassagePairProcessor_tryGetResult_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class PassagePairProcessor_tryGetResult_pargs {
 public:


  virtual ~PassagePairProcessor_tryGetResult_pargs() throw() {}

  const int64_t* requestId;
  const std::vector< ::thrift::adept::common::HltContentUnion> * metaContents;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _PassagePairProcessor_tryGetResult_result__isset {
  _PassagePairProcessor_tryGetResult_result__isset() : success(false) {}
  bool success;
} _PassagePairProcessor_tryGetResult_result__isset;

class PassagePairProcessor_tryGetResult_result {
 public:

  PassagePairProcessor_tryGetResult_result() : success(0) {
  }

  virtual ~PassagePairProcessor_tryGetResult_result() throw() {}

  bool success;

  _PassagePairProcessor_tryGetResult_result__isset __isset;

  void __set_success(const bool val) {
    success = val;
  }

  bool operator == (const PassagePairProcessor_tryGetResult_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const PassagePairProcessor_tryGetResult_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PassagePairProcessor_tryGetResult_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _PassagePairProcessor_tryGetResult_presult__isset {
  _PassagePairProcessor_tryGetResult_presult__isset() : success(false) {}
  bool success;
} _PassagePairProcessor_tryGetResult_presult__isset;

class PassagePairProcessor_tryGetResult_presult {
 public:


  virtual ~PassagePairProcessor_tryGetResult_presult() throw() {}

  bool* success;

  _PassagePairProcessor_tryGetResult_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class PassagePairProcessorClient : virtual public PassagePairProcessorIf {
 public:
  PassagePairProcessorClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  PassagePairProcessorClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
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
  void process(std::vector< ::thrift::adept::common::HltContentUnion> & _return, const  ::thrift::adept::common::Passage& passage1, const  ::thrift::adept::common::Passage& passage2);
  void send_process(const  ::thrift::adept::common::Passage& passage1, const  ::thrift::adept::common::Passage& passage2);
  void recv_process(std::vector< ::thrift::adept::common::HltContentUnion> & _return);
  int64_t processAsync(const  ::thrift::adept::common::Passage& passage1, const  ::thrift::adept::common::Passage& passage2);
  void send_processAsync(const  ::thrift::adept::common::Passage& passage1, const  ::thrift::adept::common::Passage& passage2);
  int64_t recv_processAsync();
  bool tryGetResult(const int64_t requestId, const std::vector< ::thrift::adept::common::HltContentUnion> & metaContents);
  void send_tryGetResult(const int64_t requestId, const std::vector< ::thrift::adept::common::HltContentUnion> & metaContents);
  bool recv_tryGetResult();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class PassagePairProcessorProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<PassagePairProcessorIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (PassagePairProcessorProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_process(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_processAsync(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_tryGetResult(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  PassagePairProcessorProcessor(boost::shared_ptr<PassagePairProcessorIf> iface) :
    iface_(iface) {
    processMap_["process"] = &PassagePairProcessorProcessor::process_process;
    processMap_["processAsync"] = &PassagePairProcessorProcessor::process_processAsync;
    processMap_["tryGetResult"] = &PassagePairProcessorProcessor::process_tryGetResult;
  }

  virtual ~PassagePairProcessorProcessor() {}
};

class PassagePairProcessorProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  PassagePairProcessorProcessorFactory(const ::boost::shared_ptr< PassagePairProcessorIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< PassagePairProcessorIfFactory > handlerFactory_;
};

class PassagePairProcessorMultiface : virtual public PassagePairProcessorIf {
 public:
  PassagePairProcessorMultiface(std::vector<boost::shared_ptr<PassagePairProcessorIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~PassagePairProcessorMultiface() {}
 protected:
  std::vector<boost::shared_ptr<PassagePairProcessorIf> > ifaces_;
  PassagePairProcessorMultiface() {}
  void add(boost::shared_ptr<PassagePairProcessorIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void process(std::vector< ::thrift::adept::common::HltContentUnion> & _return, const  ::thrift::adept::common::Passage& passage1, const  ::thrift::adept::common::Passage& passage2) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->process(_return, passage1, passage2);
    }
    ifaces_[i]->process(_return, passage1, passage2);
    return;
  }

  int64_t processAsync(const  ::thrift::adept::common::Passage& passage1, const  ::thrift::adept::common::Passage& passage2) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->processAsync(passage1, passage2);
    }
    return ifaces_[i]->processAsync(passage1, passage2);
  }

  bool tryGetResult(const int64_t requestId, const std::vector< ::thrift::adept::common::HltContentUnion> & metaContents) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->tryGetResult(requestId, metaContents);
    }
    return ifaces_[i]->tryGetResult(requestId, metaContents);
  }

};

}}} // namespace

#endif
