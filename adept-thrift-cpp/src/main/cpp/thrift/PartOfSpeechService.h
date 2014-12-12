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
#ifndef PartOfSpeechService_H
#define PartOfSpeechService_H

#include <thrift/TDispatchProcessor.h>
#include "common_types.h"
#include "ChunkService.h"

namespace thrift { namespace adept { namespace common {

class PartOfSpeechServiceIf : virtual public ChunkServiceIf {
 public:
  virtual ~PartOfSpeechServiceIf() {}
  virtual void getPartOfSpeechTag(Type& _return) = 0;
  virtual void getPosTag(Type& _return) = 0;
  virtual int64_t getSequenceId() = 0;
  virtual void setPosTag(const Type& posTag) = 0;
};

class PartOfSpeechServiceIfFactory : virtual public ChunkServiceIfFactory {
 public:
  typedef PartOfSpeechServiceIf Handler;

  virtual ~PartOfSpeechServiceIfFactory() {}

  virtual PartOfSpeechServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ItemServiceIf* /* handler */) = 0;
};

class PartOfSpeechServiceIfSingletonFactory : virtual public PartOfSpeechServiceIfFactory {
 public:
  PartOfSpeechServiceIfSingletonFactory(const boost::shared_ptr<PartOfSpeechServiceIf>& iface) : iface_(iface) {}
  virtual ~PartOfSpeechServiceIfSingletonFactory() {}

  virtual PartOfSpeechServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ItemServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<PartOfSpeechServiceIf> iface_;
};

class PartOfSpeechServiceNull : virtual public PartOfSpeechServiceIf , virtual public ChunkServiceNull {
 public:
  virtual ~PartOfSpeechServiceNull() {}
  void getPartOfSpeechTag(Type& /* _return */) {
    return;
  }
  void getPosTag(Type& /* _return */) {
    return;
  }
  int64_t getSequenceId() {
    int64_t _return = 0;
    return _return;
  }
  void setPosTag(const Type& /* posTag */) {
    return;
  }
};


class PartOfSpeechService_getPartOfSpeechTag_args {
 public:

  PartOfSpeechService_getPartOfSpeechTag_args() {
  }

  virtual ~PartOfSpeechService_getPartOfSpeechTag_args() throw() {}


