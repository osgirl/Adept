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
#ifndef IDService_H
#define IDService_H

#include <thrift/TDispatchProcessor.h>
#include "common_types.h"

namespace thrift { namespace adept { namespace common {

class IDServiceIf {
 public:
  virtual ~IDServiceIf() {}
  virtual void getId(std::string& _return) = 0;
  virtual void getIdString(std::string& _return) = 0;
};

class IDServiceIfFactory {
 public:
  typedef IDServiceIf Handler;

  virtual ~IDServiceIfFactory() {}

  virtual IDServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(IDServiceIf* /* handler */) = 0;
};

class IDServiceIfSingletonFactory : virtual public IDServiceIfFactory {
 public:
  IDServiceIfSingletonFactory(const boost::shared_ptr<IDServiceIf>& iface) : iface_(iface) {}
  virtual ~IDServiceIfSingletonFactory() {}

  virtual IDServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(IDServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<IDServiceIf> iface_;
};

class IDServiceNull : virtual public IDServiceIf {
 public:
  virtual ~IDServiceNull() {}
  void getId(std::string& /* _return */) {
    return;
  }
  void getIdString(std::string& /* _return */) {
    return;
  }
};


class IDService_getId_args {
 public:

  IDService_getId_args() {
  }

  virtual ~IDService_getId_args() throw() {}


  bool operator == (const IDService_getId_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const IDService_getId_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const IDService_getId_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class IDService_getId_pargs {
 public:


  virtual ~IDService_getId_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _IDService_getId_result__isset {
  _IDService_getId_result__isset() : success(false) {}
  bool success;
} _IDService_getId_result__isset;

class IDService_getId_result {
 public:

  IDService_getId_result() : success() {
  }

  virtual ~IDService_getId_result() throw() {}

  std::string success;

  _IDService_getId_result__isset __isset;

  void __set_success(const std::string& val) {
    success = val;
  }

  bool operator == (const IDService_getId_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const IDService_getId_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const IDService_getId_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _IDService_getId_presult__isset {
  _IDService_getId_presult__isset() : success(false) {}
  bool success;
} _IDService_getId_presult__isset;

class IDService_getId_presult {
 public:


  virtual ~IDService_getId_presult() throw() {}

  std::string* success;

  _IDService_getId_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class IDService_getIdString_args {
 public:

  IDService_getIdString_args() {
  }

  virtual ~IDService_getIdString_args() throw() {}


  bool operator == (const IDService_getIdString_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const IDService_getIdString_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const IDService_getIdString_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class IDService_getIdString_pargs {
 public:


  virtual ~IDService_getIdString_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _IDService_getIdString_result__isset {
  _IDService_getIdString_result__isset() : success(false) {}
  bool success;
} _IDService_getIdString_result__isset;

class IDService_getIdString_result {
 public:

  IDService_getIdString_result() : success() {
  }

  virtual ~IDService_getIdString_result() throw() {}

  std::string success;

  _IDService_getIdString_result__isset __isset;

  void __set_success(const std::string& val) {
    success = val;
  }

  bool operator == (const IDService_getIdString_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const IDService_getIdString_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const IDService_getIdString_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _IDService_getIdString_presult__isset {
  _IDService_getIdString_presult__isset() : success(false) {}
  bool success;
} _IDService_getIdString_presult__isset;

class IDService_getIdString_presult {
 public:


  virtual ~IDService_getIdString_presult() throw() {}

  std::string* success;

  _IDService_getIdString_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class IDServiceClient : virtual public IDServiceIf {
 public:
  IDServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  IDServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
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
  void getId(std::string& _return);
  void send_getId();
  void recv_getId(std::string& _return);
  void getIdString(std::string& _return);
  void send_getIdString();
  void recv_getIdString(std::string& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class IDServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<IDServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (IDServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_getId(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getIdString(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  IDServiceProcessor(boost::shared_ptr<IDServiceIf> iface) :
    iface_(iface) {
    processMap_["getId"] = &IDServiceProcessor::process_getId;
    processMap_["getIdString"] = &IDServiceProcessor::process_getIdString;
  }

  virtual ~IDServiceProcessor() {}
};

class IDServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  IDServiceProcessorFactory(const ::boost::shared_ptr< IDServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< IDServiceIfFactory > handlerFactory_;
};

class IDServiceMultiface : virtual public IDServiceIf {
 public:
  IDServiceMultiface(std::vector<boost::shared_ptr<IDServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~IDServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<IDServiceIf> > ifaces_;
  IDServiceMultiface() {}
  void add(boost::shared_ptr<IDServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void getId(std::string& _return) {
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

};

}}} // namespace

#endif
