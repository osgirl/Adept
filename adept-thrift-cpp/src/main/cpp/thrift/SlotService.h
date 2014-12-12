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
#ifndef SlotService_H
#define SlotService_H

#include <thrift/TDispatchProcessor.h>
#include "common_types.h"

namespace thrift { namespace adept { namespace common {

class SlotServiceIf {
 public:
  virtual ~SlotServiceIf() {}
  virtual void getSlot(std::string& _return) = 0;
  virtual int64_t getSlotId() = 0;
};

class SlotServiceIfFactory {
 public:
  typedef SlotServiceIf Handler;

  virtual ~SlotServiceIfFactory() {}

  virtual SlotServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(SlotServiceIf* /* handler */) = 0;
};

class SlotServiceIfSingletonFactory : virtual public SlotServiceIfFactory {
 public:
  SlotServiceIfSingletonFactory(const boost::shared_ptr<SlotServiceIf>& iface) : iface_(iface) {}
  virtual ~SlotServiceIfSingletonFactory() {}

  virtual SlotServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(SlotServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<SlotServiceIf> iface_;
};

class SlotServiceNull : virtual public SlotServiceIf {
 public:
  virtual ~SlotServiceNull() {}
  void getSlot(std::string& /* _return */) {
    return;
  }
  int64_t getSlotId() {
    int64_t _return = 0;
    return _return;
  }
};


class SlotService_getSlot_args {
 public:

  SlotService_getSlot_args() {
  }

  virtual ~SlotService_getSlot_args() throw() {}


  bool operator == (const SlotService_getSlot_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const SlotService_getSlot_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SlotService_getSlot_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class SlotService_getSlot_pargs {
 public:


  virtual ~SlotService_getSlot_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _SlotService_getSlot_result__isset {
  _SlotService_getSlot_result__isset() : success(false) {}
  bool success;
} _SlotService_getSlot_result__isset;

class SlotService_getSlot_result {
 public:

  SlotService_getSlot_result() : success() {
  }

  virtual ~SlotService_getSlot_result() throw() {}

  std::string success;

  _SlotService_getSlot_result__isset __isset;

  void __set_success(const std::string& val) {
    success = val;
  }

  bool operator == (const SlotService_getSlot_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const SlotService_getSlot_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SlotService_getSlot_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _SlotService_getSlot_presult__isset {
  _SlotService_getSlot_presult__isset() : success(false) {}
  bool success;
} _SlotService_getSlot_presult__isset;

class SlotService_getSlot_presult {
 public:


  virtual ~SlotService_getSlot_presult() throw() {}

  std::string* success;

  _SlotService_getSlot_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class SlotService_getSlotId_args {
 public:

  SlotService_getSlotId_args() {
  }

  virtual ~SlotService_getSlotId_args() throw() {}


  bool operator == (const SlotService_getSlotId_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const SlotService_getSlotId_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SlotService_getSlotId_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class SlotService_getSlotId_pargs {
 public:


  virtual ~SlotService_getSlotId_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _SlotService_getSlotId_result__isset {
  _SlotService_getSlotId_result__isset() : success(false) {}
  bool success;
} _SlotService_getSlotId_result__isset;

class SlotService_getSlotId_result {
 public:

  SlotService_getSlotId_result() : success(0) {
  }

  virtual ~SlotService_getSlotId_result() throw() {}

  int64_t success;

  _SlotService_getSlotId_result__isset __isset;

  void __set_success(const int64_t val) {
    success = val;
  }

  bool operator == (const SlotService_getSlotId_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const SlotService_getSlotId_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SlotService_getSlotId_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _SlotService_getSlotId_presult__isset {
  _SlotService_getSlotId_presult__isset() : success(false) {}
  bool success;
} _SlotService_getSlotId_presult__isset;

class SlotService_getSlotId_presult {
 public:


  virtual ~SlotService_getSlotId_presult() throw() {}

  int64_t* success;

  _SlotService_getSlotId_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class SlotServiceClient : virtual public SlotServiceIf {
 public:
  SlotServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  SlotServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
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
  void getSlot(std::string& _return);
  void send_getSlot();
  void recv_getSlot(std::string& _return);
  int64_t getSlotId();
  void send_getSlotId();
  int64_t recv_getSlotId();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class SlotServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<SlotServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (SlotServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_getSlot(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getSlotId(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  SlotServiceProcessor(boost::shared_ptr<SlotServiceIf> iface) :
    iface_(iface) {
    processMap_["getSlot"] = &SlotServiceProcessor::process_getSlot;
    processMap_["getSlotId"] = &SlotServiceProcessor::process_getSlotId;
  }

  virtual ~SlotServiceProcessor() {}
};

class SlotServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  SlotServiceProcessorFactory(const ::boost::shared_ptr< SlotServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< SlotServiceIfFactory > handlerFactory_;
};

class SlotServiceMultiface : virtual public SlotServiceIf {
 public:
  SlotServiceMultiface(std::vector<boost::shared_ptr<SlotServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~SlotServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<SlotServiceIf> > ifaces_;
  SlotServiceMultiface() {}
  void add(boost::shared_ptr<SlotServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void getSlot(std::string& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getSlot(_return);
    }
    ifaces_[i]->getSlot(_return);
    return;
  }

  int64_t getSlotId() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getSlotId();
    }
    return ifaces_[i]->getSlotId();
  }

};

}}} // namespace

#endif
