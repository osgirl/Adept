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
#ifndef ChunkService_H
#define ChunkService_H

#include <thrift/TDispatchProcessor.h>
#include "common_types.h"
#include "ItemService.h"

namespace thrift { namespace adept { namespace common {

class ChunkServiceIf : virtual public ItemServiceIf {
 public:
  virtual ~ChunkServiceIf() {}
  virtual bool Contains(const ChunkUnion& chunk) = 0;
  virtual bool equals(const ChunkUnion& obj) = 0;
  virtual void getContainingChunk(ChunkUnion& _return, const std::vector<ChunkUnion> & chunks) = 0;
  virtual void getMatchingChunk(ChunkUnion& _return, const std::vector<ChunkUnion> & chunks) = 0;
  virtual void getTokenOffset(TokenOffset& _return) = 0;
  virtual void getTokenStream(TokenStream& _return) = 0;
  virtual int32_t hashCode() = 0;
  virtual void setTokenStream(const TokenStream& tokenStream) = 0;
};

class ChunkServiceIfFactory : virtual public ItemServiceIfFactory {
 public:
  typedef ChunkServiceIf Handler;

  virtual ~ChunkServiceIfFactory() {}

  virtual ChunkServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ItemServiceIf* /* handler */) = 0;
};

class ChunkServiceIfSingletonFactory : virtual public ChunkServiceIfFactory {
 public:
  ChunkServiceIfSingletonFactory(const boost::shared_ptr<ChunkServiceIf>& iface) : iface_(iface) {}
  virtual ~ChunkServiceIfSingletonFactory() {}

  virtual ChunkServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ItemServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<ChunkServiceIf> iface_;
};

class ChunkServiceNull : virtual public ChunkServiceIf , virtual public ItemServiceNull {
 public:
  virtual ~ChunkServiceNull() {}
  bool Contains(const ChunkUnion& /* chunk */) {
    bool _return = false;
    return _return;
  }
  bool equals(const ChunkUnion& /* obj */) {
    bool _return = false;
    return _return;
  }
  void getContainingChunk(ChunkUnion& /* _return */, const std::vector<ChunkUnion> & /* chunks */) {
    return;
  }
  void getMatchingChunk(ChunkUnion& /* _return */, const std::vector<ChunkUnion> & /* chunks */) {
    return;
  }
  void getTokenOffset(TokenOffset& /* _return */) {
    return;
  }
  void getTokenStream(TokenStream& /* _return */) {
    return;
  }
  int32_t hashCode() {
    int32_t _return = 0;
    return _return;
  }
  void setTokenStream(const TokenStream& /* tokenStream */) {
    return;
  }
};

typedef struct _ChunkService_Contains_args__isset {
  _ChunkService_Contains_args__isset() : chunk(false) {}
  bool chunk;
} _ChunkService_Contains_args__isset;

class ChunkService_Contains_args {
 public:

  ChunkService_Contains_args() {
  }

  virtual ~ChunkService_Contains_args() throw() {}

  ChunkUnion chunk;

  _ChunkService_Contains_args__isset __isset;

  void __set_chunk(const ChunkUnion& val) {
    chunk = val;
  }

