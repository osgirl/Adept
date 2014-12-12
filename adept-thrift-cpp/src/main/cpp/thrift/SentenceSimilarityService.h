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
#ifndef SentenceSimilarityService_H
#define SentenceSimilarityService_H

#include <thrift/TDispatchProcessor.h>
#include "common_types.h"
#include "ItemService.h"

namespace thrift { namespace adept { namespace common {

class SentenceSimilarityServiceIf : virtual public ItemServiceIf {
 public:
  virtual ~SentenceSimilarityServiceIf() {}
  virtual void getSentence1(Sentence& _return) = 0;
  virtual void getSentence2(Sentence& _return) = 0;
  virtual double getSimilarity() = 0;
};

class SentenceSimilarityServiceIfFactory : virtual public ItemServiceIfFactory {
 public:
  typedef SentenceSimilarityServiceIf Handler;

  virtual ~SentenceSimilarityServiceIfFactory() {}

  virtual SentenceSimilarityServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ItemServiceIf* /* handler */) = 0;
};

class SentenceSimilarityServiceIfSingletonFactory : virtual public SentenceSimilarityServiceIfFactory {
 public:
  SentenceSimilarityServiceIfSingletonFactory(const boost::shared_ptr<SentenceSimilarityServiceIf>& iface) : iface_(iface) {}
  virtual ~SentenceSimilarityServiceIfSingletonFactory() {}

  virtual SentenceSimilarityServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ItemServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<SentenceSimilarityServiceIf> iface_;
};

class SentenceSimilarityServiceNull : virtual public SentenceSimilarityServiceIf , virtual public ItemServiceNull {
 public:
  virtual ~SentenceSimilarityServiceNull() {}
  void getSentence1(Sentence& /* _return */) {
    return;
  }
  void getSentence2(Sentence& /* _return */) {
    return;
  }
  double getSimilarity() {
    double _return = (double)0;
    return _return;
  }
};


class SentenceSimilarityService_getSentence1_args {
 public:

  SentenceSimilarityService_getSentence1_args() {
  }

  virtual ~SentenceSimilarityService_getSentence1_args() throw() {}


