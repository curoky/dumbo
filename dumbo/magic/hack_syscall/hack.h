#include <bits/types/time_t.h>
#include <ctype.h>

extern "C" {
extern time_t mytime(time_t *__timer) __THROW;
time_t *time(time_t *__timer) __THROW __attribute__((alias("mytime")));

extern int myrand(void) __THROW;
int rand(void) __THROW __attribute__((alias("myrand")));

extern int myrand_r(unsigned int *__seed) __THROW;
int rand_r(unsigned int *__seed) __THROW __attribute__((alias("myrand_r")));
}
