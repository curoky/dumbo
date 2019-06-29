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

#include <dlfcn.h>  // for dlerror, dlopen, dlsym, RTLD_LAZY

#include <iostream>  // for operator<<, basic_ostream, endl, ostream, cerr, char_traits, cout
#include <map>       // for map
#include <memory>    // for shared_ptr, __shared_ptr_access
#include <string>    // for string, operator<<, basic_string
#include <vector>    // for vector

#include "plugin/action.h"  // for Action

extern "C" {
typedef std::shared_ptr<Action> (*CREATE_ACTION_FUNC)();
}

class ActionManager {
 public:
  explicit ActionManager(const std::vector<std::string>& so_paths) {
    for (const auto& path : so_paths) {
      void* handle = dlopen(path.c_str(), RTLD_LAZY);

      if (handle == nullptr) {
        std::cerr << "[ERROR]: " << dlerror() << std::endl;
        break;
      }

      auto create_action = (CREATE_ACTION_FUNC)dlsym(handle, "create_action");
      if (create_action == nullptr) {
        std::cerr << "[ERROR]: " << dlerror() << std::endl;
        break;
      }

      std::shared_ptr<Action> actor = create_action();
      std::cout << "[INFO]: act result " << actor->act() << std::endl;
    }
  }

 private:
  std::map<std::string, std::shared_ptr<Action>> actions;
};

int main(int argc, char const* argv[]) {
  std::string prefix = "/home/curoky/repos/cpp/dumbo/bazel-bin/dumbo/magic/dlopen_plugin/plugin/";

  std::string cat_action_path = prefix + "libcat_action.so";
  std::string echo_action_path = prefix + "libecho_action.so";
  std::vector<std::string> paths = {cat_action_path, echo_action_path};

  ActionManager am(paths);
  return 0;
}
