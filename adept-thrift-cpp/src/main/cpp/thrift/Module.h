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
#ifndef Module_H
#define Module_H

#include <thrift/TDispatchProcessor.h>
#include "module_types.h"

namespace thrift { namespace adept { namespace module {

class ModuleIf {
 public:
  virtual ~ModuleIf() {}
  virtual void activate(const std::string& configFilePath) = 0;
  virtual void deactivate() = 0;
  virtual void getModuleConfig(ModuleConfig& _return) = 0;
  virtual void getModuleTraits(ModuleTraits& _return) = 0;
};

class ModuleIfFactory {
 public:
  typedef ModuleIf Handler;

  virtual ~ModuleIfFactory() {}

  virtual ModuleIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ModuleIf* /* handler */) = 0;
};

class ModuleIfSingletonFactory : virtual public ModuleIfFactory {
 public:
  ModuleIfSingletonFactory(const boost::shared_ptr<ModuleIf>& iface) : iface_(iface) {}
  virtual ~ModuleIfSingletonFactory() {}

  virtual ModuleIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ModuleIf* /* handler */) {}

 protected:
  boost::shared_ptr<ModuleIf> iface_;
};

class ModuleNull : virtual public ModuleIf {
 public:
  virtual ~ModuleNull() {}
  void activate(const std::string& /* configFilePath */) {
    return;
  }
  void deactivate() {
    return;
  }
  void getModuleConfig(ModuleConfig& /* _return */) {
    return;
  }
  void getModuleTraits(ModuleTraits& /* _return */) {
    return;
  }
};

typedef struct _Module_activate_args__isset {
  _Module_activate_args__isset() : configFilePath(false) {}
  bool configFilePath;
} _Module_activate_args__isset;

class Module_activate_args {
 public:

  Module_activate_args() : configFilePath() {
  }

  virtual ~Module_activate_args() throw() {}

  std::string configFilePath;

  _Module_activate_args__isset __isset;

  void __set_configFilePath(const std::string& val) {
    configFilePath = val;
  }

