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
#ifndef CorpusService_H
#define CorpusService_H

#include <thrift/TDispatchProcessor.h>
#include "common_types.h"

namespace thrift { namespace adept { namespace common {

class CorpusServiceIf {
 public:
  virtual ~CorpusServiceIf() {}
  virtual void getCorpusId(std::string& _return) = 0;
  virtual void getId(ID& _return) = 0;
  virtual void getIdString(std::string& _return) = 0;
  virtual void getName(std::string& _return) = 0;
  virtual void getType(std::string& _return) = 0;
  virtual void getUri(std::string& _return) = 0;
};

class CorpusServiceIfFactory {
 public:
  typedef CorpusServiceIf Handler;

  virtual ~CorpusServiceIfFactory() {}

  virtual CorpusServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(CorpusServiceIf* /* handler */) = 0;
};

class CorpusServiceIfSingletonFactory : virtual public CorpusServiceIfFactory {
 public:
  CorpusServiceIfSingletonFactory(const boost::shared_ptr<CorpusServiceIf>& iface) : iface_(iface) {}
  virtual ~CorpusServiceIfSingletonFactory() {}

  virtual CorpusServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(CorpusServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<CorpusServiceIf> iface_;
};

class CorpusServiceNull : virtual public CorpusServiceIf {
 public:
  virtual ~CorpusServiceNull() {}
  void getCorpusId(std::string& /* _return */) {
    return;
  }
  void getId(ID& /* _return */) {
    return;
  }
  void getIdString(std::string& /* _return */) {
    return;
  }
  void getName(std::string& /* _return */) {
    return;
  }
  void getType(std::string& /* _return */) {
    return;
  }
  void getUri(std::string& /* _return */) {
    return;
  }
};


class CorpusService_getCorpusId_args {
 public:

  CorpusService_getCorpusId_args() {
  }

  virtual ~CorpusService_getCorpusId_args() throw() {}


