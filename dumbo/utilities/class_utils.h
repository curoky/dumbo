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
 * ----------------------------------------------------------------------------
 * @file: class_utils.h
 * ----------------------------------------------------------------------------
 */

#pragma once
#include <glog/logging.h>  // for COMPACT_GOOGLE_LOG_INFO, LOG, LogMessage
#include <iostream>        // for operator<<
#include <memory>
#include <string>          // for size_t
#include <utility>  // for move

namespace taro {
namespace util {

class ClassMetrics {
 public:
  struct Counter {
    void reset() {
      construct = 0;
      destruct = 0;
      move_cons = 0;
      copy_cons = 0;
      move_assign = 0;
      copy_assign = 0;
    }
    size_t construct = 0;
    size_t destruct = 0;
    size_t move_cons = 0;
    size_t copy_cons = 0;
    size_t move_assign = 0;
    size_t copy_assign = 0;
  };

  explicit ClassMetrics(Counter& count) : count_(count) { count_.construct++; }

  ~ClassMetrics() { count_.destruct++; }

  ClassMetrics(const ClassMetrics& cm) : count_(cm.count_) {
    count_.copy_cons++;
    LOG(INFO) << "copy constructor!";
  }

  ClassMetrics& operator=(const ClassMetrics&) {
    count_.copy_assign++;
    LOG(INFO) << "copy assignment operator!";
    return *this;
  }

  ClassMetrics(ClassMetrics&& cm) : count_(cm.count_) {
    count_.move_cons++;
    LOG(INFO) << "move constructor!";
  }

  ClassMetrics& operator=(ClassMetrics&&) noexcept {
    count_.move_assign++;
    LOG(INFO) << " move assignment operator!";
    return *this;
  }

 private:
  Counter& count_;
};

}  // namespace util
}  // namespace taro
