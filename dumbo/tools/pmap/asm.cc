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

#include <pthread.h>
#include <stdint.h>
#include <stdio.h>

// -fno-omit-frame-pointer might be required - otherwise you might get a crash
// might not be exactly at the top; but probably very close

void *stack_top() {
  void **top;
  asm("movq %%rbp, %0" : "=r"(top));  // set top to %rbp - replace with %ebp for 32-bit x86
  // if top is higher in memory than the variable, then still part of the stack.
  while ((uintptr_t)*top > (uintptr_t)&top) {
    top = (void **)*top;  // NOLINT
  }
  return top;
}

void *test_another_layer(int x) { return stack_top(); }

void *subthread(void *ptr) {
  void *st1 = stack_top();
  void *st2 = test_another_layer(0);
  void *st3 = &ptr;
  int a[100];
  int b;
  void *st4 = &a[0];
  void *st5 = &a[1];
  void *st6 = &a[99];
  void *st7 = &b;

  printf("stack tops 2: %p %p %p %p %p %p %p\n", st1, st2, st3, st4, st5, st6, st7);
  return NULL;
}

int main(int argc, char *argv[]) {
  void *st1 = stack_top();
  void *st2 = test_another_layer(0);
  void *st3 = &argc;
  printf("stack tops: %x %x %x\n", st1, st2, st3);
  pthread_t ot;
  if (pthread_create(&ot, NULL, subthread, NULL) != 0) {
    perror("cannot create");
    return 1;
  }
  if (pthread_join(ot, NULL) != 0) {
    perror("cannot join");
    return 2;
  }
  return 0;
}
