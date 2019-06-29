/**
 * Copyright 2020 curoky(cccuroky@gmail.com).
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef EchoService_H
#define EchoService_H

#include <stdint.h>                     // for uint32_t, int32_t
#include <thrift/TDispatchProcessor.h>  // for TDispatchProcessor
#include <thrift/TProcessor.h>  // for TConnectionInfo (ptr only), TProcessor (ptr only), TProcessorFactory
#include <thrift/async/TConcurrentClientSyncInfo.h>

#include <map>     // for map, map<>::value_compare
#include <memory>  // for shared_ptr, __alloc_traits<>::value_type, __shared_ptr_access
#include <string>  // for string, basic_string, operator<
#include <vector>  // for vector, size_t

#include "mock_types.h"  // for MockRequest, MockException, MockResponse

namespace apache::thrift::async {
class TConcurrentClientSyncInfo;
}  // namespace apache::thrift::async
namespace apache::thrift::protocol {
class TProtocol;
}  // namespace apache::thrift::protocol

namespace idl {
namespace thrift {

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4250)  // inheriting methods via dominance
#endif

class EchoServiceIf {
 public:
  virtual ~EchoServiceIf() {}
  virtual void echo(MockResponse& _return, const MockRequest& req) = 0;
  virtual void oneway_echo(const MockRequest& req) = 0;
};

class EchoServiceIfFactory {
 public:
  typedef EchoServiceIf Handler;

  virtual ~EchoServiceIfFactory() {}

  virtual EchoServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(EchoServiceIf* /* handler */) = 0;
};

class EchoServiceIfSingletonFactory : virtual public EchoServiceIfFactory {
 public:
  EchoServiceIfSingletonFactory(const ::std::shared_ptr<EchoServiceIf>& iface) : iface_(iface) {}
  virtual ~EchoServiceIfSingletonFactory() {}

  virtual EchoServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(EchoServiceIf* /* handler */) {}

 protected:
  ::std::shared_ptr<EchoServiceIf> iface_;
};

class EchoServiceNull : virtual public EchoServiceIf {
 public:
  virtual ~EchoServiceNull() {}
  void echo(MockResponse& /* _return */, const MockRequest& /* req */) { return; }
  void oneway_echo(const MockRequest& /* req */) { return; }
};

typedef struct _EchoService_echo_args__isset {
  _EchoService_echo_args__isset() : req(false) {}
  bool req : 1;
} _EchoService_echo_args__isset;

class EchoService_echo_args {
 public:
  EchoService_echo_args(const EchoService_echo_args&);
  EchoService_echo_args& operator=(const EchoService_echo_args&);
  EchoService_echo_args() {}

  virtual ~EchoService_echo_args() noexcept;
  MockRequest req;

  _EchoService_echo_args__isset __isset;

  void __set_req(const MockRequest& val);

  bool operator==(const EchoService_echo_args& rhs) const {
    if (!(req == rhs.req)) return false;
    return true;
  }
  bool operator!=(const EchoService_echo_args& rhs) const { return !(*this == rhs); }

  bool operator<(const EchoService_echo_args&) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;
};

class EchoService_echo_pargs {
 public:
  virtual ~EchoService_echo_pargs() noexcept;
  const MockRequest* req;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;
};

typedef struct _EchoService_echo_result__isset {
  _EchoService_echo_result__isset() : success(false), ex(false) {}
  bool success : 1;
  bool ex : 1;
} _EchoService_echo_result__isset;

class EchoService_echo_result {
 public:
  EchoService_echo_result(const EchoService_echo_result&);
  EchoService_echo_result& operator=(const EchoService_echo_result&);
  EchoService_echo_result() {}

  virtual ~EchoService_echo_result() noexcept;
  MockResponse success;
  MockException ex;

  _EchoService_echo_result__isset __isset;

  void __set_success(const MockResponse& val);

  void __set_ex(const MockException& val);

  bool operator==(const EchoService_echo_result& rhs) const {
    if (!(success == rhs.success)) return false;
    if (!(ex == rhs.ex)) return false;
    return true;
  }
  bool operator!=(const EchoService_echo_result& rhs) const { return !(*this == rhs); }

  bool operator<(const EchoService_echo_result&) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;
};

typedef struct _EchoService_echo_presult__isset {
  _EchoService_echo_presult__isset() : success(false), ex(false) {}
  bool success : 1;
  bool ex : 1;
} _EchoService_echo_presult__isset;

class EchoService_echo_presult {
 public:
  virtual ~EchoService_echo_presult() noexcept;
  MockResponse* success;
  MockException ex;

  _EchoService_echo_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
};

typedef struct _EchoService_oneway_echo_args__isset {
  _EchoService_oneway_echo_args__isset() : req(false) {}
  bool req : 1;
} _EchoService_oneway_echo_args__isset;

class EchoService_oneway_echo_args {
 public:
  EchoService_oneway_echo_args(const EchoService_oneway_echo_args&);
  EchoService_oneway_echo_args& operator=(const EchoService_oneway_echo_args&);
  EchoService_oneway_echo_args() {}

  virtual ~EchoService_oneway_echo_args() noexcept;
  MockRequest req;

  _EchoService_oneway_echo_args__isset __isset;

  void __set_req(const MockRequest& val);

