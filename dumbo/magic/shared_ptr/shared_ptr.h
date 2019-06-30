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

#pragma once
#include <atomic>

namespace cry {

template <typename T>
class SharedPtr {
 public:
  explicit SharedPtr(T *ptr) : ptr_(ptr) { counter_ = new std::atomic_long(1); }

  SharedPtr(SharedPtr<T> &other) noexcept { *this = other; }
  SharedPtr<T> &operator=(SharedPtr<T> &other) noexcept {
    reset();

    ptr_ = other.ptr_;
    counter_ = other.counter_;
    counter_->fetch_add(1);
    return *this;
  }

  void reset() noexcept {
    if (counter_ != nullptr) {
      if (counter_->fetch_sub(1) == 1) {
        delete counter_;
        counter_ = nullptr;
        delete ptr_;
        ptr_ = nullptr;
      }
    }
  }

  long use_count() const noexcept {  // NOLINT
    if (counter_ != nullptr) {
      return counter_->load();
    } else {
      return 0;
    }
  }

  T *get() const noexcept { return ptr_; }

  ~SharedPtr() noexcept { reset(); }

 private:
  T *ptr_ = nullptr;
  std::atomic_long *counter_ = nullptr;
};

}  // namespace cry
