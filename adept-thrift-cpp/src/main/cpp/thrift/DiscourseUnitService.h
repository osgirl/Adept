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
#ifndef DiscourseUnitService_H
#define DiscourseUnitService_H

#include <thrift/TDispatchProcessor.h>
#include "common_types.h"
#include "ChunkService.h"

namespace thrift { namespace adept { namespace common {

class DiscourseUnitServiceIf : virtual public ChunkServiceIf {
 public:
  virtual ~DiscourseUnitServiceIf() {}
  virtual void getDiscourceType(std::string& _return) = 0;
  virtual double getNoveltyConfidence() = 0;
  virtual int64_t getSequenceId() = 0;
  virtual double getUncertaintyConfidence() = 0;
  virtual void setDiscourceType(const std::string& discourceType) = 0;
  virtual void setNoveltyConfidence(const double noveltyConfidence) = 0;
  virtual void setUncertaintyConfidence(const double uncertaintyConfidence) = 0;
};

class DiscourseUnitServiceIfFactory : virtual public ChunkServiceIfFactory {
 public:
  typedef DiscourseUnitServiceIf Handler;

  virtual ~DiscourseUnitServiceIfFactory() {}

  virtual DiscourseUnitServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ItemServiceIf* /* handler */) = 0;
};

class DiscourseUnitServiceIfSingletonFactory : virtual public DiscourseUnitServiceIfFactory {
 public:
  DiscourseUnitServiceIfSingletonFactory(const boost::shared_ptr<DiscourseUnitServiceIf>& iface) : iface_(iface) {}
  virtual ~DiscourseUnitServiceIfSingletonFactory() {}

  virtual DiscourseUnitServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ItemServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<DiscourseUnitServiceIf> iface_;
};

class DiscourseUnitServiceNull : virtual public DiscourseUnitServiceIf , virtual public ChunkServiceNull {
 public:
  virtual ~DiscourseUnitServiceNull() {}
  void getDiscourceType(std::string& /* _return */) {
    return;
  }
  double getNoveltyConfidence() {
    double _return = (double)0;
    return _return;
  }
  int64_t getSequenceId() {
    int64_t _return = 0;
    return _return;
  }
  double getUncertaintyConfidence() {
    double _return = (double)0;
    return _return;
  }
  void setDiscourceType(const std::string& /* discourceType */) {
    return;
  }
  void setNoveltyConfidence(const double /* noveltyConfidence */) {
    return;
  }
  void setUncertaintyConfidence(const double /* uncertaintyConfidence */) {
    return;
  }
};


class DiscourseUnitService_getDiscourceType_args {
 public:

  DiscourseUnitService_getDiscourceType_args() {
  }

  virtual ~DiscourseUnitService_getDiscourceType_args() throw() {}


