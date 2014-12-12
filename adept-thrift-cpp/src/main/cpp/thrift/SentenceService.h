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
#ifndef SentenceService_H
#define SentenceService_H

#include <thrift/TDispatchProcessor.h>
#include "common_types.h"
#include "ChunkService.h"

namespace thrift { namespace adept { namespace common {

class SentenceServiceIf : virtual public ChunkServiceIf {
 public:
  virtual ~SentenceServiceIf() {}
  virtual double getNoveltyConfidence() = 0;
  virtual void getPunctuation(std::string& _return) = 0;
  virtual int64_t getSequenceId() = 0;
  virtual SentenceType::type getType() = 0;
  virtual double getUncertaintyConfidence() = 0;
  virtual void setNoveltyConfidence(const double noveltyConfidence) = 0;
  virtual void setPunctuation(const std::string& punctuation) = 0;
  virtual void setType(const SentenceType::type type) = 0;
  virtual void setUncertaintyConfidence(const double uncertaintyConfidence) = 0;
};

class SentenceServiceIfFactory : virtual public ChunkServiceIfFactory {
 public:
  typedef SentenceServiceIf Handler;

  virtual ~SentenceServiceIfFactory() {}

  virtual SentenceServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ItemServiceIf* /* handler */) = 0;
};

class SentenceServiceIfSingletonFactory : virtual public SentenceServiceIfFactory {
 public:
  SentenceServiceIfSingletonFactory(const boost::shared_ptr<SentenceServiceIf>& iface) : iface_(iface) {}
  virtual ~SentenceServiceIfSingletonFactory() {}

  virtual SentenceServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ItemServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<SentenceServiceIf> iface_;
};

class SentenceServiceNull : virtual public SentenceServiceIf , virtual public ChunkServiceNull {
 public:
  virtual ~SentenceServiceNull() {}
  double getNoveltyConfidence() {
    double _return = (double)0;
    return _return;
  }
  void getPunctuation(std::string& /* _return */) {
    return;
  }
  int64_t getSequenceId() {
    int64_t _return = 0;
    return _return;
  }
  SentenceType::type getType() {
    SentenceType::type _return = (SentenceType::type)0;
    return _return;
  }
  double getUncertaintyConfidence() {
    double _return = (double)0;
    return _return;
  }
  void setNoveltyConfidence(const double /* noveltyConfidence */) {
    return;
  }
  void setPunctuation(const std::string& /* punctuation */) {
    return;
  }
  void setType(const SentenceType::type /* type */) {
    return;
  }
  void setUncertaintyConfidence(const double /* uncertaintyConfidence */) {
    return;
  }
};


class SentenceService_getNoveltyConfidence_args {
 public:

  SentenceService_getNoveltyConfidence_args() {
  }

  virtual ~SentenceService_getNoveltyConfidence_args() throw() {}