  bool operator == (const CorpusService_getCorpusId_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const CorpusService_getCorpusId_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const CorpusService_getCorpusId_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class CorpusService_getCorpusId_pargs {
 public:


  virtual ~CorpusService_getCorpusId_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _CorpusService_getCorpusId_result__isset {
  _CorpusService_getCorpusId_result__isset() : success(false) {}
  bool success;
} _CorpusService_getCorpusId_result__isset;

class CorpusService_getCorpusId_result {
 public:

  CorpusService_getCorpusId_result() : success() {
  }

  virtual ~CorpusService_getCorpusId_result() throw() {}

  std::string success;

  _CorpusService_getCorpusId_result__isset __isset;

  void __set_success(const std::string& val) {
    success = val;
  }

  bool operator == (const CorpusService_getCorpusId_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const CorpusService_getCorpusId_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const CorpusService_getCorpusId_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _CorpusService_getCorpusId_presult__isset {
  _CorpusService_getCorpusId_presult__isset() : success(false) {}
  bool success;
} _CorpusService_getCorpusId_presult__isset;

class CorpusService_getCorpusId_presult {
 public:


  virtual ~CorpusService_getCorpusId_presult() throw() {}

  std::string* success;

  _CorpusService_getCorpusId_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class CorpusService_getId_args {
 public:

  CorpusService_getId_args() {
  }

  virtual ~CorpusService_getId_args() throw() {}


  bool operator == (const CorpusService_getId_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const CorpusService_getId_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const CorpusService_getId_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class CorpusService_getId_pargs {
 public:


  virtual ~CorpusService_getId_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _CorpusService_getId_result__isset {
  _CorpusService_getId_result__isset() : success(false) {}
  bool success;
} _CorpusService_getId_result__isset;

class CorpusService_getId_result {
 public:

  CorpusService_getId_result() {
  }

  virtual ~CorpusService_getId_result() throw() {}

  ID success;

  _CorpusService_getId_result__isset __isset;

  void __set_success(const ID& val) {
    success = val;
  }

  bool operator == (const CorpusService_getId_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const CorpusService_getId_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const CorpusService_getId_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _CorpusService_getId_presult__isset {
  _CorpusService_getId_presult__isset() : success(false) {}
  bool success;
} _CorpusService_getId_presult__isset;

class CorpusService_getId_presult {
 public:


  virtual ~CorpusService_getId_presult() throw() {}

  ID* success;

  _CorpusService_getId_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class CorpusService_getIdString_args {
 public:

  CorpusService_getIdString_args() {
  }

  virtual ~CorpusService_getIdString_args() throw() {}


  bool operator == (const CorpusService_getIdString_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const CorpusService_getIdString_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const CorpusService_getIdString_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class CorpusService_getIdString_pargs {
 public:


  virtual ~CorpusService_getIdString_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _CorpusService_getIdString_result__isset {
  _CorpusService_getIdString_result__isset() : success(false) {}
  bool success;
} _CorpusService_getIdString_result__isset;

class CorpusService_getIdString_result {
 public:

  CorpusService_getIdString_result() : success() {
  }

  virtual ~CorpusService_getIdString_result() throw() {}

  std::string success;

  _CorpusService_getIdString_result__isset __isset;

  void __set_success(const std::string& val) {
    success = val;
  }

  bool operator == (const CorpusService_getIdString_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const CorpusService_getIdString_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const CorpusService_getIdString_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _CorpusService_getIdString_presult__isset {
  _CorpusService_getIdString_presult__isset() : success(false) {}
  bool success;
} _CorpusService_getIdString_presult__isset;

class CorpusService_getIdString_presult {
 public:


  virtual ~CorpusService_getIdString_presult() throw() {}

  std::string* success;

  _CorpusService_getIdString_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class CorpusService_getName_args {
 public:

  CorpusService_getName_args() {
  }

  virtual ~CorpusService_getName_args() throw() {}


  bool operator == (const CorpusService_getName_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const CorpusService_getName_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const CorpusService_getName_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class CorpusService_getName_pargs {
 public:


  virtual ~CorpusService_getName_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _CorpusService_getName_result__isset {
  _CorpusService_getName_result__isset() : success(false) {}
  bool success;
} _CorpusService_getName_result__isset;

class CorpusService_getName_result {
 public:

  CorpusService_getName_result() : success() {
  }

  virtual ~CorpusService_getName_result() throw() {}

  std::string success;

  _CorpusService_getName_result__isset __isset;

  void __set_success(const std::string& val) {
    success = val;
  }

  bool operator == (const CorpusService_getName_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const CorpusService_getName_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const CorpusService_getName_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _CorpusService_getName_presult__isset {
  _CorpusService_getName_presult__isset() : success(false) {}
  bool success;
} _CorpusService_getName_presult__isset;

class CorpusService_getName_presult {
 public:


  virtual ~CorpusService_getName_presult() throw() {}

  std::string* success;

  _CorpusService_getName_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class CorpusService_getType_args {
 public:

  CorpusService_getType_args() {
  }

  virtual ~CorpusService_getType_args() throw() {}


  bool operator == (const CorpusService_getType_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const CorpusService_getType_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const CorpusService_getType_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class CorpusService_getType_pargs {
 public:


  virtual ~CorpusService_getType_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _CorpusService_getType_result__isset {
  _CorpusService_getType_result__isset() : success(false) {}
  bool success;
} _CorpusService_getType_result__isset;

class CorpusService_getType_result {
 public:

  CorpusService_getType_result() : success() {
  }

  virtual ~CorpusService_getType_result() throw() {}

  std::string success;

  _CorpusService_getType_result__isset __isset;

  void __set_success(const std::string& val) {
    success = val;
  }

  bool operator == (const CorpusService_getType_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const CorpusService_getType_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const CorpusService_getType_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _CorpusService_getType_presult__isset {
  _CorpusService_getType_presult__isset() : success(false) {}
  bool success;
} _CorpusService_getType_presult__isset;

class CorpusService_getType_presult {
 public:


  virtual ~CorpusService_getType_presult() throw() {}

  std::string* success;

  _CorpusService_getType_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class CorpusService_getUri_args {
 public:

  CorpusService_getUri_args() {
  }

  virtual ~CorpusService_getUri_args() throw() {}


  bool operator == (const CorpusService_getUri_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const CorpusService_getUri_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const CorpusService_getUri_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class CorpusService_getUri_pargs {
 public:


  virtual ~CorpusService_getUri_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _CorpusService_getUri_result__isset {
  _CorpusService_getUri_result__isset() : success(false) {}
  bool success;
} _CorpusService_getUri_result__isset;

class CorpusService_getUri_result {
 public:

  CorpusService_getUri_result() : success() {
  }

  virtual ~CorpusService_getUri_result() throw() {}

  std::string success;

  _CorpusService_getUri_result__isset __isset;

  void __set_success(const std::string& val) {
    success = val;
  }

  bool operator == (const CorpusService_getUri_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const CorpusService_getUri_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const CorpusService_getUri_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _CorpusService_getUri_presult__isset {
  _CorpusService_getUri_presult__isset() : success(false) {}
  bool success;
} _CorpusService_getUri_presult__isset;

class CorpusService_getUri_presult {
 public:


  virtual ~CorpusService_getUri_presult() throw() {}

  std::string* success;

  _CorpusService_getUri_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class CorpusServiceClient : virtual public CorpusServiceIf {
 public:
  CorpusServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  CorpusServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
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
  void getCorpusId(std::string& _return);
  void send_getCorpusId();
  void recv_getCorpusId(std::string& _return);
  void getId(ID& _return);
  void send_getId();
  void recv_getId(ID& _return);
  void getIdString(std::string& _return);
  void send_getIdString();
  void recv_getIdString(std::string& _return);
  void getName(std::string& _return);
  void send_getName();
  void recv_getName(std::string& _return);
  void getType(std::string& _return);
  void send_getType();
  void recv_getType(std::string& _return);
  void getUri(std::string& _return);
  void send_getUri();
  void recv_getUri(std::string& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class CorpusServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<CorpusServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (CorpusServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_getCorpusId(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getId(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getIdString(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getName(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getType(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getUri(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  CorpusServiceProcessor(boost::shared_ptr<CorpusServiceIf> iface) :
    iface_(iface) {
    processMap_["getCorpusId"] = &CorpusServiceProcessor::process_getCorpusId;
    processMap_["getId"] = &CorpusServiceProcessor::process_getId;
    processMap_["getIdString"] = &CorpusServiceProcessor::process_getIdString;
    processMap_["getName"] = &CorpusServiceProcessor::process_getName;
    processMap_["getType"] = &CorpusServiceProcessor::process_getType;
    processMap_["getUri"] = &CorpusServiceProcessor::process_getUri;
  }

  virtual ~CorpusServiceProcessor() {}
};

class CorpusServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  CorpusServiceProcessorFactory(const ::boost::shared_ptr< CorpusServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< CorpusServiceIfFactory > handlerFactory_;
};

class CorpusServiceMultiface : virtual public CorpusServiceIf {
 public:
  CorpusServiceMultiface(std::vector<boost::shared_ptr<CorpusServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~CorpusServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<CorpusServiceIf> > ifaces_;
  CorpusServiceMultiface() {}
  void add(boost::shared_ptr<CorpusServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void getCorpusId(std::string& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getCorpusId(_return);
    }
    ifaces_[i]->getCorpusId(_return);
    return;
  }

  void getId(ID& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getId(_return);
    }
    ifaces_[i]->getId(_return);
    return;
  }

  void getIdString(std::string& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getIdString(_return);
    }
    ifaces_[i]->getIdString(_return);
    return;
  }

  void getName(std::string& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getName(_return);
    }
    ifaces_[i]->getName(_return);
    return;
  }

  void getType(std::string& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getType(_return);
    }
    ifaces_[i]->getType(_return);
    return;
  }

  void getUri(std::string& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getUri(_return);
    }
    ifaces_[i]->getUri(_return);
    return;
  }

};

}}} // namespace

#endif
