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
#ifndef JointRelationCoreferenceService_H
#define JointRelationCoreferenceService_H

#include <thrift/TDispatchProcessor.h>
#include "common_types.h"
#include "ItemService.h"

namespace thrift { namespace adept { namespace common {

class JointRelationCoreferenceServiceIf : virtual public ItemServiceIf {
 public:
  virtual ~JointRelationCoreferenceServiceIf() {}
  virtual void getCoreference(Coreference& _return) = 0;
  virtual void getRelations(std::vector<Relation> & _return) = 0;
  virtual void setCoreference(const Coreference& coreference) = 0;
  virtual void setRelations(const std::vector<Relation> & relations) = 0;
};

class JointRelationCoreferenceServiceIfFactory : virtual public ItemServiceIfFactory {
 public:
  typedef JointRelationCoreferenceServiceIf Handler;

  virtual ~JointRelationCoreferenceServiceIfFactory() {}

  virtual JointRelationCoreferenceServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ItemServiceIf* /* handler */) = 0;
};

class JointRelationCoreferenceServiceIfSingletonFactory : virtual public JointRelationCoreferenceServiceIfFactory {
 public:
  JointRelationCoreferenceServiceIfSingletonFactory(const boost::shared_ptr<JointRelationCoreferenceServiceIf>& iface) : iface_(iface) {}
  virtual ~JointRelationCoreferenceServiceIfSingletonFactory() {}

  virtual JointRelationCoreferenceServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ItemServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<JointRelationCoreferenceServiceIf> iface_;
};

class JointRelationCoreferenceServiceNull : virtual public JointRelationCoreferenceServiceIf , virtual public ItemServiceNull {
 public:
  virtual ~JointRelationCoreferenceServiceNull() {}
  void getCoreference(Coreference& /* _return */) {
    return;
  }
  void getRelations(std::vector<Relation> & /* _return */) {
    return;
  }
  void setCoreference(const Coreference& /* coreference */) {
    return;
  }
  void setRelations(const std::vector<Relation> & /* relations */) {
    return;
  }
};


class JointRelationCoreferenceService_getCoreference_args {
 public:

  JointRelationCoreferenceService_getCoreference_args() {
  }

  virtual ~JointRelationCoreferenceService_getCoreference_args() throw() {}


