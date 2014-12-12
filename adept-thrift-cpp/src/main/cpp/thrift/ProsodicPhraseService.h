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
#ifndef ProsodicPhraseService_H
#define ProsodicPhraseService_H

#include <thrift/TDispatchProcessor.h>
#include "common_types.h"
#include "ChunkService.h"

namespace thrift { namespace adept { namespace common {

class ProsodicPhraseServiceIf : virtual public ChunkServiceIf {
 public:
  virtual ~ProsodicPhraseServiceIf() {}
  virtual double getConfidence() = 0;
  virtual double getNoveltyConfidence() = 0;
  virtual int64_t getSequenceId() = 0;
  virtual void getType(std::string& _return) = 0;
  virtual double getUncertaintyConfidence() = 0;
  virtual void setConfidence(const double confidence) = 0;
  virtual void setNoveltyConfidence(const double noveltyConfidence) = 0;
  virtual void setType(const std::string& type) = 0;
  virtual void setUncertaintyConfidence(const double uncertaintyConfidence) = 0;
};

class ProsodicPhraseServiceIfFactory : virtual public ChunkServiceIfFactory {
 public:
  typedef ProsodicPhraseServiceIf Handler;

  virtual ~ProsodicPhraseServiceIfFactory() {}

  virtual ProsodicPhraseServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ItemServiceIf* /* handler */) = 0;
};

class ProsodicPhraseServiceIfSingletonFactory : virtual public ProsodicPhraseServiceIfFactory {
 public:
  ProsodicPhraseServiceIfSingletonFactory(const boost::shared_ptr<ProsodicPhraseServiceIf>& iface) : iface_(iface) {}
  virtual ~ProsodicPhraseServiceIfSingletonFactory() {}

  virtual ProsodicPhraseServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ItemServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<ProsodicPhraseServiceIf> iface_;
};

class ProsodicPhraseServiceNull : virtual public ProsodicPhraseServiceIf , virtual public ChunkServiceNull {
 public:
  virtual ~ProsodicPhraseServiceNull() {}
  double getConfidence() {
    double _return = (double)0;
    return _return;
  }
  double getNoveltyConfidence() {
    double _return = (double)0;
    return _return;
  }
  int64_t getSequenceId() {
    int64_t _return = 0;
    return _return;
  }
  void getType(std::string& /* _return */) {
    return;
  }
  double getUncertaintyConfidence() {
    double _return = (double)0;
    return _return;
  }
  void setConfidence(const double /* confidence */) {
    return;
  }
  void setNoveltyConfidence(const double /* noveltyConfidence */) {
    return;
  }
  void setType(const std::string& /* type */) {
    return;
  }
  void setUncertaintyConfidence(const double /* uncertaintyConfidence */) {
    return;
  }
};


class ProsodicPhraseService_getConfidence_args {
 public:

  ProsodicPhraseService_getConfidence_args() {
  }

  virtual ~ProsodicPhraseService_getConfidence_args() throw() {}


