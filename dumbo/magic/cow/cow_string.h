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
 * @file: cow.cc
 */

#include <algorithm>
#include <atomic>

namespace cry {

class CowString {
 public:
  CowString(size_t n, char ch) noexcept {
    data_ = new char[n + 1];
    data_[n] = '\0';
    size_ = n;

    counter_ = new std::atomic_long(1);

    std::fill_n(data_, n, ch);
  }

  ~CowString() noexcept { reset(); }

  CowString(CowString& str) noexcept { *this = str; }

  CowString& operator=(CowString& str) noexcept {
    reset();

    data_ = str.data_;
    size_ = str.size_;
    counter_ = str.counter_;
    counter_->fetch_add(1);
    return *this;
  }

  void reset() noexcept {
    if (counter_ != nullptr) {
      if (counter_->fetch_sub(1) == 1) {
        delete counter_;
        counter_ = nullptr;
        delete[] data_;
        data_ = nullptr;
      }
    }
  }

  char* data() const noexcept { return data_; }

  char* mutableData() noexcept {
    if (counter_->load() > 1) {
      unshare();
    }
    return data_;
  }

  char* begin() noexcept { return mutableData(); }

  const char* begin() const noexcept { return data_; }

  char& operator[](size_t pos) noexcept { return *(begin() + pos); }

  const char& operator[](size_t pos) const noexcept { return *(begin() + pos); }

  long use_count() const noexcept {
    if (counter_ != nullptr) {
      return counter_->load();
    } else {
      return 0;
    }
  }

 private:
  void unshare() noexcept {
    reset();

    char* new_data = new char[size_ + 1];
    new_data[size_] = '\0';
    counter_ = new std::atomic_long(1);

    std::copy_n(data_, size_, new_data);
    data_ = new_data;
  }

 private:
  char* data_ = nullptr;
  size_t size_ = 0;

  std::atomic_long* counter_ = nullptr;
};

}  // namespace cry
