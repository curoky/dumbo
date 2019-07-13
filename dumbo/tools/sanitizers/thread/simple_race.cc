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

// REF: https://github.com/google/sanitizers/wiki/ThreadSanitizerCppManual
// RUN: clang++ simple_race.cc -fsanitize=thread -fPIE -pie -g

#include <pthread.h>
#include <stdio.h>

int Global;

void *Thread1(void *x) {
  Global++;
  return NULL;
}

void *Thread2(void *x) {
  Global--;
  return NULL;
}

int main() {
  pthread_t t[2];
  pthread_create(&t[0], NULL, Thread1, NULL);
  pthread_create(&t[1], NULL, Thread2, NULL);
  pthread_join(t[0], NULL);
  pthread_join(t[1], NULL);
}

/*
==================
WARNING: ThreadSanitizer: data race (pid=1611923)
  Read of size 4 at 0x56174bb3101c by thread T2:
    #0 Thread2(void*) <null> (simple_race+0xb17)
    #1 <null> <null> (libtsan.so.0+0x2d1af)

  Previous write of size 4 at 0x56174bb3101c by thread T1:
    #0 Thread1(void*) <null> (simple_race+0xacf)
    #1 <null> <null> (libtsan.so.0+0x2d1af)

  Location is global 'Global' of size 4 at 0x56174bb3101c (simple_race+0x00000000301c)

  Thread T2 (tid=1612338, running) created by main thread at:
    #0 pthread_create <null> (libtsan.so.0+0x5ea99)
    #1 main <null> (simple_race+0xba5)

  Thread T1 (tid=1612337, finished) created by main thread at:
    #0 pthread_create <null> (libtsan.so.0+0x5ea99)
    #1 main <null> (simple_race+0xb84)
*/