  bool operator==(const EchoService_oneway_echo_args& rhs) const {
    if (!(req == rhs.req)) return false;
    return true;
  }
  bool operator!=(const EchoService_oneway_echo_args& rhs) const { return !(*this == rhs); }

  bool operator<(const EchoService_oneway_echo_args&) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;
};

class EchoService_oneway_echo_pargs {
 public:
  virtual ~EchoService_oneway_echo_pargs() noexcept;
  const MockRequest* req;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;
};

class EchoServiceClient : virtual public EchoServiceIf {
 public:
  EchoServiceClient(std::shared_ptr<::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  EchoServiceClient(std::shared_ptr<::apache::thrift::protocol::TProtocol> iprot,
                    std::shared_ptr<::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot, oprot);
  }

 private:
  void setProtocol(std::shared_ptr<::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot, prot);
  }
  void setProtocol(std::shared_ptr<::apache::thrift::protocol::TProtocol> iprot,
                   std::shared_ptr<::apache::thrift::protocol::TProtocol> oprot) {
    piprot_ = iprot;
    poprot_ = oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }

 public:
  std::shared_ptr<::apache::thrift::protocol::TProtocol> getInputProtocol() { return piprot_; }
  std::shared_ptr<::apache::thrift::protocol::TProtocol> getOutputProtocol() { return poprot_; }
  void echo(MockResponse& _return, const MockRequest& req);
  void send_echo(const MockRequest& req);
  void recv_echo(MockResponse& _return);
  void oneway_echo(const MockRequest& req);
  void send_oneway_echo(const MockRequest& req);

 protected:
  std::shared_ptr<::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr<::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class EchoServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<EchoServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot,
                            ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname,
                            int32_t seqid, void* callContext);

 private:
  typedef void (EchoServiceProcessor::*ProcessFunction)(int32_t,
                                                        ::apache::thrift::protocol::TProtocol*,
                                                        ::apache::thrift::protocol::TProtocol*,
                                                        void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_echo(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
                    ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_oneway_echo(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
                           ::apache::thrift::protocol::TProtocol* oprot, void* callContext);

 public:
  EchoServiceProcessor(::std::shared_ptr<EchoServiceIf> iface) : iface_(iface) {
    processMap_["echo"] = &EchoServiceProcessor::process_echo;
    processMap_["oneway_echo"] = &EchoServiceProcessor::process_oneway_echo;
  }

  virtual ~EchoServiceProcessor() {}
};

class EchoServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  EchoServiceProcessorFactory(const ::std::shared_ptr<EchoServiceIfFactory>& handlerFactory)
      : handlerFactory_(handlerFactory) {}

  ::std::shared_ptr<::apache::thrift::TProcessor> getProcessor(
      const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::std::shared_ptr<EchoServiceIfFactory> handlerFactory_;
};

class EchoServiceMultiface : virtual public EchoServiceIf {
 public:
  EchoServiceMultiface(std::vector<std::shared_ptr<EchoServiceIf>>& ifaces) : ifaces_(ifaces) {}
  virtual ~EchoServiceMultiface() {}

 protected:
  std::vector<std::shared_ptr<EchoServiceIf>> ifaces_;
  EchoServiceMultiface() {}
  void add(::std::shared_ptr<EchoServiceIf> iface) { ifaces_.push_back(iface); }

 public:
  void echo(MockResponse& _return, const MockRequest& req) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->echo(_return, req);
    }
    ifaces_[i]->echo(_return, req);
    return;
  }

  void oneway_echo(const MockRequest& req) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->oneway_echo(req);
    }
    ifaces_[i]->oneway_echo(req);
  }
};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class EchoServiceConcurrentClient : virtual public EchoServiceIf {
 public:
  EchoServiceConcurrentClient(
      std::shared_ptr<::apache::thrift::protocol::TProtocol> prot,
      std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync)
      : sync_(sync) {
    setProtocol(prot);
  }
  EchoServiceConcurrentClient(
      std::shared_ptr<::apache::thrift::protocol::TProtocol> iprot,
      std::shared_ptr<::apache::thrift::protocol::TProtocol> oprot,
      std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync)
      : sync_(sync) {
    setProtocol(iprot, oprot);
  }

 private:
  void setProtocol(std::shared_ptr<::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot, prot);
  }
  void setProtocol(std::shared_ptr<::apache::thrift::protocol::TProtocol> iprot,
                   std::shared_ptr<::apache::thrift::protocol::TProtocol> oprot) {
    piprot_ = iprot;
    poprot_ = oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }

 public:
  std::shared_ptr<::apache::thrift::protocol::TProtocol> getInputProtocol() { return piprot_; }
  std::shared_ptr<::apache::thrift::protocol::TProtocol> getOutputProtocol() { return poprot_; }
  void echo(MockResponse& _return, const MockRequest& req);
  int32_t send_echo(const MockRequest& req);
  void recv_echo(MockResponse& _return, const int32_t seqid);
  void oneway_echo(const MockRequest& req);
  void send_oneway_echo(const MockRequest& req);

 protected:
  std::shared_ptr<::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr<::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync_;
};

#ifdef _MSC_VER
#pragma warning(pop)
#endif

}  // namespace thrift
}  // namespace idl

#endif