  bool operator == (const SentenceService_getNoveltyConfidence_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const SentenceService_getNoveltyConfidence_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SentenceService_getNoveltyConfidence_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class SentenceService_getNoveltyConfidence_pargs {
 public:


  virtual ~SentenceService_getNoveltyConfidence_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _SentenceService_getNoveltyConfidence_result__isset {
  _SentenceService_getNoveltyConfidence_result__isset() : success(false) {}
  bool success;
} _SentenceService_getNoveltyConfidence_result__isset;

class SentenceService_getNoveltyConfidence_result {
 public:

  SentenceService_getNoveltyConfidence_result() : success(0) {
  }

  virtual ~SentenceService_getNoveltyConfidence_result() throw() {}

  double success;

  _SentenceService_getNoveltyConfidence_result__isset __isset;

  void __set_success(const double val) {
    success = val;
  }

  bool operator == (const SentenceService_getNoveltyConfidence_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const SentenceService_getNoveltyConfidence_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SentenceService_getNoveltyConfidence_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _SentenceService_getNoveltyConfidence_presult__isset {
  _SentenceService_getNoveltyConfidence_presult__isset() : success(false) {}
  bool success;
} _SentenceService_getNoveltyConfidence_presult__isset;

class SentenceService_getNoveltyConfidence_presult {
 public:


  virtual ~SentenceService_getNoveltyConfidence_presult() throw() {}

  double* success;

  _SentenceService_getNoveltyConfidence_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class SentenceService_getPunctuation_args {
 public:

  SentenceService_getPunctuation_args() {
  }

  virtual ~SentenceService_getPunctuation_args() throw() {}


  bool operator == (const SentenceService_getPunctuation_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const SentenceService_getPunctuation_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SentenceService_getPunctuation_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class SentenceService_getPunctuation_pargs {
 public:


  virtual ~SentenceService_getPunctuation_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _SentenceService_getPunctuation_result__isset {
  _SentenceService_getPunctuation_result__isset() : success(false) {}
  bool success;
} _SentenceService_getPunctuation_result__isset;

class SentenceService_getPunctuation_result {
 public:

  SentenceService_getPunctuation_result() : success() {
  }

  virtual ~SentenceService_getPunctuation_result() throw() {}

  std::string success;

  _SentenceService_getPunctuation_result__isset __isset;

  void __set_success(const std::string& val) {
    success = val;
  }

  bool operator == (const SentenceService_getPunctuation_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const SentenceService_getPunctuation_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SentenceService_getPunctuation_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _SentenceService_getPunctuation_presult__isset {
  _SentenceService_getPunctuation_presult__isset() : success(false) {}
  bool success;
} _SentenceService_getPunctuation_presult__isset;

class SentenceService_getPunctuation_presult {
 public:


  virtual ~SentenceService_getPunctuation_presult() throw() {}

  std::string* success;

  _SentenceService_getPunctuation_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class SentenceService_getSequenceId_args {
 public:

  SentenceService_getSequenceId_args() {
  }

  virtual ~SentenceService_getSequenceId_args() throw() {}


  bool operator == (const SentenceService_getSequenceId_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const SentenceService_getSequenceId_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SentenceService_getSequenceId_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class SentenceService_getSequenceId_pargs {
 public:


  virtual ~SentenceService_getSequenceId_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _SentenceService_getSequenceId_result__isset {
  _SentenceService_getSequenceId_result__isset() : success(false) {}
  bool success;
} _SentenceService_getSequenceId_result__isset;

class SentenceService_getSequenceId_result {
 public:

  SentenceService_getSequenceId_result() : success(0) {
  }

  virtual ~SentenceService_getSequenceId_result() throw() {}

  int64_t success;

  _SentenceService_getSequenceId_result__isset __isset;

  void __set_success(const int64_t val) {
    success = val;
  }

  bool operator == (const SentenceService_getSequenceId_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const SentenceService_getSequenceId_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SentenceService_getSequenceId_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _SentenceService_getSequenceId_presult__isset {
  _SentenceService_getSequenceId_presult__isset() : success(false) {}
  bool success;
} _SentenceService_getSequenceId_presult__isset;

class SentenceService_getSequenceId_presult {
 public:


  virtual ~SentenceService_getSequenceId_presult() throw() {}

  int64_t* success;

  _SentenceService_getSequenceId_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class SentenceService_getType_args {
 public:

  SentenceService_getType_args() {
  }

  virtual ~SentenceService_getType_args() throw() {}


  bool operator == (const SentenceService_getType_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const SentenceService_getType_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SentenceService_getType_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class SentenceService_getType_pargs {
 public:


  virtual ~SentenceService_getType_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _SentenceService_getType_result__isset {
  _SentenceService_getType_result__isset() : success(false) {}
  bool success;
} _SentenceService_getType_result__isset;

class SentenceService_getType_result {
 public:

  SentenceService_getType_result() : success((SentenceType::type)0) {
  }

  virtual ~SentenceService_getType_result() throw() {}

  SentenceType::type success;

  _SentenceService_getType_result__isset __isset;

  void __set_success(const SentenceType::type val) {
    success = val;
  }

  bool operator == (const SentenceService_getType_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const SentenceService_getType_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SentenceService_getType_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _SentenceService_getType_presult__isset {
  _SentenceService_getType_presult__isset() : success(false) {}
  bool success;
} _SentenceService_getType_presult__isset;

class SentenceService_getType_presult {
 public:


  virtual ~SentenceService_getType_presult() throw() {}

  SentenceType::type* success;

  _SentenceService_getType_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class SentenceService_getUncertaintyConfidence_args {
 public:

  SentenceService_getUncertaintyConfidence_args() {
  }

  virtual ~SentenceService_getUncertaintyConfidence_args() throw() {}


  bool operator == (const SentenceService_getUncertaintyConfidence_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const SentenceService_getUncertaintyConfidence_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SentenceService_getUncertaintyConfidence_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class SentenceService_getUncertaintyConfidence_pargs {
 public:


  virtual ~SentenceService_getUncertaintyConfidence_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _SentenceService_getUncertaintyConfidence_result__isset {
  _SentenceService_getUncertaintyConfidence_result__isset() : success(false) {}
  bool success;
} _SentenceService_getUncertaintyConfidence_result__isset;

class SentenceService_getUncertaintyConfidence_result {
 public:

  SentenceService_getUncertaintyConfidence_result() : success(0) {
  }

  virtual ~SentenceService_getUncertaintyConfidence_result() throw() {}

  double success;

  _SentenceService_getUncertaintyConfidence_result__isset __isset;

  void __set_success(const double val) {
    success = val;
  }

  bool operator == (const SentenceService_getUncertaintyConfidence_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const SentenceService_getUncertaintyConfidence_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SentenceService_getUncertaintyConfidence_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _SentenceService_getUncertaintyConfidence_presult__isset {
  _SentenceService_getUncertaintyConfidence_presult__isset() : success(false) {}
  bool success;
} _SentenceService_getUncertaintyConfidence_presult__isset;

class SentenceService_getUncertaintyConfidence_presult {
 public:


  virtual ~SentenceService_getUncertaintyConfidence_presult() throw() {}

  double* success;

  _SentenceService_getUncertaintyConfidence_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _SentenceService_setNoveltyConfidence_args__isset {
  _SentenceService_setNoveltyConfidence_args__isset() : noveltyConfidence(false) {}
  bool noveltyConfidence;
} _SentenceService_setNoveltyConfidence_args__isset;

class SentenceService_setNoveltyConfidence_args {
 public:

  SentenceService_setNoveltyConfidence_args() : noveltyConfidence(0) {
  }

  virtual ~SentenceService_setNoveltyConfidence_args() throw() {}

  double noveltyConfidence;

  _SentenceService_setNoveltyConfidence_args__isset __isset;

  void __set_noveltyConfidence(const double val) {
    noveltyConfidence = val;
  }

  bool operator == (const SentenceService_setNoveltyConfidence_args & rhs) const
  {
    if (!(noveltyConfidence == rhs.noveltyConfidence))
      return false;
    return true;
  }
  bool operator != (const SentenceService_setNoveltyConfidence_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SentenceService_setNoveltyConfidence_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class SentenceService_setNoveltyConfidence_pargs {
 public:


  virtual ~SentenceService_setNoveltyConfidence_pargs() throw() {}

  const double* noveltyConfidence;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class SentenceService_setNoveltyConfidence_result {
 public:

  SentenceService_setNoveltyConfidence_result() {
  }

  virtual ~SentenceService_setNoveltyConfidence_result() throw() {}


  bool operator == (const SentenceService_setNoveltyConfidence_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const SentenceService_setNoveltyConfidence_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SentenceService_setNoveltyConfidence_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class SentenceService_setNoveltyConfidence_presult {
 public:


  virtual ~SentenceService_setNoveltyConfidence_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _SentenceService_setPunctuation_args__isset {
  _SentenceService_setPunctuation_args__isset() : punctuation(false) {}
  bool punctuation;
} _SentenceService_setPunctuation_args__isset;

class SentenceService_setPunctuation_args {
 public:

  SentenceService_setPunctuation_args() : punctuation() {
  }

  virtual ~SentenceService_setPunctuation_args() throw() {}

  std::string punctuation;

  _SentenceService_setPunctuation_args__isset __isset;

  void __set_punctuation(const std::string& val) {
    punctuation = val;
  }

  bool operator == (const SentenceService_setPunctuation_args & rhs) const
  {
    if (!(punctuation == rhs.punctuation))
      return false;
    return true;
  }
  bool operator != (const SentenceService_setPunctuation_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SentenceService_setPunctuation_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class SentenceService_setPunctuation_pargs {
 public:


  virtual ~SentenceService_setPunctuation_pargs() throw() {}

  const std::string* punctuation;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class SentenceService_setPunctuation_result {
 public:

  SentenceService_setPunctuation_result() {
  }

  virtual ~SentenceService_setPunctuation_result() throw() {}


  bool operator == (const SentenceService_setPunctuation_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const SentenceService_setPunctuation_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SentenceService_setPunctuation_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class SentenceService_setPunctuation_presult {
 public:


  virtual ~SentenceService_setPunctuation_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _SentenceService_setType_args__isset {
  _SentenceService_setType_args__isset() : type(false) {}
  bool type;
} _SentenceService_setType_args__isset;

class SentenceService_setType_args {
 public:

  SentenceService_setType_args() : type((SentenceType::type)0) {
  }

  virtual ~SentenceService_setType_args() throw() {}

  SentenceType::type type;

  _SentenceService_setType_args__isset __isset;

  void __set_type(const SentenceType::type val) {
    type = val;
  }

  bool operator == (const SentenceService_setType_args & rhs) const
  {
    if (!(type == rhs.type))
      return false;
    return true;
  }
  bool operator != (const SentenceService_setType_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SentenceService_setType_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class SentenceService_setType_pargs {
 public:


  virtual ~SentenceService_setType_pargs() throw() {}

  const SentenceType::type* type;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class SentenceService_setType_result {
 public:

  SentenceService_setType_result() {
  }

  virtual ~SentenceService_setType_result() throw() {}


  bool operator == (const SentenceService_setType_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const SentenceService_setType_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SentenceService_setType_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class SentenceService_setType_presult {
 public:


  virtual ~SentenceService_setType_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _SentenceService_setUncertaintyConfidence_args__isset {
  _SentenceService_setUncertaintyConfidence_args__isset() : uncertaintyConfidence(false) {}
  bool uncertaintyConfidence;
} _SentenceService_setUncertaintyConfidence_args__isset;

class SentenceService_setUncertaintyConfidence_args {
 public:

  SentenceService_setUncertaintyConfidence_args() : uncertaintyConfidence(0) {
  }

  virtual ~SentenceService_setUncertaintyConfidence_args() throw() {}

  double uncertaintyConfidence;

  _SentenceService_setUncertaintyConfidence_args__isset __isset;

  void __set_uncertaintyConfidence(const double val) {
    uncertaintyConfidence = val;
  }

  bool operator == (const SentenceService_setUncertaintyConfidence_args & rhs) const
  {
    if (!(uncertaintyConfidence == rhs.uncertaintyConfidence))
      return false;
    return true;
  }
  bool operator != (const SentenceService_setUncertaintyConfidence_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SentenceService_setUncertaintyConfidence_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class SentenceService_setUncertaintyConfidence_pargs {
 public:


  virtual ~SentenceService_setUncertaintyConfidence_pargs() throw() {}

  const double* uncertaintyConfidence;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class SentenceService_setUncertaintyConfidence_result {
 public:

  SentenceService_setUncertaintyConfidence_result() {
  }

  virtual ~SentenceService_setUncertaintyConfidence_result() throw() {}


  bool operator == (const SentenceService_setUncertaintyConfidence_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const SentenceService_setUncertaintyConfidence_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SentenceService_setUncertaintyConfidence_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class SentenceService_setUncertaintyConfidence_presult {
 public:


  virtual ~SentenceService_setUncertaintyConfidence_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class SentenceServiceClient : virtual public SentenceServiceIf, public ChunkServiceClient {
 public:
  SentenceServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    ChunkServiceClient(prot, prot) {}
  SentenceServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    ChunkServiceClient(iprot, oprot) {}
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  double getNoveltyConfidence();
  void send_getNoveltyConfidence();
  double recv_getNoveltyConfidence();
  void getPunctuation(std::string& _return);
  void send_getPunctuation();
  void recv_getPunctuation(std::string& _return);
  int64_t getSequenceId();
  void send_getSequenceId();
  int64_t recv_getSequenceId();
  SentenceType::type getType();
  void send_getType();
  SentenceType::type recv_getType();
  double getUncertaintyConfidence();
  void send_getUncertaintyConfidence();
  double recv_getUncertaintyConfidence();
  void setNoveltyConfidence(const double noveltyConfidence);
  void send_setNoveltyConfidence(const double noveltyConfidence);
  void recv_setNoveltyConfidence();
  void setPunctuation(const std::string& punctuation);
  void send_setPunctuation(const std::string& punctuation);
  void recv_setPunctuation();
  void setType(const SentenceType::type type);
  void send_setType(const SentenceType::type type);
  void recv_setType();
  void setUncertaintyConfidence(const double uncertaintyConfidence);
  void send_setUncertaintyConfidence(const double uncertaintyConfidence);
  void recv_setUncertaintyConfidence();
};

class SentenceServiceProcessor : public ChunkServiceProcessor {
 protected:
  boost::shared_ptr<SentenceServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (SentenceServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_getNoveltyConfidence(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getPunctuation(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getSequenceId(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getType(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getUncertaintyConfidence(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setNoveltyConfidence(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setPunctuation(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setType(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setUncertaintyConfidence(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  SentenceServiceProcessor(boost::shared_ptr<SentenceServiceIf> iface) :
    ChunkServiceProcessor(iface),
    iface_(iface) {
    processMap_["getNoveltyConfidence"] = &SentenceServiceProcessor::process_getNoveltyConfidence;
    processMap_["getPunctuation"] = &SentenceServiceProcessor::process_getPunctuation;
    processMap_["getSequenceId"] = &SentenceServiceProcessor::process_getSequenceId;
    processMap_["getType"] = &SentenceServiceProcessor::process_getType;
    processMap_["getUncertaintyConfidence"] = &SentenceServiceProcessor::process_getUncertaintyConfidence;
    processMap_["setNoveltyConfidence"] = &SentenceServiceProcessor::process_setNoveltyConfidence;
    processMap_["setPunctuation"] = &SentenceServiceProcessor::process_setPunctuation;
    processMap_["setType"] = &SentenceServiceProcessor::process_setType;
    processMap_["setUncertaintyConfidence"] = &SentenceServiceProcessor::process_setUncertaintyConfidence;
  }

  virtual ~SentenceServiceProcessor() {}
};

class SentenceServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  SentenceServiceProcessorFactory(const ::boost::shared_ptr< SentenceServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< SentenceServiceIfFactory > handlerFactory_;
};

class SentenceServiceMultiface : virtual public SentenceServiceIf, public ChunkServiceMultiface {
 public:
  SentenceServiceMultiface(std::vector<boost::shared_ptr<SentenceServiceIf> >& ifaces) : ifaces_(ifaces) {
    std::vector<boost::shared_ptr<SentenceServiceIf> >::iterator iter;
    for (iter = ifaces.begin(); iter != ifaces.end(); ++iter) {
      ChunkServiceMultiface::add(*iter);
    }
  }
  virtual ~SentenceServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<SentenceServiceIf> > ifaces_;
  SentenceServiceMultiface() {}
  void add(boost::shared_ptr<SentenceServiceIf> iface) {
    ChunkServiceMultiface::add(iface);
    ifaces_.push_back(iface);
  }
 public:
  double getNoveltyConfidence() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getNoveltyConfidence();
    }
    return ifaces_[i]->getNoveltyConfidence();
  }

  void getPunctuation(std::string& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getPunctuation(_return);
    }
    ifaces_[i]->getPunctuation(_return);
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

  SentenceType::type getType() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getType();
    }
    return ifaces_[i]->getType();
  }

  double getUncertaintyConfidence() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getUncertaintyConfidence();
    }
    return ifaces_[i]->getUncertaintyConfidence();
  }

  void setNoveltyConfidence(const double noveltyConfidence) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setNoveltyConfidence(noveltyConfidence);
    }
    ifaces_[i]->setNoveltyConfidence(noveltyConfidence);
  }

  void setPunctuation(const std::string& punctuation) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setPunctuation(punctuation);
    }
    ifaces_[i]->setPunctuation(punctuation);
  }

  void setType(const SentenceType::type type) {
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