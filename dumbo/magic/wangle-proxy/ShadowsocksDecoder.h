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
 */

#pragma once

#include <glog/logging.h>
#include <wangle/codec/ByteToMessageDecoder.h>

#include <iostream>
#include <memory>
#include <string>
#include <utility>

#include "RC4Handler.h"
#include "util.h"

class ShadowsocksDecoder : public wangle::BytesToBytesHandler {
 public:
  explicit ShadowsocksDecoder(const std::string& key) {
    key_buf_ = std::move(folly::IOBuf::copyBuffer(key));
  }

  bool decode(Context*, folly::IOBufQueue& q, std::unique_ptr<folly::IOBuf>& result) {
    if (q.chainLength() == 0) {
      return false;
    }

    LOG(INFO) << "[decode] IOBufQueue length: " << q.chainLength();

    if (is_first_recv_) {
      is_first_recv_ = false;
      LOG(INFO) << "is_first_recv_";

      init_encryptor(std::move(q.split(16)));
    }

    auto cipher_buf = q.move();

    LOG(INFO) << "[decode] cipher message len: " << cipher_buf->length();
    // debugchar(cipher_buf->data(), cipher_buf->length());

    auto plain_buf = folly::IOBuf::create(cipher_buf->length());
    plain_buf->append(cipher_buf->length());

    handler_->decrypt(cipher_buf->data(), cipher_buf->length(), plain_buf->writableData());

    LOG(INFO) << "[decode] plain message len: " << plain_buf->length();
    // debugchar(plain_buf->data(), plain_buf->length());

    result = std::move(plain_buf);
    return true;
  }

  void init_encryptor(std::unique_ptr<folly::IOBuf> iv) {
    iv_buf_ = std::move(iv);
    debugchar(iv_buf_->data(), 16);
    debugchar(key_buf_->data(), 16);
    handler_ = std::make_shared<RC4Handler>(key_buf_->data(), iv_buf_->data());
  }

  void transportActive(Context* ctx) override {
    transportActive_ = true;
    ctx->fireTransportActive();
  }

  void transportInactive(Context* ctx) override {
    transportActive_ = false;
    ctx->fireTransportInactive();
  }

  void read(Context* ctx, folly::IOBufQueue& q) override {
    bool success = true;
    while (success && transportActive_) {
      std::unique_ptr<folly::IOBuf> result;
      success = decode(ctx, q, result);
      if (success) {
        folly::IOBufQueue::Options clOptions;
        clOptions.cacheChainLength = true;
        folly::IOBufQueue queue(clOptions);
        queue.append(std::move(result));
        ctx->fireRead(queue);
      }
    }
  }

  std::unique_ptr<folly::IOBuf> encode(std::unique_ptr<folly::IOBuf>& msg) {
    std::unique_ptr<folly::IOBuf> result(folly::IOBuf::create(msg->length() + 16));
    result->advance(16);
    result->append(msg->length());
    handler_->encrypt(msg->data(), msg->length(), result->writableData());

    if (is_first_send_) {
      is_first_send_ = false;
      LOG(INFO) << "is_first_send_";

      memcpy(result->writableData() - iv_buf_->length(), iv_buf_->data(), iv_buf_->length());
      result->prepend(iv_buf_->length());
    }

    LOG(INFO) << "[encode] cipher message len: " << result->length();
    return result;
  }

  folly::Future<folly::Unit> write(Context* ctx, std::unique_ptr<folly::IOBuf> msg) override {
    auto buf = encode(msg);
    return buf ? ctx->fireWrite(std::move(buf)) : folly::makeFuture();
  }

 private:
  bool transportActive_ = true;
  bool is_first_recv_ = true;
  bool is_first_send_ = true;

  std::unique_ptr<folly::IOBuf> iv_buf_{nullptr};
  std::unique_ptr<folly::IOBuf> key_buf_{nullptr};

  std::shared_ptr<RC4Handler> handler_{nullptr};
};