  bool operator == (const SentenceSimilarityService_getSentence1_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const SentenceSimilarityService_getSentence1_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SentenceSimilarityService_getSentence1_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class SentenceSimilarityService_getSentence1_pargs {
 public:


  virtual ~SentenceSimilarityService_getSentence1_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _SentenceSimilarityService_getSentence1_result__isset {
  _SentenceSimilarityService_getSentence1_result__isset() : success(false) {}
  bool success;
} _SentenceSimilarityService_getSentence1_result__isset;

class SentenceSimilarityService_getSentence1_result {
 public:

  SentenceSimilarityService_getSentence1_result() {
  }

  virtual ~SentenceSimilarityService_getSentence1_result() throw() {}

  Sentence success;

  _SentenceSimilarityService_getSentence1_result__isset __isset;

  void __set_success(const Sentence& val) {
    success = val;
  }

  bool operator == (const SentenceSimilarityService_getSentence1_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const SentenceSimilarityService_getSentence1_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SentenceSimilarityService_getSentence1_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _SentenceSimilarityService_getSentence1_presult__isset {
  _SentenceSimilarityService_getSentence1_presult__isset() : success(false) {}
  bool success;
} _SentenceSimilarityService_getSentence1_presult__isset;

class SentenceSimilarityService_getSentence1_presult {
 public:


  virtual ~SentenceSimilarityService_getSentence1_presult() throw() {}

  Sentence* success;

  _SentenceSimilarityService_getSentence1_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class SentenceSimilarityService_getSentence2_args {
 public:

  SentenceSimilarityService_getSentence2_args() {
  }

  virtual ~SentenceSimilarityService_getSentence2_args() throw() {}


  bool operator == (const SentenceSimilarityService_getSentence2_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const SentenceSimilarityService_getSentence2_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SentenceSimilarityService_getSentence2_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class SentenceSimilarityService_getSentence2_pargs {
 public:


  virtual ~SentenceSimilarityService_getSentence2_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _SentenceSimilarityService_getSentence2_result__isset {
  _SentenceSimilarityService_getSentence2_result__isset() : success(false) {}
  bool success;
} _SentenceSimilarityService_getSentence2_result__isset;

class SentenceSimilarityService_getSentence2_result {
 public:

  SentenceSimilarityService_getSentence2_result() {
  }

  virtual ~SentenceSimilarityService_getSentence2_result() throw() {}

  Sentence success;

  _SentenceSimilarityService_getSentence2_result__isset __isset;

  void __set_success(const Sentence& val) {
    success = val;
  }

  bool operator == (const SentenceSimilarityService_getSentence2_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const SentenceSimilarityService_getSentence2_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SentenceSimilarityService_getSentence2_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _SentenceSimilarityService_getSentence2_presult__isset {
  _SentenceSimilarityService_getSentence2_presult__isset() : success(false) {}
  bool success;
} _SentenceSimilarityService_getSentence2_presult__isset;

class SentenceSimilarityService_getSentence2_presult {
 public:


  virtual ~SentenceSimilarityService_getSentence2_presult() throw() {}

  Sentence* success;

  _SentenceSimilarityService_getSentence2_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class SentenceSimilarityService_getSimilarity_args {
 public:

  SentenceSimilarityService_getSimilarity_args() {
  }

  virtual ~SentenceSimilarityService_getSimilarity_args() throw() {}


  bool operator == (const SentenceSimilarityService_getSimilarity_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const SentenceSimilarityService_getSimilarity_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SentenceSimilarityService_getSimilarity_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class SentenceSimilarityService_getSimilarity_pargs {
 public:


  virtual ~SentenceSimilarityService_getSimilarity_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _SentenceSimilarityService_getSimilarity_result__isset {
  _SentenceSimilarityService_getSimilarity_result__isset() : success(false) {}
  bool success;
} _SentenceSimilarityService_getSimilarity_result__isset;

class SentenceSimilarityService_getSimilarity_result {
 public:

  SentenceSimilarityService_getSimilarity_result() : success(0) {
  }

  virtual ~SentenceSimilarityService_getSimilarity_result() throw() {}

  double success;

  _SentenceSimilarityService_getSimilarity_result__isset __isset;

  void __set_success(const double val) {
    success = val;
  }

  bool operator == (const SentenceSimilarityService_getSimilarity_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const SentenceSimilarityService_getSimilarity_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SentenceSimilarityService_getSimilarity_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _SentenceSimilarityService_getSimilarity_presult__isset {
  _SentenceSimilarityService_getSimilarity_presult__isset() : success(false) {}
  bool success;
} _SentenceSimilarityService_getSimilarity_presult__isset;

class SentenceSimilarityService_getSimilarity_presult {
 public:


  virtual ~SentenceSimilarityService_getSimilarity_presult() throw() {}

  double* success;

  _SentenceSimilarityService_getSimilarity_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class SentenceSimilarityServiceClient : virtual public SentenceSimilarityServiceIf, public ItemServiceClient {
 public:
  SentenceSimilarityServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    ItemServiceClient(prot, prot) {}
  SentenceSimilarityServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    ItemServiceClient(iprot, oprot) {}
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void getSentence1(Sentence& _return);
  void send_getSentence1();
  void recv_getSentence1(Sentence& _return);
  void getSentence2(Sentence& _return);
  void send_getSentence2();
  void recv_getSentence2(Sentence& _return);
  double getSimilarity();
  void send_getSimilarity();
  double recv_getSimilarity();
};

class SentenceSimilarityServiceProcessor : public ItemServiceProcessor {
 protected:
  boost::shared_ptr<SentenceSimilarityServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (SentenceSimilarityServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_getSentence1(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getSentence2(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getSimilarity(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  SentenceSimilarityServiceProcessor(boost::shared_ptr<SentenceSimilarityServiceIf> iface) :
    ItemServiceProcessor(iface),
    iface_(iface) {
    processMap_["getSentence1"] = &SentenceSimilarityServiceProcessor::process_getSentence1;
    processMap_["getSentence2"] = &SentenceSimilarityServiceProcessor::process_getSentence2;
    processMap_["getSimilarity"] = &SentenceSimilarityServiceProcessor::process_getSimilarity;
  }

  virtual ~SentenceSimilarityServiceProcessor() {}
};

class SentenceSimilarityServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  SentenceSimilarityServiceProcessorFactory(const ::boost::shared_ptr< SentenceSimilarityServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< SentenceSimilarityServiceIfFactory > handlerFactory_;
};

class SentenceSimilarityServiceMultiface : virtual public SentenceSimilarityServiceIf, public ItemServiceMultiface {
 public:
  SentenceSimilarityServiceMultiface(std::vector<boost::shared_ptr<SentenceSimilarityServiceIf> >& ifaces) : ifaces_(ifaces) {
    std::vector<boost::shared_ptr<SentenceSimilarityServiceIf> >::iterator iter;
    for (iter = ifaces.begin(); iter != ifaces.end(); ++iter) {
      ItemServiceMultiface::add(*iter);
    }
  }
  virtual ~SentenceSimilarityServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<SentenceSimilarityServiceIf> > ifaces_;
  SentenceSimilarityServiceMultiface() {}
  void add(boost::shared_ptr<SentenceSimilarityServiceIf> iface) {
    ItemServiceMultiface::add(iface);
    ifaces_.push_back(iface);
  }
 public:
  void getSentence1(Sentence& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getSentence1(_return);
    }
    ifaces_[i]->getSentence1(_return);
    return;
  }

  void getSentence2(Sentence& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getSentence2(_return);
    }
    ifaces_[i]->getSentence2(_return);
    return;
  }

  double getSimilarity() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getSimilarity();
    }
    return ifaces_[i]->getSimilarity();
  }

};

}}} // namespace

#endif
