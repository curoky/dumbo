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

// int fcntl(int fd, int cmd);
// int fcntl(int fd, int cmd, long arg);
// int fcntl(int fd, int cmd, struct flock *lock);
// fd:文件描述词
// cmd:操作命令
// arg:供命令使用的参数
// lock:同上

#include <fcntl.h>  // for fcntl, F_GETFL, F_SETFL, O_NONBLOCK

void setnoblocking(int fd) {
  int opts = 0;
  opts = fcntl(fd, F_GETFL);
  opts = opts | O_NONBLOCK;
  fcntl(fd, F_SETFL);
}