  bool operator == (const JointRelationCoreferenceService_getCoreference_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const JointRelationCoreferenceService_getCoreference_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const JointRelationCoreferenceService_getCoreference_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class JointRelationCoreferenceService_getCoreference_pargs {
 public:


  virtual ~JointRelationCoreferenceService_getCoreference_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _JointRelationCoreferenceService_getCoreference_result__isset {
  _JointRelationCoreferenceService_getCoreference_result__isset() : success(false) {}
  bool success;
} _JointRelationCoreferenceService_getCoreference_result__isset;

class JointRelationCoreferenceService_getCoreference_result {
 public:

  JointRelationCoreferenceService_getCoreference_result() {
  }

  virtual ~JointRelationCoreferenceService_getCoreference_result() throw() {}

  Coreference success;

  _JointRelationCoreferenceService_getCoreference_result__isset __isset;

  void __set_success(const Coreference& val) {
    success = val;
  }

  bool operator == (const JointRelationCoreferenceService_getCoreference_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const JointRelationCoreferenceService_getCoreference_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const JointRelationCoreferenceService_getCoreference_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _JointRelationCoreferenceService_getCoreference_presult__isset {
  _JointRelationCoreferenceService_getCoreference_presult__isset() : success(false) {}
  bool success;
} _JointRelationCoreferenceService_getCoreference_presult__isset;

class JointRelationCoreferenceService_getCoreference_presult {
 public:


  virtual ~JointRelationCoreferenceService_getCoreference_presult() throw() {}

  Coreference* success;

  _JointRelationCoreferenceService_getCoreference_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class JointRelationCoreferenceService_getRelations_args {
 public:

  JointRelationCoreferenceService_getRelations_args() {
  }

  virtual ~JointRelationCoreferenceService_getRelations_args() throw() {}


  bool operator == (const JointRelationCoreferenceService_getRelations_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const JointRelationCoreferenceService_getRelations_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const JointRelationCoreferenceService_getRelations_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class JointRelationCoreferenceService_getRelations_pargs {
 public:


  virtual ~JointRelationCoreferenceService_getRelations_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _JointRelationCoreferenceService_getRelations_result__isset {
  _JointRelationCoreferenceService_getRelations_result__isset() : success(false) {}
  bool success;
} _JointRelationCoreferenceService_getRelations_result__isset;

class JointRelationCoreferenceService_getRelations_result {
 public:

  JointRelationCoreferenceService_getRelations_result() {
  }

  virtual ~JointRelationCoreferenceService_getRelations_result() throw() {}

  std::vector<Relation>  success;

  _JointRelationCoreferenceService_getRelations_result__isset __isset;

  void __set_success(const std::vector<Relation> & val) {
    success = val;
  }

  bool operator == (const JointRelationCoreferenceService_getRelations_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const JointRelationCoreferenceService_getRelations_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const JointRelationCoreferenceService_getRelations_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _JointRelationCoreferenceService_getRelations_presult__isset {
  _JointRelationCoreferenceService_getRelations_presult__isset() : success(false) {}
  bool success;
} _JointRelationCoreferenceService_getRelations_presult__isset;

class JointRelationCoreferenceService_getRelations_presult {
 public:


  virtual ~JointRelationCoreferenceService_getRelations_presult() throw() {}

  std::vector<Relation> * success;

  _JointRelationCoreferenceService_getRelations_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _JointRelationCoreferenceService_setCoreference_args__isset {
  _JointRelationCoreferenceService_setCoreference_args__isset() : coreference(false) {}
  bool coreference;
} _JointRelationCoreferenceService_setCoreference_args__isset;

class JointRelationCoreferenceService_setCoreference_args {
 public:

  JointRelationCoreferenceService_setCoreference_args() {
  }

  virtual ~JointRelationCoreferenceService_setCoreference_args() throw() {}

  Coreference coreference;

  _JointRelationCoreferenceService_setCoreference_args__isset __isset;

  void __set_coreference(const Coreference& val) {
    coreference = val;
  }

  bool operator == (const JointRelationCoreferenceService_setCoreference_args & rhs) const
  {
    if (!(coreference == rhs.coreference))
      return false;
    return true;
  }
  bool operator != (const JointRelationCoreferenceService_setCoreference_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const JointRelationCoreferenceService_setCoreference_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class JointRelationCoreferenceService_setCoreference_pargs {
 public:


  virtual ~JointRelationCoreferenceService_setCoreference_pargs() throw() {}

  const Coreference* coreference;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class JointRelationCoreferenceService_setCoreference_result {
 public:

  JointRelationCoreferenceService_setCoreference_result() {
  }

  virtual ~JointRelationCoreferenceService_setCoreference_result() throw() {}


  bool operator == (const JointRelationCoreferenceService_setCoreference_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const JointRelationCoreferenceService_setCoreference_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const JointRelationCoreferenceService_setCoreference_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class JointRelationCoreferenceService_setCoreference_presult {
 public:


  virtual ~JointRelationCoreferenceService_setCoreference_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _JointRelationCoreferenceService_setRelations_args__isset {
  _JointRelationCoreferenceService_setRelations_args__isset() : relations(false) {}
  bool relations;
} _JointRelationCoreferenceService_setRelations_args__isset;

class JointRelationCoreferenceService_setRelations_args {
 public:

  JointRelationCoreferenceService_setRelations_args() {
  }

  virtual ~JointRelationCoreferenceService_setRelations_args() throw() {}

  std::vector<Relation>  relations;

  _JointRelationCoreferenceService_setRelations_args__isset __isset;

  void __set_relations(const std::vector<Relation> & val) {
    relations = val;
  }

  bool operator == (const JointRelationCoreferenceService_setRelations_args & rhs) const
  {
    if (!(relations == rhs.relations))
      return false;
    return true;
  }
  bool operator != (const JointRelationCoreferenceService_setRelations_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const JointRelationCoreferenceService_setRelations_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class JointRelationCoreferenceService_setRelations_pargs {
 public:


  virtual ~JointRelationCoreferenceService_setRelations_pargs() throw() {}

  const std::vector<Relation> * relations;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class JointRelationCoreferenceService_setRelations_result {
 public:

  JointRelationCoreferenceService_setRelations_result() {
  }

  virtual ~JointRelationCoreferenceService_setRelations_result() throw() {}


  bool operator == (const JointRelationCoreferenceService_setRelations_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const JointRelationCoreferenceService_setRelations_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const JointRelationCoreferenceService_setRelations_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class JointRelationCoreferenceService_setRelations_presult {
 public:


  virtual ~JointRelationCoreferenceService_setRelations_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class JointRelationCoreferenceServiceClient : virtual public JointRelationCoreferenceServiceIf, public ItemServiceClient {
 public:
  JointRelationCoreferenceServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    ItemServiceClient(prot, prot) {}
  JointRelationCoreferenceServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    ItemServiceClient(iprot, oprot) {}
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void getCoreference(Coreference& _return);
  void send_getCoreference();
  void recv_getCoreference(Coreference& _return);
  void getRelations(std::vector<Relation> & _return);
  void send_getRelations();
  void recv_getRelations(std::vector<Relation> & _return);
  void setCoreference(const Coreference& coreference);
  void send_setCoreference(const Coreference& coreference);
  void recv_setCoreference();
  void setRelations(const std::vector<Relation> & relations);
  void send_setRelations(const std::vector<Relation> & relations);
  void recv_setRelations();
};

class JointRelationCoreferenceServiceProcessor : public ItemServiceProcessor {
 protected:
  boost::shared_ptr<JointRelationCoreferenceServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (JointRelationCoreferenceServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_getCoreference(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getRelations(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setCoreference(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setRelations(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  JointRelationCoreferenceServiceProcessor(boost::shared_ptr<JointRelationCoreferenceServiceIf> iface) :
    ItemServiceProcessor(iface),
    iface_(iface) {
    processMap_["getCoreference"] = &JointRelationCoreferenceServiceProcessor::process_getCoreference;
    processMap_["getRelations"] = &JointRelationCoreferenceServiceProcessor::process_getRelations;
    processMap_["setCoreference"] = &JointRelationCoreferenceServiceProcessor::process_setCoreference;
    processMap_["setRelations"] = &JointRelationCoreferenceServiceProcessor::process_setRelations;
  }

  virtual ~JointRelationCoreferenceServiceProcessor() {}
};

class JointRelationCoreferenceServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  JointRelationCoreferenceServiceProcessorFactory(const ::boost::shared_ptr< JointRelationCoreferenceServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< JointRelationCoreferenceServiceIfFactory > handlerFactory_;
};

class JointRelationCoreferenceServiceMultiface : virtual public JointRelationCoreferenceServiceIf, public ItemServiceMultiface {
 public:
  JointRelationCoreferenceServiceMultiface(std::vector<boost::shared_ptr<JointRelationCoreferenceServiceIf> >& ifaces) : ifaces_(ifaces) {
    std::vector<boost::shared_ptr<JointRelationCoreferenceServiceIf> >::iterator iter;
    for (iter = ifaces.begin(); iter != ifaces.end(); ++iter) {
      ItemServiceMultiface::add(*iter);
    }
  }
  virtual ~JointRelationCoreferenceServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<JointRelationCoreferenceServiceIf> > ifaces_;
  JointRelationCoreferenceServiceMultiface() {}
  void add(boost::shared_ptr<JointRelationCoreferenceServiceIf> iface) {
    ItemServiceMultiface::add(iface);
    ifaces_.push_back(iface);
  }
 public:
  void getCoreference(Coreference& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getCoreference(_return);
    }
    ifaces_[i]->getCoreference(_return);
    return;
  }

  void getRelations(std::vector<Relation> & _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getRelations(_return);
    }
    ifaces_[i]->getRelations(_return);
    return;
  }

  void setCoreference(const Coreference& coreference) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setCoreference(coreference);
    }
    ifaces_[i]->setCoreference(coreference);
  }

  void setRelations(const std::vector<Relation> & relations) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setRelations(relations);
    }
    ifaces_[i]->setRelations(relations);
  }

};

}}} // namespace

#endif