  bool operator == (const PartOfSpeechService_getPartOfSpeechTag_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const PartOfSpeechService_getPartOfSpeechTag_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PartOfSpeechService_getPartOfSpeechTag_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class PartOfSpeechService_getPartOfSpeechTag_pargs {
 public:


  virtual ~PartOfSpeechService_getPartOfSpeechTag_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _PartOfSpeechService_getPartOfSpeechTag_result__isset {
  _PartOfSpeechService_getPartOfSpeechTag_result__isset() : success(false) {}
  bool success;
} _PartOfSpeechService_getPartOfSpeechTag_result__isset;

class PartOfSpeechService_getPartOfSpeechTag_result {
 public:

  PartOfSpeechService_getPartOfSpeechTag_result() {
  }

  virtual ~PartOfSpeechService_getPartOfSpeechTag_result() throw() {}

  Type success;

  _PartOfSpeechService_getPartOfSpeechTag_result__isset __isset;

  void __set_success(const Type& val) {
    success = val;
  }

  bool operator == (const PartOfSpeechService_getPartOfSpeechTag_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const PartOfSpeechService_getPartOfSpeechTag_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PartOfSpeechService_getPartOfSpeechTag_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _PartOfSpeechService_getPartOfSpeechTag_presult__isset {
  _PartOfSpeechService_getPartOfSpeechTag_presult__isset() : success(false) {}
  bool success;
} _PartOfSpeechService_getPartOfSpeechTag_presult__isset;

class PartOfSpeechService_getPartOfSpeechTag_presult {
 public:


  virtual ~PartOfSpeechService_getPartOfSpeechTag_presult() throw() {}

  Type* success;

  _PartOfSpeechService_getPartOfSpeechTag_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class PartOfSpeechService_getPosTag_args {
 public:

  PartOfSpeechService_getPosTag_args() {
  }

  virtual ~PartOfSpeechService_getPosTag_args() throw() {}


  bool operator == (const PartOfSpeechService_getPosTag_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const PartOfSpeechService_getPosTag_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PartOfSpeechService_getPosTag_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class PartOfSpeechService_getPosTag_pargs {
 public:


  virtual ~PartOfSpeechService_getPosTag_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _PartOfSpeechService_getPosTag_result__isset {
  _PartOfSpeechService_getPosTag_result__isset() : success(false) {}
  bool success;
} _PartOfSpeechService_getPosTag_result__isset;

class PartOfSpeechService_getPosTag_result {
 public:

  PartOfSpeechService_getPosTag_result() {
  }

  virtual ~PartOfSpeechService_getPosTag_result() throw() {}

  Type success;

  _PartOfSpeechService_getPosTag_result__isset __isset;

  void __set_success(const Type& val) {
    success = val;
  }

  bool operator == (const PartOfSpeechService_getPosTag_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const PartOfSpeechService_getPosTag_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PartOfSpeechService_getPosTag_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _PartOfSpeechService_getPosTag_presult__isset {
  _PartOfSpeechService_getPosTag_presult__isset() : success(false) {}
  bool success;
} _PartOfSpeechService_getPosTag_presult__isset;

class PartOfSpeechService_getPosTag_presult {
 public:


  virtual ~PartOfSpeechService_getPosTag_presult() throw() {}

  Type* success;

  _PartOfSpeechService_getPosTag_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class PartOfSpeechService_getSequenceId_args {
 public:

  PartOfSpeechService_getSequenceId_args() {
  }

  virtual ~PartOfSpeechService_getSequenceId_args() throw() {}


  bool operator == (const PartOfSpeechService_getSequenceId_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const PartOfSpeechService_getSequenceId_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PartOfSpeechService_getSequenceId_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class PartOfSpeechService_getSequenceId_pargs {
 public:


  virtual ~PartOfSpeechService_getSequenceId_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _PartOfSpeechService_getSequenceId_result__isset {
  _PartOfSpeechService_getSequenceId_result__isset() : success(false) {}
  bool success;
} _PartOfSpeechService_getSequenceId_result__isset;

class PartOfSpeechService_getSequenceId_result {
 public:

  PartOfSpeechService_getSequenceId_result() : success(0) {
  }

  virtual ~PartOfSpeechService_getSequenceId_result() throw() {}

  int64_t success;

  _PartOfSpeechService_getSequenceId_result__isset __isset;

  void __set_success(const int64_t val) {
    success = val;
  }

  bool operator == (const PartOfSpeechService_getSequenceId_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const PartOfSpeechService_getSequenceId_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PartOfSpeechService_getSequenceId_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _PartOfSpeechService_getSequenceId_presult__isset {
  _PartOfSpeechService_getSequenceId_presult__isset() : success(false) {}
  bool success;
} _PartOfSpeechService_getSequenceId_presult__isset;

class PartOfSpeechService_getSequenceId_presult {
 public:


  virtual ~PartOfSpeechService_getSequenceId_presult() throw() {}

  int64_t* success;

  _PartOfSpeechService_getSequenceId_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _PartOfSpeechService_setPosTag_args__isset {
  _PartOfSpeechService_setPosTag_args__isset() : posTag(false) {}
  bool posTag;
} _PartOfSpeechService_setPosTag_args__isset;

class PartOfSpeechService_setPosTag_args {
 public:

  PartOfSpeechService_setPosTag_args() {
  }

  virtual ~PartOfSpeechService_setPosTag_args() throw() {}

  Type posTag;

  _PartOfSpeechService_setPosTag_args__isset __isset;

  void __set_posTag(const Type& val) {
    posTag = val;
  }

  bool operator == (const PartOfSpeechService_setPosTag_args & rhs) const
  {
    if (!(posTag == rhs.posTag))
      return false;
    return true;
  }
  bool operator != (const PartOfSpeechService_setPosTag_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PartOfSpeechService_setPosTag_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class PartOfSpeechService_setPosTag_pargs {
 public:


  virtual ~PartOfSpeechService_setPosTag_pargs() throw() {}

  const Type* posTag;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class PartOfSpeechService_setPosTag_result {
 public:

  PartOfSpeechService_setPosTag_result() {
  }

  virtual ~PartOfSpeechService_setPosTag_result() throw() {}


  bool operator == (const PartOfSpeechService_setPosTag_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const PartOfSpeechService_setPosTag_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PartOfSpeechService_setPosTag_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class PartOfSpeechService_setPosTag_presult {
 public:


  virtual ~PartOfSpeechService_setPosTag_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class PartOfSpeechServiceClient : virtual public PartOfSpeechServiceIf, public ChunkServiceClient {
 public:
  PartOfSpeechServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    ChunkServiceClient(prot, prot) {}
  PartOfSpeechServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    ChunkServiceClient(iprot, oprot) {}
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void getPartOfSpeechTag(Type& _return);
  void send_getPartOfSpeechTag();
  void recv_getPartOfSpeechTag(Type& _return);
  void getPosTag(Type& _return);
  void send_getPosTag();
  void recv_getPosTag(Type& _return);
  int64_t getSequenceId();
  void send_getSequenceId();
  int64_t recv_getSequenceId();
  void setPosTag(const Type& posTag);
  void send_setPosTag(const Type& posTag);
  void recv_setPosTag();
};

class PartOfSpeechServiceProcessor : public ChunkServiceProcessor {
 protected:
  boost::shared_ptr<PartOfSpeechServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (PartOfSpeechServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_getPartOfSpeechTag(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getPosTag(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getSequenceId(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setPosTag(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  PartOfSpeechServiceProcessor(boost::shared_ptr<PartOfSpeechServiceIf> iface) :
    ChunkServiceProcessor(iface),
    iface_(iface) {
    processMap_["getPartOfSpeechTag"] = &PartOfSpeechServiceProcessor::process_getPartOfSpeechTag;
    processMap_["getPosTag"] = &PartOfSpeechServiceProcessor::process_getPosTag;
    processMap_["getSequenceId"] = &PartOfSpeechServiceProcessor::process_getSequenceId;
    processMap_["setPosTag"] = &PartOfSpeechServiceProcessor::process_setPosTag;
  }

  virtual ~PartOfSpeechServiceProcessor() {}
};

class PartOfSpeechServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  PartOfSpeechServiceProcessorFactory(const ::boost::shared_ptr< PartOfSpeechServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< PartOfSpeechServiceIfFactory > handlerFactory_;
};

class PartOfSpeechServiceMultiface : virtual public PartOfSpeechServiceIf, public ChunkServiceMultiface {
 public:
  PartOfSpeechServiceMultiface(std::vector<boost::shared_ptr<PartOfSpeechServiceIf> >& ifaces) : ifaces_(ifaces) {
    std::vector<boost::shared_ptr<PartOfSpeechServiceIf> >::iterator iter;
    for (iter = ifaces.begin(); iter != ifaces.end(); ++iter) {
      ChunkServiceMultiface::add(*iter);
    }
  }
  virtual ~PartOfSpeechServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<PartOfSpeechServiceIf> > ifaces_;
  PartOfSpeechServiceMultiface() {}
  void add(boost::shared_ptr<PartOfSpeechServiceIf> iface) {
    ChunkServiceMultiface::add(iface);
    ifaces_.push_back(iface);
  }
 public:
  void getPartOfSpeechTag(Type& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getPartOfSpeechTag(_return);
    }
    ifaces_[i]->getPartOfSpeechTag(_return);
    return;
  }

  void getPosTag(Type& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getPosTag(_return);
    }
    ifaces_[i]->getPosTag(_return);
    return;
  }

  int64_t getSequenceId() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getSequenceId();
    }
    return ifaces_[i]->getSequenceId();
  }

  void setPosTag(const Type& posTag) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setPosTag(posTag);
    }
    ifaces_[i]->setPosTag(posTag);
  }

};

}}} // namespace

#endif