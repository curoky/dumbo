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

#include <boost/interprocess/creation_tags.hpp>          // for create_only, open_only
#include <boost/interprocess/interprocess_fwd.hpp>       // for managed_shared_memory
#include <boost/interprocess/managed_shared_memory.hpp>  // for basic_managed_shared_memory
#include <boost/interprocess/shared_memory_object.hpp>   // for shared_memory_object
#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE

TEST_CASE("[ManagedSharedMemory]: BaseTest") {
  using boost::interprocess::create_only;
  using boost::interprocess::managed_shared_memory;
  using boost::interprocess::open_only;
  using boost::interprocess::shared_memory_object;

  // 保证内存文件被删除
  struct shm_remove {
    shm_remove() { shared_memory_object::remove("MySharedMemory"); }
    ~shm_remove() { shared_memory_object::remove("MySharedMemory"); }
  } remover;

  managed_shared_memory::handle_t handle;

  {
    // 创建一段共享内存的管理器
    // `MySharedMemory` 在/dev/shm/目录下，大小为64k
    managed_shared_memory segment(create_only, "MySharedMemory", 65536);

    // 获取未分配的大小
    managed_shared_memory::size_type free_memory = segment.get_free_memory();
    REQUIRE(free_memory == 65312);

    // 分配一块内存，大小1k
    void* shptr = segment.allocate(1024 /*bytes to allocate*/);
    REQUIRE(free_memory == 65312);

    // 即使共享内存映射到不同的地址空间，这个通过
    // 基地址获得的句柄能够标识共享内存段中的任意字节。
    // 这个handle可以在其它进程中使用
    handle = segment.get_handle_from_address(shptr);
  }

  {
    managed_shared_memory segment(open_only, "MySharedMemory");
    void* msg = segment.get_address_from_handle(handle);
    segment.deallocate(msg);
    REQUIRE(segment.get_free_memory() == 65312);
  }
}