  bool operator == (const ProsodicPhraseService_getConfidence_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ProsodicPhraseService_getConfidence_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProsodicPhraseService_getConfidence_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ProsodicPhraseService_getConfidence_pargs {
 public:


  virtual ~ProsodicPhraseService_getConfidence_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ProsodicPhraseService_getConfidence_result__isset {
  _ProsodicPhraseService_getConfidence_result__isset() : success(false) {}
  bool success;
} _ProsodicPhraseService_getConfidence_result__isset;

class ProsodicPhraseService_getConfidence_result {
 public:

  ProsodicPhraseService_getConfidence_result() : success(0) {
  }

  virtual ~ProsodicPhraseService_getConfidence_result() throw() {}

  double success;

  _ProsodicPhraseService_getConfidence_result__isset __isset;

  void __set_success(const double val) {
    success = val;
  }

  bool operator == (const ProsodicPhraseService_getConfidence_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ProsodicPhraseService_getConfidence_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProsodicPhraseService_getConfidence_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ProsodicPhraseService_getConfidence_presult__isset {
  _ProsodicPhraseService_getConfidence_presult__isset() : success(false) {}
  bool success;
} _ProsodicPhraseService_getConfidence_presult__isset;

class ProsodicPhraseService_getConfidence_presult {
 public:


  virtual ~ProsodicPhraseService_getConfidence_presult() throw() {}

  double* success;

  _ProsodicPhraseService_getConfidence_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class ProsodicPhraseService_getNoveltyConfidence_args {
 public:

  ProsodicPhraseService_getNoveltyConfidence_args() {
  }

  virtual ~ProsodicPhraseService_getNoveltyConfidence_args() throw() {}


  bool operator == (const ProsodicPhraseService_getNoveltyConfidence_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ProsodicPhraseService_getNoveltyConfidence_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProsodicPhraseService_getNoveltyConfidence_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ProsodicPhraseService_getNoveltyConfidence_pargs {
 public:


  virtual ~ProsodicPhraseService_getNoveltyConfidence_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ProsodicPhraseService_getNoveltyConfidence_result__isset {
  _ProsodicPhraseService_getNoveltyConfidence_result__isset() : success(false) {}
  bool success;
} _ProsodicPhraseService_getNoveltyConfidence_result__isset;

class ProsodicPhraseService_getNoveltyConfidence_result {
 public:

  ProsodicPhraseService_getNoveltyConfidence_result() : success(0) {
  }

  virtual ~ProsodicPhraseService_getNoveltyConfidence_result() throw() {}

  double success;

  _ProsodicPhraseService_getNoveltyConfidence_result__isset __isset;

  void __set_success(const double val) {
    success = val;
  }

  bool operator == (const ProsodicPhraseService_getNoveltyConfidence_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ProsodicPhraseService_getNoveltyConfidence_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProsodicPhraseService_getNoveltyConfidence_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ProsodicPhraseService_getNoveltyConfidence_presult__isset {
  _ProsodicPhraseService_getNoveltyConfidence_presult__isset() : success(false) {}
  bool success;
} _ProsodicPhraseService_getNoveltyConfidence_presult__isset;

class ProsodicPhraseService_getNoveltyConfidence_presult {
 public:


  virtual ~ProsodicPhraseService_getNoveltyConfidence_presult() throw() {}

  double* success;

  _ProsodicPhraseService_getNoveltyConfidence_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class ProsodicPhraseService_getSequenceId_args {
 public:

  ProsodicPhraseService_getSequenceId_args() {
  }

  virtual ~ProsodicPhraseService_getSequenceId_args() throw() {}


  bool operator == (const ProsodicPhraseService_getSequenceId_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ProsodicPhraseService_getSequenceId_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProsodicPhraseService_getSequenceId_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ProsodicPhraseService_getSequenceId_pargs {
 public:


  virtual ~ProsodicPhraseService_getSequenceId_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ProsodicPhraseService_getSequenceId_result__isset {
  _ProsodicPhraseService_getSequenceId_result__isset() : success(false) {}
  bool success;
} _ProsodicPhraseService_getSequenceId_result__isset;

class ProsodicPhraseService_getSequenceId_result {
 public:

  ProsodicPhraseService_getSequenceId_result() : success(0) {
  }

  virtual ~ProsodicPhraseService_getSequenceId_result() throw() {}

  int64_t success;

  _ProsodicPhraseService_getSequenceId_result__isset __isset;

  void __set_success(const int64_t val) {
    success = val;
  }

  bool operator == (const ProsodicPhraseService_getSequenceId_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ProsodicPhraseService_getSequenceId_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProsodicPhraseService_getSequenceId_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ProsodicPhraseService_getSequenceId_presult__isset {
  _ProsodicPhraseService_getSequenceId_presult__isset() : success(false) {}
  bool success;
} _ProsodicPhraseService_getSequenceId_presult__isset;

class ProsodicPhraseService_getSequenceId_presult {
 public:


  virtual ~ProsodicPhraseService_getSequenceId_presult() throw() {}

  int64_t* success;

  _ProsodicPhraseService_getSequenceId_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class ProsodicPhraseService_getType_args {
 public:

  ProsodicPhraseService_getType_args() {
  }

  virtual ~ProsodicPhraseService_getType_args() throw() {}


  bool operator == (const ProsodicPhraseService_getType_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ProsodicPhraseService_getType_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProsodicPhraseService_getType_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ProsodicPhraseService_getType_pargs {
 public:


  virtual ~ProsodicPhraseService_getType_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ProsodicPhraseService_getType_result__isset {
  _ProsodicPhraseService_getType_result__isset() : success(false) {}
  bool success;
} _ProsodicPhraseService_getType_result__isset;

class ProsodicPhraseService_getType_result {
 public:

  ProsodicPhraseService_getType_result() : success() {
  }

  virtual ~ProsodicPhraseService_getType_result() throw() {}

  std::string success;

  _ProsodicPhraseService_getType_result__isset __isset;

  void __set_success(const std::string& val) {
    success = val;
  }

  bool operator == (const ProsodicPhraseService_getType_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ProsodicPhraseService_getType_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProsodicPhraseService_getType_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ProsodicPhraseService_getType_presult__isset {
  _ProsodicPhraseService_getType_presult__isset() : success(false) {}
  bool success;
} _ProsodicPhraseService_getType_presult__isset;

class ProsodicPhraseService_getType_presult {
 public:


  virtual ~ProsodicPhraseService_getType_presult() throw() {}

  std::string* success;

  _ProsodicPhraseService_getType_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class ProsodicPhraseService_getUncertaintyConfidence_args {
 public:

  ProsodicPhraseService_getUncertaintyConfidence_args() {
  }

  virtual ~ProsodicPhraseService_getUncertaintyConfidence_args() throw() {}


  bool operator == (const ProsodicPhraseService_getUncertaintyConfidence_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ProsodicPhraseService_getUncertaintyConfidence_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProsodicPhraseService_getUncertaintyConfidence_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ProsodicPhraseService_getUncertaintyConfidence_pargs {
 public:


  virtual ~ProsodicPhraseService_getUncertaintyConfidence_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ProsodicPhraseService_getUncertaintyConfidence_result__isset {
  _ProsodicPhraseService_getUncertaintyConfidence_result__isset() : success(false) {}
  bool success;
} _ProsodicPhraseService_getUncertaintyConfidence_result__isset;

class ProsodicPhraseService_getUncertaintyConfidence_result {
 public:

  ProsodicPhraseService_getUncertaintyConfidence_result() : success(0) {
  }

  virtual ~ProsodicPhraseService_getUncertaintyConfidence_result() throw() {}

  double success;

  _ProsodicPhraseService_getUncertaintyConfidence_result__isset __isset;

  void __set_success(const double val) {
    success = val;
  }

  bool operator == (const ProsodicPhraseService_getUncertaintyConfidence_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ProsodicPhraseService_getUncertaintyConfidence_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProsodicPhraseService_getUncertaintyConfidence_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ProsodicPhraseService_getUncertaintyConfidence_presult__isset {
  _ProsodicPhraseService_getUncertaintyConfidence_presult__isset() : success(false) {}
  bool success;
} _ProsodicPhraseService_getUncertaintyConfidence_presult__isset;

class ProsodicPhraseService_getUncertaintyConfidence_presult {
 public:


  virtual ~ProsodicPhraseService_getUncertaintyConfidence_presult() throw() {}

  double* success;

  _ProsodicPhraseService_getUncertaintyConfidence_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _ProsodicPhraseService_setConfidence_args__isset {
  _ProsodicPhraseService_setConfidence_args__isset() : confidence(false) {}
  bool confidence;
} _ProsodicPhraseService_setConfidence_args__isset;

class ProsodicPhraseService_setConfidence_args {
 public:

  ProsodicPhraseService_setConfidence_args() : confidence(0) {
  }

  virtual ~ProsodicPhraseService_setConfidence_args() throw() {}

  double confidence;

  _ProsodicPhraseService_setConfidence_args__isset __isset;

  void __set_confidence(const double val) {
    confidence = val;
  }

  bool operator == (const ProsodicPhraseService_setConfidence_args & rhs) const
  {
    if (!(confidence == rhs.confidence))
      return false;
    return true;
  }
  bool operator != (const ProsodicPhraseService_setConfidence_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProsodicPhraseService_setConfidence_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ProsodicPhraseService_setConfidence_pargs {
 public:


  virtual ~ProsodicPhraseService_setConfidence_pargs() throw() {}

  const double* confidence;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ProsodicPhraseService_setConfidence_result {
 public:

  ProsodicPhraseService_setConfidence_result() {
  }

  virtual ~ProsodicPhraseService_setConfidence_result() throw() {}


  bool operator == (const ProsodicPhraseService_setConfidence_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ProsodicPhraseService_setConfidence_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProsodicPhraseService_setConfidence_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ProsodicPhraseService_setConfidence_presult {
 public:


  virtual ~ProsodicPhraseService_setConfidence_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _ProsodicPhraseService_setNoveltyConfidence_args__isset {
  _ProsodicPhraseService_setNoveltyConfidence_args__isset() : noveltyConfidence(false) {}
  bool noveltyConfidence;
} _ProsodicPhraseService_setNoveltyConfidence_args__isset;

class ProsodicPhraseService_setNoveltyConfidence_args {
 public:

  ProsodicPhraseService_setNoveltyConfidence_args() : noveltyConfidence(0) {
  }

  virtual ~ProsodicPhraseService_setNoveltyConfidence_args() throw() {}

  double noveltyConfidence;

  _ProsodicPhraseService_setNoveltyConfidence_args__isset __isset;

  void __set_noveltyConfidence(const double val) {
    noveltyConfidence = val;
  }

  bool operator == (const ProsodicPhraseService_setNoveltyConfidence_args & rhs) const
  {
    if (!(noveltyConfidence == rhs.noveltyConfidence))
      return false;
    return true;
  }
  bool operator != (const ProsodicPhraseService_setNoveltyConfidence_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProsodicPhraseService_setNoveltyConfidence_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ProsodicPhraseService_setNoveltyConfidence_pargs {
 public:


  virtual ~ProsodicPhraseService_setNoveltyConfidence_pargs() throw() {}

  const double* noveltyConfidence;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ProsodicPhraseService_setNoveltyConfidence_result {
 public:

  ProsodicPhraseService_setNoveltyConfidence_result() {
  }

  virtual ~ProsodicPhraseService_setNoveltyConfidence_result() throw() {}


  bool operator == (const ProsodicPhraseService_setNoveltyConfidence_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ProsodicPhraseService_setNoveltyConfidence_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProsodicPhraseService_setNoveltyConfidence_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ProsodicPhraseService_setNoveltyConfidence_presult {
 public:


  virtual ~ProsodicPhraseService_setNoveltyConfidence_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _ProsodicPhraseService_setType_args__isset {
  _ProsodicPhraseService_setType_args__isset() : type(false) {}
  bool type;
} _ProsodicPhraseService_setType_args__isset;

class ProsodicPhraseService_setType_args {
 public:

  ProsodicPhraseService_setType_args() : type() {
  }

  virtual ~ProsodicPhraseService_setType_args() throw() {}

  std::string type;

  _ProsodicPhraseService_setType_args__isset __isset;

  void __set_type(const std::string& val) {
    type = val;
  }

  bool operator == (const ProsodicPhraseService_setType_args & rhs) const
  {
    if (!(type == rhs.type))
      return false;
    return true;
  }
  bool operator != (const ProsodicPhraseService_setType_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProsodicPhraseService_setType_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ProsodicPhraseService_setType_pargs {
 public:


  virtual ~ProsodicPhraseService_setType_pargs() throw() {}

  const std::string* type;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ProsodicPhraseService_setType_result {
 public:

  ProsodicPhraseService_setType_result() {
  }

  virtual ~ProsodicPhraseService_setType_result() throw() {}


  bool operator == (const ProsodicPhraseService_setType_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ProsodicPhraseService_setType_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProsodicPhraseService_setType_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ProsodicPhraseService_setType_presult {
 public:


  virtual ~ProsodicPhraseService_setType_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _ProsodicPhraseService_setUncertaintyConfidence_args__isset {
  _ProsodicPhraseService_setUncertaintyConfidence_args__isset() : uncertaintyConfidence(false) {}
  bool uncertaintyConfidence;
} _ProsodicPhraseService_setUncertaintyConfidence_args__isset;

class ProsodicPhraseService_setUncertaintyConfidence_args {
 public:

  ProsodicPhraseService_setUncertaintyConfidence_args() : uncertaintyConfidence(0) {
  }

  virtual ~ProsodicPhraseService_setUncertaintyConfidence_args() throw() {}

  double uncertaintyConfidence;

  _ProsodicPhraseService_setUncertaintyConfidence_args__isset __isset;

  void __set_uncertaintyConfidence(const double val) {
    uncertaintyConfidence = val;
  }

  bool operator == (const ProsodicPhraseService_setUncertaintyConfidence_args & rhs) const
  {
    if (!(uncertaintyConfidence == rhs.uncertaintyConfidence))
      return false;
    return true;
  }
  bool operator != (const ProsodicPhraseService_setUncertaintyConfidence_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProsodicPhraseService_setUncertaintyConfidence_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ProsodicPhraseService_setUncertaintyConfidence_pargs {
 public:


  virtual ~ProsodicPhraseService_setUncertaintyConfidence_pargs() throw() {}

  const double* uncertaintyConfidence;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ProsodicPhraseService_setUncertaintyConfidence_result {
 public:

  ProsodicPhraseService_setUncertaintyConfidence_result() {
  }

  virtual ~ProsodicPhraseService_setUncertaintyConfidence_result() throw() {}


  bool operator == (const ProsodicPhraseService_setUncertaintyConfidence_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ProsodicPhraseService_setUncertaintyConfidence_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProsodicPhraseService_setUncertaintyConfidence_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ProsodicPhraseService_setUncertaintyConfidence_presult {
 public:


  virtual ~ProsodicPhraseService_setUncertaintyConfidence_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class ProsodicPhraseServiceClient : virtual public ProsodicPhraseServiceIf, public ChunkServiceClient {
 public:
  ProsodicPhraseServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    ChunkServiceClient(prot, prot) {}
  ProsodicPhraseServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    ChunkServiceClient(iprot, oprot) {}
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  double getConfidence();
  void send_getConfidence();
  double recv_getConfidence();
  double getNoveltyConfidence();
  void send_getNoveltyConfidence();
  double recv_getNoveltyConfidence();
  int64_t getSequenceId();
  void send_getSequenceId();
  int64_t recv_getSequenceId();
  void getType(std::string& _return);
  void send_getType();
  void recv_getType(std::string& _return);
  double getUncertaintyConfidence();
  void send_getUncertaintyConfidence();
  double recv_getUncertaintyConfidence();
  void setConfidence(const double confidence);
  void send_setConfidence(const double confidence);
  void recv_setConfidence();
  void setNoveltyConfidence(const double noveltyConfidence);
  void send_setNoveltyConfidence(const double noveltyConfidence);
  void recv_setNoveltyConfidence();
  void setType(const std::string& type);
  void send_setType(const std::string& type);
  void recv_setType();
  void setUncertaintyConfidence(const double uncertaintyConfidence);
  void send_setUncertaintyConfidence(const double uncertaintyConfidence);
  void recv_setUncertaintyConfidence();
};

class ProsodicPhraseServiceProcessor : public ChunkServiceProcessor {
 protected:
  boost::shared_ptr<ProsodicPhraseServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (ProsodicPhraseServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_getConfidence(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getNoveltyConfidence(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getSequenceId(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getType(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getUncertaintyConfidence(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setConfidence(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setNoveltyConfidence(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setType(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setUncertaintyConfidence(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  ProsodicPhraseServiceProcessor(boost::shared_ptr<ProsodicPhraseServiceIf> iface) :
    ChunkServiceProcessor(iface),
    iface_(iface) {
    processMap_["getConfidence"] = &ProsodicPhraseServiceProcessor::process_getConfidence;
    processMap_["getNoveltyConfidence"] = &ProsodicPhraseServiceProcessor::process_getNoveltyConfidence;
    processMap_["getSequenceId"] = &ProsodicPhraseServiceProcessor::process_getSequenceId;
    processMap_["getType"] = &ProsodicPhraseServiceProcessor::process_getType;
    processMap_["getUncertaintyConfidence"] = &ProsodicPhraseServiceProcessor::process_getUncertaintyConfidence;
    processMap_["setConfidence"] = &ProsodicPhraseServiceProcessor::process_setConfidence;
    processMap_["setNoveltyConfidence"] = &ProsodicPhraseServiceProcessor::process_setNoveltyConfidence;
    processMap_["setType"] = &ProsodicPhraseServiceProcessor::process_setType;
    processMap_["setUncertaintyConfidence"] = &ProsodicPhraseServiceProcessor::process_setUncertaintyConfidence;
  }

  virtual ~ProsodicPhraseServiceProcessor() {}
};

class ProsodicPhraseServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  ProsodicPhraseServiceProcessorFactory(const ::boost::shared_ptr< ProsodicPhraseServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< ProsodicPhraseServiceIfFactory > handlerFactory_;
};

class ProsodicPhraseServiceMultiface : virtual public ProsodicPhraseServiceIf, public ChunkServiceMultiface {
 public:
  ProsodicPhraseServiceMultiface(std::vector<boost::shared_ptr<ProsodicPhraseServiceIf> >& ifaces) : ifaces_(ifaces) {
    std::vector<boost::shared_ptr<ProsodicPhraseServiceIf> >::iterator iter;
    for (iter = ifaces.begin(); iter != ifaces.end(); ++iter) {
      ChunkServiceMultiface::add(*iter);
    }
  }
  virtual ~ProsodicPhraseServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<ProsodicPhraseServiceIf> > ifaces_;
  ProsodicPhraseServiceMultiface() {}
  void add(boost::shared_ptr<ProsodicPhraseServiceIf> iface) {
    ChunkServiceMultiface::add(iface);
    ifaces_.push_back(iface);
  }
 public:
  double getConfidence() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getConfidence();
    }
    return ifaces_[i]->getConfidence();
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

  void getType(std::string& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getType(_return);
    }
    ifaces_[i]->getType(_return);
    return;
  }

  double getUncertaintyConfidence() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getUncertaintyConfidence();
    }
    return ifaces_[i]->getUncertaintyConfidence();
  }

  void setConfidence(const double confidence) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setConfidence(confidence);
    }
    ifaces_[i]->setConfidence(confidence);
  }

  void setNoveltyConfidence(const double noveltyConfidence) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setNoveltyConfidence(noveltyConfidence);
    }
    ifaces_[i]->setNoveltyConfidence(noveltyConfidence);
  }

  void setType(const std::string& type) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setType(type);
    }
    ifaces_[i]->setType(type);
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