  bool operator == (const Module_activate_args & rhs) const
  {
    if (!(configFilePath == rhs.configFilePath))
      return false;
    return true;
  }
  bool operator != (const Module_activate_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Module_activate_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Module_activate_pargs {
 public:


  virtual ~Module_activate_pargs() throw() {}

  const std::string* configFilePath;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Module_activate_result {
 public:

  Module_activate_result() {
  }

  virtual ~Module_activate_result() throw() {}


  bool operator == (const Module_activate_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Module_activate_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Module_activate_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Module_activate_presult {
 public:


  virtual ~Module_activate_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class Module_deactivate_args {
 public:

  Module_deactivate_args() {
  }

  virtual ~Module_deactivate_args() throw() {}


  bool operator == (const Module_deactivate_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Module_deactivate_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Module_deactivate_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Module_deactivate_pargs {
 public:


  virtual ~Module_deactivate_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Module_deactivate_result {
 public:

  Module_deactivate_result() {
  }

  virtual ~Module_deactivate_result() throw() {}


  bool operator == (const Module_deactivate_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Module_deactivate_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Module_deactivate_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Module_deactivate_presult {
 public:


  virtual ~Module_deactivate_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class Module_getModuleConfig_args {
 public:

  Module_getModuleConfig_args() {
  }

  virtual ~Module_getModuleConfig_args() throw() {}


  bool operator == (const Module_getModuleConfig_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Module_getModuleConfig_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Module_getModuleConfig_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Module_getModuleConfig_pargs {
 public:


  virtual ~Module_getModuleConfig_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Module_getModuleConfig_result__isset {
  _Module_getModuleConfig_result__isset() : success(false) {}
  bool success;
} _Module_getModuleConfig_result__isset;

class Module_getModuleConfig_result {
 public:

  Module_getModuleConfig_result() {
  }

  virtual ~Module_getModuleConfig_result() throw() {}

  ModuleConfig success;

  _Module_getModuleConfig_result__isset __isset;

  void __set_success(const ModuleConfig& val) {
    success = val;
  }

  bool operator == (const Module_getModuleConfig_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Module_getModuleConfig_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Module_getModuleConfig_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Module_getModuleConfig_presult__isset {
  _Module_getModuleConfig_presult__isset() : success(false) {}
  bool success;
} _Module_getModuleConfig_presult__isset;

class Module_getModuleConfig_presult {
 public:


  virtual ~Module_getModuleConfig_presult() throw() {}

  ModuleConfig* success;

  _Module_getModuleConfig_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class Module_getModuleTraits_args {
 public:

  Module_getModuleTraits_args() {
  }

  virtual ~Module_getModuleTraits_args() throw() {}


  bool operator == (const Module_getModuleTraits_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Module_getModuleTraits_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Module_getModuleTraits_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Module_getModuleTraits_pargs {
 public:


  virtual ~Module_getModuleTraits_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Module_getModuleTraits_result__isset {
  _Module_getModuleTraits_result__isset() : success(false) {}
  bool success;
} _Module_getModuleTraits_result__isset;

class Module_getModuleTraits_result {
 public:

  Module_getModuleTraits_result() {
  }

  virtual ~Module_getModuleTraits_result() throw() {}

  ModuleTraits success;

  _Module_getModuleTraits_result__isset __isset;

  void __set_success(const ModuleTraits& val) {
    success = val;
  }

  bool operator == (const Module_getModuleTraits_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Module_getModuleTraits_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Module_getModuleTraits_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Module_getModuleTraits_presult__isset {
  _Module_getModuleTraits_presult__isset() : success(false) {}
  bool success;
} _Module_getModuleTraits_presult__isset;

class Module_getModuleTraits_presult {
 public:


  virtual ~Module_getModuleTraits_presult() throw() {}

  ModuleTraits* success;

  _Module_getModuleTraits_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class ModuleClient : virtual public ModuleIf {
 public:
  ModuleClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  ModuleClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
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
  void activate(const std::string& configFilePath);
  void send_activate(const std::string& configFilePath);
  void recv_activate();
  void deactivate();
  void send_deactivate();
  void recv_deactivate();
  void getModuleConfig(ModuleConfig& _return);
  void send_getModuleConfig();
  void recv_getModuleConfig(ModuleConfig& _return);
  void getModuleTraits(ModuleTraits& _return);
  void send_getModuleTraits();
  void recv_getModuleTraits(ModuleTraits& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class ModuleProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<ModuleIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (ModuleProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_activate(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_deactivate(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getModuleConfig(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getModuleTraits(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  ModuleProcessor(boost::shared_ptr<ModuleIf> iface) :
    iface_(iface) {
    processMap_["activate"] = &ModuleProcessor::process_activate;
    processMap_["deactivate"] = &ModuleProcessor::process_deactivate;
    processMap_["getModuleConfig"] = &ModuleProcessor::process_getModuleConfig;
    processMap_["getModuleTraits"] = &ModuleProcessor::process_getModuleTraits;
  }

  virtual ~ModuleProcessor() {}
};

class ModuleProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  ModuleProcessorFactory(const ::boost::shared_ptr< ModuleIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< ModuleIfFactory > handlerFactory_;
};

class ModuleMultiface : virtual public ModuleIf {
 public:
  ModuleMultiface(std::vector<boost::shared_ptr<ModuleIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~ModuleMultiface() {}
 protected:
  std::vector<boost::shared_ptr<ModuleIf> > ifaces_;
  ModuleMultiface() {}
  void add(boost::shared_ptr<ModuleIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void activate(const std::string& configFilePath) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->activate(configFilePath);
    }
    ifaces_[i]->activate(configFilePath);
  }

  void deactivate() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->deactivate();
    }
    ifaces_[i]->deactivate();
  }

  void getModuleConfig(ModuleConfig& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getModuleConfig(_return);
    }
    ifaces_[i]->getModuleConfig(_return);
    return;
  }

  void getModuleTraits(ModuleTraits& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getModuleTraits(_return);
    }
    ifaces_[i]->getModuleTraits(_return);
    return;
  }

};

}}} // namespace

#endif