  bool operator == (const ChunkService_Contains_args & rhs) const
  {
    if (!(chunk == rhs.chunk))
      return false;
    return true;
  }
  bool operator != (const ChunkService_Contains_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ChunkService_Contains_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ChunkService_Contains_pargs {
 public:


  virtual ~ChunkService_Contains_pargs() throw() {}

  const ChunkUnion* chunk;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ChunkService_Contains_result__isset {
  _ChunkService_Contains_result__isset() : success(false) {}
  bool success;
} _ChunkService_Contains_result__isset;

class ChunkService_Contains_result {
 public:

  ChunkService_Contains_result() : success(0) {
  }

  virtual ~ChunkService_Contains_result() throw() {}

  bool success;

  _ChunkService_Contains_result__isset __isset;

  void __set_success(const bool val) {
    success = val;
  }

  bool operator == (const ChunkService_Contains_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ChunkService_Contains_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ChunkService_Contains_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ChunkService_Contains_presult__isset {
  _ChunkService_Contains_presult__isset() : success(false) {}
  bool success;
} _ChunkService_Contains_presult__isset;

class ChunkService_Contains_presult {
 public:


  virtual ~ChunkService_Contains_presult() throw() {}

  bool* success;

  _ChunkService_Contains_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _ChunkService_equals_args__isset {
  _ChunkService_equals_args__isset() : obj(false) {}
  bool obj;
} _ChunkService_equals_args__isset;

class ChunkService_equals_args {
 public:

  ChunkService_equals_args() {
  }

  virtual ~ChunkService_equals_args() throw() {}

  ChunkUnion obj;

  _ChunkService_equals_args__isset __isset;

  void __set_obj(const ChunkUnion& val) {
    obj = val;
  }

  bool operator == (const ChunkService_equals_args & rhs) const
  {
    if (!(obj == rhs.obj))
      return false;
    return true;
  }
  bool operator != (const ChunkService_equals_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ChunkService_equals_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ChunkService_equals_pargs {
 public:


  virtual ~ChunkService_equals_pargs() throw() {}

  const ChunkUnion* obj;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ChunkService_equals_result__isset {
  _ChunkService_equals_result__isset() : success(false) {}
  bool success;
} _ChunkService_equals_result__isset;

class ChunkService_equals_result {
 public:

  ChunkService_equals_result() : success(0) {
  }

  virtual ~ChunkService_equals_result() throw() {}

  bool success;

  _ChunkService_equals_result__isset __isset;

  void __set_success(const bool val) {
    success = val;
  }

  bool operator == (const ChunkService_equals_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ChunkService_equals_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ChunkService_equals_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ChunkService_equals_presult__isset {
  _ChunkService_equals_presult__isset() : success(false) {}
  bool success;
} _ChunkService_equals_presult__isset;

class ChunkService_equals_presult {
 public:


  virtual ~ChunkService_equals_presult() throw() {}

  bool* success;

  _ChunkService_equals_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _ChunkService_getContainingChunk_args__isset {
  _ChunkService_getContainingChunk_args__isset() : chunks(false) {}
  bool chunks;
} _ChunkService_getContainingChunk_args__isset;

class ChunkService_getContainingChunk_args {
 public:

  ChunkService_getContainingChunk_args() {
  }

  virtual ~ChunkService_getContainingChunk_args() throw() {}

  std::vector<ChunkUnion>  chunks;

  _ChunkService_getContainingChunk_args__isset __isset;

  void __set_chunks(const std::vector<ChunkUnion> & val) {
    chunks = val;
  }

  bool operator == (const ChunkService_getContainingChunk_args & rhs) const
  {
    if (!(chunks == rhs.chunks))
      return false;
    return true;
  }
  bool operator != (const ChunkService_getContainingChunk_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ChunkService_getContainingChunk_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ChunkService_getContainingChunk_pargs {
 public:


  virtual ~ChunkService_getContainingChunk_pargs() throw() {}

  const std::vector<ChunkUnion> * chunks;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ChunkService_getContainingChunk_result__isset {
  _ChunkService_getContainingChunk_result__isset() : success(false) {}
  bool success;
} _ChunkService_getContainingChunk_result__isset;

class ChunkService_getContainingChunk_result {
 public:

  ChunkService_getContainingChunk_result() {
  }

  virtual ~ChunkService_getContainingChunk_result() throw() {}

  ChunkUnion success;

  _ChunkService_getContainingChunk_result__isset __isset;

  void __set_success(const ChunkUnion& val) {
    success = val;
  }

  bool operator == (const ChunkService_getContainingChunk_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ChunkService_getContainingChunk_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ChunkService_getContainingChunk_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ChunkService_getContainingChunk_presult__isset {
  _ChunkService_getContainingChunk_presult__isset() : success(false) {}
  bool success;
} _ChunkService_getContainingChunk_presult__isset;

class ChunkService_getContainingChunk_presult {
 public:


  virtual ~ChunkService_getContainingChunk_presult() throw() {}

  ChunkUnion* success;

  _ChunkService_getContainingChunk_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _ChunkService_getMatchingChunk_args__isset {
  _ChunkService_getMatchingChunk_args__isset() : chunks(false) {}
  bool chunks;
} _ChunkService_getMatchingChunk_args__isset;

class ChunkService_getMatchingChunk_args {
 public:

  ChunkService_getMatchingChunk_args() {
  }

  virtual ~ChunkService_getMatchingChunk_args() throw() {}

  std::vector<ChunkUnion>  chunks;

  _ChunkService_getMatchingChunk_args__isset __isset;

  void __set_chunks(const std::vector<ChunkUnion> & val) {
    chunks = val;
  }

  bool operator == (const ChunkService_getMatchingChunk_args & rhs) const
  {
    if (!(chunks == rhs.chunks))
      return false;
    return true;
  }
  bool operator != (const ChunkService_getMatchingChunk_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ChunkService_getMatchingChunk_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ChunkService_getMatchingChunk_pargs {
 public:


  virtual ~ChunkService_getMatchingChunk_pargs() throw() {}

  const std::vector<ChunkUnion> * chunks;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ChunkService_getMatchingChunk_result__isset {
  _ChunkService_getMatchingChunk_result__isset() : success(false) {}
  bool success;
} _ChunkService_getMatchingChunk_result__isset;

class ChunkService_getMatchingChunk_result {
 public:

  ChunkService_getMatchingChunk_result() {
  }

  virtual ~ChunkService_getMatchingChunk_result() throw() {}

  ChunkUnion success;

  _ChunkService_getMatchingChunk_result__isset __isset;

  void __set_success(const ChunkUnion& val) {
    success = val;
  }

  bool operator == (const ChunkService_getMatchingChunk_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ChunkService_getMatchingChunk_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ChunkService_getMatchingChunk_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ChunkService_getMatchingChunk_presult__isset {
  _ChunkService_getMatchingChunk_presult__isset() : success(false) {}
  bool success;
} _ChunkService_getMatchingChunk_presult__isset;

class ChunkService_getMatchingChunk_presult {
 public:


  virtual ~ChunkService_getMatchingChunk_presult() throw() {}

  ChunkUnion* success;

  _ChunkService_getMatchingChunk_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class ChunkService_getTokenOffset_args {
 public:

  ChunkService_getTokenOffset_args() {
  }

  virtual ~ChunkService_getTokenOffset_args() throw() {}


  bool operator == (const ChunkService_getTokenOffset_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ChunkService_getTokenOffset_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ChunkService_getTokenOffset_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ChunkService_getTokenOffset_pargs {
 public:


  virtual ~ChunkService_getTokenOffset_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ChunkService_getTokenOffset_result__isset {
  _ChunkService_getTokenOffset_result__isset() : success(false) {}
  bool success;
} _ChunkService_getTokenOffset_result__isset;

class ChunkService_getTokenOffset_result {
 public:

  ChunkService_getTokenOffset_result() {
  }

  virtual ~ChunkService_getTokenOffset_result() throw() {}

  TokenOffset success;

  _ChunkService_getTokenOffset_result__isset __isset;

  void __set_success(const TokenOffset& val) {
    success = val;
  }

  bool operator == (const ChunkService_getTokenOffset_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ChunkService_getTokenOffset_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ChunkService_getTokenOffset_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ChunkService_getTokenOffset_presult__isset {
  _ChunkService_getTokenOffset_presult__isset() : success(false) {}
  bool success;
} _ChunkService_getTokenOffset_presult__isset;

class ChunkService_getTokenOffset_presult {
 public:


  virtual ~ChunkService_getTokenOffset_presult() throw() {}

  TokenOffset* success;

  _ChunkService_getTokenOffset_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class ChunkService_getTokenStream_args {
 public:

  ChunkService_getTokenStream_args() {
  }

  virtual ~ChunkService_getTokenStream_args() throw() {}


  bool operator == (const ChunkService_getTokenStream_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ChunkService_getTokenStream_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ChunkService_getTokenStream_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ChunkService_getTokenStream_pargs {
 public:


  virtual ~ChunkService_getTokenStream_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ChunkService_getTokenStream_result__isset {
  _ChunkService_getTokenStream_result__isset() : success(false) {}
  bool success;
} _ChunkService_getTokenStream_result__isset;

class ChunkService_getTokenStream_result {
 public:

  ChunkService_getTokenStream_result() {
  }

  virtual ~ChunkService_getTokenStream_result() throw() {}

  TokenStream success;

  _ChunkService_getTokenStream_result__isset __isset;

  void __set_success(const TokenStream& val) {
    success = val;
  }

  bool operator == (const ChunkService_getTokenStream_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ChunkService_getTokenStream_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ChunkService_getTokenStream_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ChunkService_getTokenStream_presult__isset {
  _ChunkService_getTokenStream_presult__isset() : success(false) {}
  bool success;
} _ChunkService_getTokenStream_presult__isset;

class ChunkService_getTokenStream_presult {
 public:


  virtual ~ChunkService_getTokenStream_presult() throw() {}

  TokenStream* success;

  _ChunkService_getTokenStream_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class ChunkService_hashCode_args {
 public:

  ChunkService_hashCode_args() {
  }

  virtual ~ChunkService_hashCode_args() throw() {}


  bool operator == (const ChunkService_hashCode_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ChunkService_hashCode_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ChunkService_hashCode_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ChunkService_hashCode_pargs {
 public:


  virtual ~ChunkService_hashCode_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ChunkService_hashCode_result__isset {
  _ChunkService_hashCode_result__isset() : success(false) {}
  bool success;
} _ChunkService_hashCode_result__isset;

class ChunkService_hashCode_result {
 public:

  ChunkService_hashCode_result() : success(0) {
  }

  virtual ~ChunkService_hashCode_result() throw() {}

  int32_t success;

  _ChunkService_hashCode_result__isset __isset;

  void __set_success(const int32_t val) {
    success = val;
  }

  bool operator == (const ChunkService_hashCode_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ChunkService_hashCode_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ChunkService_hashCode_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ChunkService_hashCode_presult__isset {
  _ChunkService_hashCode_presult__isset() : success(false) {}
  bool success;
} _ChunkService_hashCode_presult__isset;

class ChunkService_hashCode_presult {
 public:


  virtual ~ChunkService_hashCode_presult() throw() {}

  int32_t* success;

  _ChunkService_hashCode_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _ChunkService_setTokenStream_args__isset {
  _ChunkService_setTokenStream_args__isset() : tokenStream(false) {}
  bool tokenStream;
} _ChunkService_setTokenStream_args__isset;

class ChunkService_setTokenStream_args {
 public:

  ChunkService_setTokenStream_args() {
  }

  virtual ~ChunkService_setTokenStream_args() throw() {}

  TokenStream tokenStream;

  _ChunkService_setTokenStream_args__isset __isset;

  void __set_tokenStream(const TokenStream& val) {
    tokenStream = val;
  }

  bool operator == (const ChunkService_setTokenStream_args & rhs) const
  {
    if (!(tokenStream == rhs.tokenStream))
      return false;
    return true;
  }
  bool operator != (const ChunkService_setTokenStream_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ChunkService_setTokenStream_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ChunkService_setTokenStream_pargs {
 public:


  virtual ~ChunkService_setTokenStream_pargs() throw() {}

  const TokenStream* tokenStream;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ChunkService_setTokenStream_result {
 public:

  ChunkService_setTokenStream_result() {
  }

  virtual ~ChunkService_setTokenStream_result() throw() {}


  bool operator == (const ChunkService_setTokenStream_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ChunkService_setTokenStream_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ChunkService_setTokenStream_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ChunkService_setTokenStream_presult {
 public:


  virtual ~ChunkService_setTokenStream_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class ChunkServiceClient : virtual public ChunkServiceIf, public ItemServiceClient {
 public:
  ChunkServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    ItemServiceClient(prot, prot) {}
  ChunkServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    ItemServiceClient(iprot, oprot) {}
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  bool Contains(const ChunkUnion& chunk);
  void send_Contains(const ChunkUnion& chunk);
  bool recv_Contains();
  bool equals(const ChunkUnion& obj);
  void send_equals(const ChunkUnion& obj);
  bool recv_equals();
  void getContainingChunk(ChunkUnion& _return, const std::vector<ChunkUnion> & chunks);
  void send_getContainingChunk(const std::vector<ChunkUnion> & chunks);
  void recv_getContainingChunk(ChunkUnion& _return);
  void getMatchingChunk(ChunkUnion& _return, const std::vector<ChunkUnion> & chunks);
  void send_getMatchingChunk(const std::vector<ChunkUnion> & chunks);
  void recv_getMatchingChunk(ChunkUnion& _return);
  void getTokenOffset(TokenOffset& _return);
  void send_getTokenOffset();
  void recv_getTokenOffset(TokenOffset& _return);
  void getTokenStream(TokenStream& _return);
  void send_getTokenStream();
  void recv_getTokenStream(TokenStream& _return);
  int32_t hashCode();
  void send_hashCode();
  int32_t recv_hashCode();
  void setTokenStream(const TokenStream& tokenStream);
  void send_setTokenStream(const TokenStream& tokenStream);
  void recv_setTokenStream();
};

class ChunkServiceProcessor : public ItemServiceProcessor {
 protected:
  boost::shared_ptr<ChunkServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (ChunkServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_Contains(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_equals(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getContainingChunk(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getMatchingChunk(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getTokenOffset(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getTokenStream(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_hashCode(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setTokenStream(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  ChunkServiceProcessor(boost::shared_ptr<ChunkServiceIf> iface) :
    ItemServiceProcessor(iface),
    iface_(iface) {
    processMap_["Contains"] = &ChunkServiceProcessor::process_Contains;
    processMap_["equals"] = &ChunkServiceProcessor::process_equals;
    processMap_["getContainingChunk"] = &ChunkServiceProcessor::process_getContainingChunk;
    processMap_["getMatchingChunk"] = &ChunkServiceProcessor::process_getMatchingChunk;
    processMap_["getTokenOffset"] = &ChunkServiceProcessor::process_getTokenOffset;
    processMap_["getTokenStream"] = &ChunkServiceProcessor::process_getTokenStream;
    processMap_["hashCode"] = &ChunkServiceProcessor::process_hashCode;
    processMap_["setTokenStream"] = &ChunkServiceProcessor::process_setTokenStream;
  }

  virtual ~ChunkServiceProcessor() {}
};

class ChunkServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  ChunkServiceProcessorFactory(const ::boost::shared_ptr< ChunkServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< ChunkServiceIfFactory > handlerFactory_;
};

class ChunkServiceMultiface : virtual public ChunkServiceIf, public ItemServiceMultiface {
 public:
  ChunkServiceMultiface(std::vector<boost::shared_ptr<ChunkServiceIf> >& ifaces) : ifaces_(ifaces) {
    std::vector<boost::shared_ptr<ChunkServiceIf> >::iterator iter;
    for (iter = ifaces.begin(); iter != ifaces.end(); ++iter) {
      ItemServiceMultiface::add(*iter);
    }
  }
  virtual ~ChunkServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<ChunkServiceIf> > ifaces_;
  ChunkServiceMultiface() {}
  void add(boost::shared_ptr<ChunkServiceIf> iface) {
    ItemServiceMultiface::add(iface);
    ifaces_.push_back(iface);
  }
 public:
  bool Contains(const ChunkUnion& chunk) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Contains(chunk);
    }
    return ifaces_[i]->Contains(chunk);
  }

  bool equals(const ChunkUnion& obj) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->equals(obj);
    }
    return ifaces_[i]->equals(obj);
  }

  void getContainingChunk(ChunkUnion& _return, const std::vector<ChunkUnion> & chunks) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getContainingChunk(_return, chunks);
    }
    ifaces_[i]->getContainingChunk(_return, chunks);
    return;
  }

  void getMatchingChunk(ChunkUnion& _return, const std::vector<ChunkUnion> & chunks) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getMatchingChunk(_return, chunks);
    }
    ifaces_[i]->getMatchingChunk(_return, chunks);
    return;
  }

  void getTokenOffset(TokenOffset& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getTokenOffset(_return);
    }
    ifaces_[i]->getTokenOffset(_return);
    return;
  }

  void getTokenStream(TokenStream& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getTokenStream(_return);
    }
    ifaces_[i]->getTokenStream(_return);
    return;
  }

  int32_t hashCode() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->hashCode();
    }
    return ifaces_[i]->hashCode();
  }

  void setTokenStream(const TokenStream& tokenStream) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setTokenStream(tokenStream);
    }
    ifaces_[i]->setTokenStream(tokenStream);
  }

};

}}} // namespace

#endif