  bool operator == (const DiscourseUnitService_getDiscourceType_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DiscourseUnitService_getDiscourceType_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiscourseUnitService_getDiscourceType_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiscourseUnitService_getDiscourceType_pargs {
 public:


  virtual ~DiscourseUnitService_getDiscourceType_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiscourseUnitService_getDiscourceType_result__isset {
  _DiscourseUnitService_getDiscourceType_result__isset() : success(false) {}
  bool success;
} _DiscourseUnitService_getDiscourceType_result__isset;

class DiscourseUnitService_getDiscourceType_result {
 public:

  DiscourseUnitService_getDiscourceType_result() : success() {
  }

  virtual ~DiscourseUnitService_getDiscourceType_result() throw() {}

  std::string success;

  _DiscourseUnitService_getDiscourceType_result__isset __isset;

  void __set_success(const std::string& val) {
    success = val;
  }

  bool operator == (const DiscourseUnitService_getDiscourceType_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const DiscourseUnitService_getDiscourceType_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiscourseUnitService_getDiscourceType_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiscourseUnitService_getDiscourceType_presult__isset {
  _DiscourseUnitService_getDiscourceType_presult__isset() : success(false) {}
  bool success;
} _DiscourseUnitService_getDiscourceType_presult__isset;

class DiscourseUnitService_getDiscourceType_presult {
 public:


  virtual ~DiscourseUnitService_getDiscourceType_presult() throw() {}

  std::string* success;

  _DiscourseUnitService_getDiscourceType_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class DiscourseUnitService_getNoveltyConfidence_args {
 public:

  DiscourseUnitService_getNoveltyConfidence_args() {
  }

  virtual ~DiscourseUnitService_getNoveltyConfidence_args() throw() {}


  bool operator == (const DiscourseUnitService_getNoveltyConfidence_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DiscourseUnitService_getNoveltyConfidence_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiscourseUnitService_getNoveltyConfidence_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiscourseUnitService_getNoveltyConfidence_pargs {
 public:


  virtual ~DiscourseUnitService_getNoveltyConfidence_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiscourseUnitService_getNoveltyConfidence_result__isset {
  _DiscourseUnitService_getNoveltyConfidence_result__isset() : success(false) {}
  bool success;
} _DiscourseUnitService_getNoveltyConfidence_result__isset;

class DiscourseUnitService_getNoveltyConfidence_result {
 public:

  DiscourseUnitService_getNoveltyConfidence_result() : success(0) {
  }

  virtual ~DiscourseUnitService_getNoveltyConfidence_result() throw() {}

  double success;

  _DiscourseUnitService_getNoveltyConfidence_result__isset __isset;

  void __set_success(const double val) {
    success = val;
  }

  bool operator == (const DiscourseUnitService_getNoveltyConfidence_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const DiscourseUnitService_getNoveltyConfidence_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiscourseUnitService_getNoveltyConfidence_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiscourseUnitService_getNoveltyConfidence_presult__isset {
  _DiscourseUnitService_getNoveltyConfidence_presult__isset() : success(false) {}
  bool success;
} _DiscourseUnitService_getNoveltyConfidence_presult__isset;

class DiscourseUnitService_getNoveltyConfidence_presult {
 public:


  virtual ~DiscourseUnitService_getNoveltyConfidence_presult() throw() {}

  double* success;

  _DiscourseUnitService_getNoveltyConfidence_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class DiscourseUnitService_getSequenceId_args {
 public:

  DiscourseUnitService_getSequenceId_args() {
  }

  virtual ~DiscourseUnitService_getSequenceId_args() throw() {}


  bool operator == (const DiscourseUnitService_getSequenceId_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DiscourseUnitService_getSequenceId_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiscourseUnitService_getSequenceId_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiscourseUnitService_getSequenceId_pargs {
 public:


  virtual ~DiscourseUnitService_getSequenceId_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiscourseUnitService_getSequenceId_result__isset {
  _DiscourseUnitService_getSequenceId_result__isset() : success(false) {}
  bool success;
} _DiscourseUnitService_getSequenceId_result__isset;

class DiscourseUnitService_getSequenceId_result {
 public:

  DiscourseUnitService_getSequenceId_result() : success(0) {
  }

  virtual ~DiscourseUnitService_getSequenceId_result() throw() {}

  int64_t success;

  _DiscourseUnitService_getSequenceId_result__isset __isset;

  void __set_success(const int64_t val) {
    success = val;
  }

  bool operator == (const DiscourseUnitService_getSequenceId_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const DiscourseUnitService_getSequenceId_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiscourseUnitService_getSequenceId_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiscourseUnitService_getSequenceId_presult__isset {
  _DiscourseUnitService_getSequenceId_presult__isset() : success(false) {}
  bool success;
} _DiscourseUnitService_getSequenceId_presult__isset;

class DiscourseUnitService_getSequenceId_presult {
 public:


  virtual ~DiscourseUnitService_getSequenceId_presult() throw() {}

  int64_t* success;

  _DiscourseUnitService_getSequenceId_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class DiscourseUnitService_getUncertaintyConfidence_args {
 public:

  DiscourseUnitService_getUncertaintyConfidence_args() {
  }

  virtual ~DiscourseUnitService_getUncertaintyConfidence_args() throw() {}


  bool operator == (const DiscourseUnitService_getUncertaintyConfidence_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DiscourseUnitService_getUncertaintyConfidence_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiscourseUnitService_getUncertaintyConfidence_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiscourseUnitService_getUncertaintyConfidence_pargs {
 public:


  virtual ~DiscourseUnitService_getUncertaintyConfidence_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiscourseUnitService_getUncertaintyConfidence_result__isset {
  _DiscourseUnitService_getUncertaintyConfidence_result__isset() : success(false) {}
  bool success;
} _DiscourseUnitService_getUncertaintyConfidence_result__isset;

class DiscourseUnitService_getUncertaintyConfidence_result {
 public:

  DiscourseUnitService_getUncertaintyConfidence_result() : success(0) {
  }

  virtual ~DiscourseUnitService_getUncertaintyConfidence_result() throw() {}

  double success;

  _DiscourseUnitService_getUncertaintyConfidence_result__isset __isset;

  void __set_success(const double val) {
    success = val;
  }

  bool operator == (const DiscourseUnitService_getUncertaintyConfidence_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const DiscourseUnitService_getUncertaintyConfidence_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiscourseUnitService_getUncertaintyConfidence_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiscourseUnitService_getUncertaintyConfidence_presult__isset {
  _DiscourseUnitService_getUncertaintyConfidence_presult__isset() : success(false) {}
  bool success;
} _DiscourseUnitService_getUncertaintyConfidence_presult__isset;

class DiscourseUnitService_getUncertaintyConfidence_presult {
 public:


  virtual ~DiscourseUnitService_getUncertaintyConfidence_presult() throw() {}

  double* success;

  _DiscourseUnitService_getUncertaintyConfidence_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DiscourseUnitService_setDiscourceType_args__isset {
  _DiscourseUnitService_setDiscourceType_args__isset() : discourceType(false) {}
  bool discourceType;
} _DiscourseUnitService_setDiscourceType_args__isset;

class DiscourseUnitService_setDiscourceType_args {
 public:

  DiscourseUnitService_setDiscourceType_args() : discourceType() {
  }

  virtual ~DiscourseUnitService_setDiscourceType_args() throw() {}

  std::string discourceType;

  _DiscourseUnitService_setDiscourceType_args__isset __isset;

  void __set_discourceType(const std::string& val) {
    discourceType = val;
  }

  bool operator == (const DiscourseUnitService_setDiscourceType_args & rhs) const
  {
    if (!(discourceType == rhs.discourceType))
      return false;
    return true;
  }
  bool operator != (const DiscourseUnitService_setDiscourceType_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiscourseUnitService_setDiscourceType_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiscourseUnitService_setDiscourceType_pargs {
 public:


  virtual ~DiscourseUnitService_setDiscourceType_pargs() throw() {}

  const std::string* discourceType;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiscourseUnitService_setDiscourceType_result {
 public:

  DiscourseUnitService_setDiscourceType_result() {
  }

  virtual ~DiscourseUnitService_setDiscourceType_result() throw() {}


  bool operator == (const DiscourseUnitService_setDiscourceType_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DiscourseUnitService_setDiscourceType_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiscourseUnitService_setDiscourceType_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiscourseUnitService_setDiscourceType_presult {
 public:


  virtual ~DiscourseUnitService_setDiscourceType_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DiscourseUnitService_setNoveltyConfidence_args__isset {
  _DiscourseUnitService_setNoveltyConfidence_args__isset() : noveltyConfidence(false) {}
  bool noveltyConfidence;
} _DiscourseUnitService_setNoveltyConfidence_args__isset;

class DiscourseUnitService_setNoveltyConfidence_args {
 public:

  DiscourseUnitService_setNoveltyConfidence_args() : noveltyConfidence(0) {
  }

  virtual ~DiscourseUnitService_setNoveltyConfidence_args() throw() {}

  double noveltyConfidence;

  _DiscourseUnitService_setNoveltyConfidence_args__isset __isset;

  void __set_noveltyConfidence(const double val) {
    noveltyConfidence = val;
  }

  bool operator == (const DiscourseUnitService_setNoveltyConfidence_args & rhs) const
  {
    if (!(noveltyConfidence == rhs.noveltyConfidence))
      return false;
    return true;
  }
  bool operator != (const DiscourseUnitService_setNoveltyConfidence_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiscourseUnitService_setNoveltyConfidence_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiscourseUnitService_setNoveltyConfidence_pargs {
 public:


  virtual ~DiscourseUnitService_setNoveltyConfidence_pargs() throw() {}

  const double* noveltyConfidence;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiscourseUnitService_setNoveltyConfidence_result {
 public:

  DiscourseUnitService_setNoveltyConfidence_result() {
  }

  virtual ~DiscourseUnitService_setNoveltyConfidence_result() throw() {}


  bool operator == (const DiscourseUnitService_setNoveltyConfidence_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DiscourseUnitService_setNoveltyConfidence_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiscourseUnitService_setNoveltyConfidence_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiscourseUnitService_setNoveltyConfidence_presult {
 public:


  virtual ~DiscourseUnitService_setNoveltyConfidence_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DiscourseUnitService_setUncertaintyConfidence_args__isset {
  _DiscourseUnitService_setUncertaintyConfidence_args__isset() : uncertaintyConfidence(false) {}
  bool uncertaintyConfidence;
} _DiscourseUnitService_setUncertaintyConfidence_args__isset;

class DiscourseUnitService_setUncertaintyConfidence_args {
 public:

  DiscourseUnitService_setUncertaintyConfidence_args() : uncertaintyConfidence(0) {
  }

  virtual ~DiscourseUnitService_setUncertaintyConfidence_args() throw() {}

  double uncertaintyConfidence;

  _DiscourseUnitService_setUncertaintyConfidence_args__isset __isset;

  void __set_uncertaintyConfidence(const double val) {
    uncertaintyConfidence = val;
  }

  bool operator == (const DiscourseUnitService_setUncertaintyConfidence_args & rhs) const
  {
    if (!(uncertaintyConfidence == rhs.uncertaintyConfidence))
      return false;
    return true;
  }
  bool operator != (const DiscourseUnitService_setUncertaintyConfidence_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiscourseUnitService_setUncertaintyConfidence_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiscourseUnitService_setUncertaintyConfidence_pargs {
 public:


  virtual ~DiscourseUnitService_setUncertaintyConfidence_pargs() throw() {}

  const double* uncertaintyConfidence;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiscourseUnitService_setUncertaintyConfidence_result {
 public:

  DiscourseUnitService_setUncertaintyConfidence_result() {
  }

  virtual ~DiscourseUnitService_setUncertaintyConfidence_result() throw() {}


  bool operator == (const DiscourseUnitService_setUncertaintyConfidence_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DiscourseUnitService_setUncertaintyConfidence_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiscourseUnitService_setUncertaintyConfidence_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiscourseUnitService_setUncertaintyConfidence_presult {
 public:


  virtual ~DiscourseUnitService_setUncertaintyConfidence_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class DiscourseUnitServiceClient : virtual public DiscourseUnitServiceIf, public ChunkServiceClient {
 public:
  DiscourseUnitServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    ChunkServiceClient(prot, prot) {}
  DiscourseUnitServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    ChunkServiceClient(iprot, oprot) {}
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void getDiscourceType(std::string& _return);
  void send_getDiscourceType();
  void recv_getDiscourceType(std::string& _return);
  double getNoveltyConfidence();
  void send_getNoveltyConfidence();
  double recv_getNoveltyConfidence();
  int64_t getSequenceId();
  void send_getSequenceId();
  int64_t recv_getSequenceId();
  double getUncertaintyConfidence();
  void send_getUncertaintyConfidence();
  double recv_getUncertaintyConfidence();
  void setDiscourceType(const std::string& discourceType);
  void send_setDiscourceType(const std::string& discourceType);
  void recv_setDiscourceType();
  void setNoveltyConfidence(const double noveltyConfidence);
  void send_setNoveltyConfidence(const double noveltyConfidence);
  void recv_setNoveltyConfidence();
  void setUncertaintyConfidence(const double uncertaintyConfidence);
  void send_setUncertaintyConfidence(const double uncertaintyConfidence);
  void recv_setUncertaintyConfidence();
};

class DiscourseUnitServiceProcessor : public ChunkServiceProcessor {
 protected:
  boost::shared_ptr<DiscourseUnitServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (DiscourseUnitServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_getDiscourceType(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getNoveltyConfidence(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getSequenceId(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getUncertaintyConfidence(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setDiscourceType(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setNoveltyConfidence(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setUncertaintyConfidence(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  DiscourseUnitServiceProcessor(boost::shared_ptr<DiscourseUnitServiceIf> iface) :
    ChunkServiceProcessor(iface),
    iface_(iface) {
    processMap_["getDiscourceType"] = &DiscourseUnitServiceProcessor::process_getDiscourceType;
    processMap_["getNoveltyConfidence"] = &DiscourseUnitServiceProcessor::process_getNoveltyConfidence;
    processMap_["getSequenceId"] = &DiscourseUnitServiceProcessor::process_getSequenceId;
    processMap_["getUncertaintyConfidence"] = &DiscourseUnitServiceProcessor::process_getUncertaintyConfidence;
    processMap_["setDiscourceType"] = &DiscourseUnitServiceProcessor::process_setDiscourceType;
    processMap_["setNoveltyConfidence"] = &DiscourseUnitServiceProcessor::process_setNoveltyConfidence;
    processMap_["setUncertaintyConfidence"] = &DiscourseUnitServiceProcessor::process_setUncertaintyConfidence;
  }

  virtual ~DiscourseUnitServiceProcessor() {}
};

class DiscourseUnitServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  DiscourseUnitServiceProcessorFactory(const ::boost::shared_ptr< DiscourseUnitServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< DiscourseUnitServiceIfFactory > handlerFactory_;
};

class DiscourseUnitServiceMultiface : virtual public DiscourseUnitServiceIf, public ChunkServiceMultiface {
 public:
  DiscourseUnitServiceMultiface(std::vector<boost::shared_ptr<DiscourseUnitServiceIf> >& ifaces) : ifaces_(ifaces) {
    std::vector<boost::shared_ptr<DiscourseUnitServiceIf> >::iterator iter;
    for (iter = ifaces.begin(); iter != ifaces.end(); ++iter) {
      ChunkServiceMultiface::add(*iter);
    }
  }
  virtual ~DiscourseUnitServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<DiscourseUnitServiceIf> > ifaces_;
  DiscourseUnitServiceMultiface() {}
  void add(boost::shared_ptr<DiscourseUnitServiceIf> iface) {
    ChunkServiceMultiface::add(iface);
    ifaces_.push_back(iface);
  }
 public:
  void getDiscourceType(std::string& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getDiscourceType(_return);
    }
    ifaces_[i]->getDiscourceType(_return);
    return;
  }

  double getNoveltyConfidence() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getNoveltyConfidence();
    }
    return ifaces_[i]->getNoveltyConfidence();
  }

  int64_t getSequenceId() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getSequenceId();
    }
    return ifaces_[i]->getSequenceId();
  }

  double getUncertaintyConfidence() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getUncertaintyConfidence();
    }
    return ifaces_[i]->getUncertaintyConfidence();
  }

  void setDiscourceType(const std::string& discourceType) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setDiscourceType(discourceType);
    }
    ifaces_[i]->setDiscourceType(discourceType);
  }

  void setNoveltyConfidence(const double noveltyConfidence) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setNoveltyConfidence(noveltyConfidence);
    }
    ifaces_[i]->setNoveltyConfidence(noveltyConfidence);
  }

  void setUncertaintyConfidence(const double uncertaintyConfidence) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setUncertaintyConfidence(uncertaintyConfidence);
    }
    ifaces_[i]->setUncertaintyConfidence(uncertaintyConfidence);
  }

};

}}} // namespace

#endif
