#include "hack.h"

// #include <stdlib.h>
// #include <time.h>
// #include <bits/time.h>

// extern int __clock_gettime(clockid_t clock_id, struct timespec *ts);

time_t mytime(time_t *__timer) __THROW {
  // struct timespec ts;
  // __clock_gettime(CLOCK_REALTIME, &ts);

  // if (__timer) *__timer = ts.tv_sec;
  // return ts.tv_sec / 1000;
  return 10010;
}

int myrand(void) __THROW {
  //
  return 10086;
}

int myrand_r(unsigned int *__seed) __THROW {
  //
  return 10087;
}
