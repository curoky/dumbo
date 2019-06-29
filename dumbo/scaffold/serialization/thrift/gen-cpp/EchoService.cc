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

#include "EchoService.h"

#include <bits/exception.h>  // for exception
#include <stddef.h>          // for NULL
#include <thrift/TApplicationException.h>  // for TApplicationException, TApplicationException::MISSING_RESULT, TApplicationExcept...
#include <thrift/async/TConcurrentClientSyncInfo.h>  // for TConcurrentClientSyncInfo, TConcurrentRecvSentry, TConcurrentSendSentry
#include <thrift/protocol/TProtocol.h>  // for TProtocol, T_STRUCT, TInputRecursionTracker, TOutputRecursionTracker, TType, T_E...
#include <thrift/protocol/TProtocolException.h>  // for TProtocolException, TProtocolException::INVALID_DATA
#include <thrift/transport/TTransport.h>  // for TTransport

#include "dumbo/scaffold/serialization/thrift/gen-cpp/mock_types.h"  // for MockRequest, MockException, MockResponse

namespace idl {
namespace thrift {

EchoService_echo_args::~EchoService_echo_args() noexcept {}

uint32_t EchoService_echo_args::read(::apache::thrift::protocol::TProtocol* iprot) {
  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  while (true) {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid) {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->req.read(iprot);
          this->__isset.req = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t EchoService_echo_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("EchoService_echo_args");

  xfer += oprot->writeFieldBegin("req", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += this->req.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

EchoService_echo_pargs::~EchoService_echo_pargs() noexcept {}

uint32_t EchoService_echo_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("EchoService_echo_pargs");

  xfer += oprot->writeFieldBegin("req", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += (*(this->req)).write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

EchoService_echo_result::~EchoService_echo_result() noexcept {}

uint32_t EchoService_echo_result::read(::apache::thrift::protocol::TProtocol* iprot) {
  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  while (true) {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid) {
      case 0:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->success.read(iprot);
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->ex.read(iprot);
          this->__isset.ex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t EchoService_echo_result::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("EchoService_echo_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_STRUCT, 0);
    xfer += this->success.write(oprot);
    xfer += oprot->writeFieldEnd();
  } else if (this->__isset.ex) {
    xfer += oprot->writeFieldBegin("ex", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->ex.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

EchoService_echo_presult::~EchoService_echo_presult() noexcept {}

uint32_t EchoService_echo_presult::read(::apache::thrift::protocol::TProtocol* iprot) {
  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  while (true) {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid) {
      case 0:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += (*(this->success)).read(iprot);
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->ex.read(iprot);
          this->__isset.ex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

EchoService_oneway_echo_args::~EchoService_oneway_echo_args() noexcept {}

uint32_t EchoService_oneway_echo_args::read(::apache::thrift::protocol::TProtocol* iprot) {
  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  while (true) {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid) {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->req.read(iprot);
          this->__isset.req = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t EchoService_oneway_echo_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("EchoService_oneway_echo_args");

  xfer += oprot->writeFieldBegin("req", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += this->req.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

EchoService_oneway_echo_pargs::~EchoService_oneway_echo_pargs() noexcept {}

uint32_t EchoService_oneway_echo_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("EchoService_oneway_echo_pargs");

  xfer += oprot->writeFieldBegin("req", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += (*(this->req)).write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void EchoServiceClient::echo(MockResponse& _return, const MockRequest& req) {
  send_echo(req);
  recv_echo(_return);
}

void EchoServiceClient::send_echo(const MockRequest& req) {
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("echo", ::apache::thrift::protocol::T_CALL, cseqid);

  EchoService_echo_pargs args;
  args.req = &req;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void EchoServiceClient::recv_echo(MockResponse& _return) {
  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("echo") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  EchoService_echo_presult result;
  result.success = &_return;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  if (result.__isset.success) {
    // _return pointer has now been filled
    return;
  }
  if (result.__isset.ex) {
    throw result.ex;
  }
  throw ::apache::thrift::TApplicationException(
      ::apache::thrift::TApplicationException::MISSING_RESULT, "echo failed: unknown result");
}

void EchoServiceClient::oneway_echo(const MockRequest& req) { send_oneway_echo(req); }

void EchoServiceClient::send_oneway_echo(const MockRequest& req) {
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("oneway_echo", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  EchoService_oneway_echo_pargs args;
  args.req = &req;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

bool EchoServiceProcessor::dispatchCall(::apache::thrift::protocol::TProtocol* iprot,
                                        ::apache::thrift::protocol::TProtocol* oprot,
                                        const std::string& fname, int32_t seqid,
                                        void* callContext) {
  ProcessMap::iterator pfn;
  pfn = processMap_.find(fname);
  if (pfn == processMap_.end()) {
    iprot->skip(::apache::thrift::protocol::T_STRUCT);
    iprot->readMessageEnd();
    iprot->getTransport()->readEnd();
    ::apache::thrift::TApplicationException x(
        ::apache::thrift::TApplicationException::UNKNOWN_METHOD,
        "Invalid method name: '" + fname + "'");
    oprot->writeMessageBegin(fname, ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return true;
  }
  (this->*(pfn->second))(seqid, iprot, oprot, callContext);
  return true;
}

void EchoServiceProcessor::process_echo(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot,
                                        ::apache::thrift::protocol::TProtocol* oprot,
                                        void* callContext) {
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("EchoService.echo", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx,
                                                 "EchoService.echo");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "EchoService.echo");
  }

  EchoService_echo_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "EchoService.echo", bytes);
  }

  EchoService_echo_result result;
  try {
    iface_->echo(result.success, args.req);
    result.__isset.success = true;
  } catch (MockException& ex) {
    result.ex = ex;
    result.__isset.ex = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "EchoService.echo");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("echo", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "EchoService.echo");
  }

  oprot->writeMessageBegin("echo", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "EchoService.echo", bytes);
  }
}

void EchoServiceProcessor::process_oneway_echo(int32_t,
                                               ::apache::thrift::protocol::TProtocol* iprot,
                                               ::apache::thrift::protocol::TProtocol*,
                                               void* callContext) {
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("EchoService.oneway_echo", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx,
                                                 "EchoService.oneway_echo");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "EchoService.oneway_echo");
  }

  EchoService_oneway_echo_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "EchoService.oneway_echo", bytes);
  }

  try {
    iface_->oneway_echo(args.req);
  } catch (const std::exception&) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "EchoService.oneway_echo");
    }
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->asyncComplete(ctx, "EchoService.oneway_echo");
  }

  return;
}

::std::shared_ptr<::apache::thrift::TProcessor> EchoServiceProcessorFactory::getProcessor(
    const ::apache::thrift::TConnectionInfo& connInfo) {
  ::apache::thrift::ReleaseHandler<EchoServiceIfFactory> cleanup(handlerFactory_);
  ::std::shared_ptr<EchoServiceIf> handler(handlerFactory_->getHandler(connInfo), cleanup);
  ::std::shared_ptr<::apache::thrift::TProcessor> processor(new EchoServiceProcessor(handler));
  return processor;
}

void EchoServiceConcurrentClient::echo(MockResponse& _return, const MockRequest& req) {
  int32_t seqid = send_echo(req);
  recv_echo(_return, seqid);
}

int32_t EchoServiceConcurrentClient::send_echo(const MockRequest& req) {
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("echo", ::apache::thrift::protocol::T_CALL, cseqid);

  EchoService_echo_pargs args;
  args.req = &req;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void EchoServiceConcurrentClient::recv_echo(MockResponse& _return, const int32_t seqid) {
  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  // the read mutex gets dropped and reacquired as part of waitForWork()
  // The destructor of this sentry wakes up other clients
  ::apache::thrift::async::TConcurrentRecvSentry sentry(this->sync_.get(), seqid);

  while (true) {
    if (!this->sync_->getPending(fname, mtype, rseqid)) {
      iprot_->readMessageBegin(fname, mtype, rseqid);
    }
    if (seqid == rseqid) {
      if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        sentry.commit();
        throw x;
      }
      if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
      }
      if (fname.compare("echo") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      EchoService_echo_presult result;
      result.success = &_return;
      result.read(iprot_);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();

      if (result.__isset.success) {
        // _return pointer has now been filled
        sentry.commit();
        return;
      }
      if (result.__isset.ex) {
        sentry.commit();
        throw result.ex;
      }
      // in a bad state, don't commit
      throw ::apache::thrift::TApplicationException(
          ::apache::thrift::TApplicationException::MISSING_RESULT, "echo failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  }  // end while(true)
}

void EchoServiceConcurrentClient::oneway_echo(const MockRequest& req) { send_oneway_echo(req); }

void EchoServiceConcurrentClient::send_oneway_echo(const MockRequest& req) {
  int32_t cseqid = 0;
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("oneway_echo", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  EchoService_oneway_echo_pargs args;
  args.req = &req;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
}

}  // namespace thrift
}  // namespace idl
