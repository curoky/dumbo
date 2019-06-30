# timerfd

timerfd 是 Linux 为用户程序提供的一个定时器接口。

这个接口基于文件描述符，所以能够被用于 select/poll 的应用场景。

## interface

### timerfd_create

```c++
extern int timerfd_create (clockid_t __clock_id, int __flags) __THROW;
```

- param clockid: 可以是 CLOCK_MONOTONIC 或者 CLOCK_REALTIME。
  CLOCK_REALTIME：相对时间，从 1970.1.1 到目前的时间。更改系统时间会更改获取的值。也就是，它以系统时间为坐标。
  CLOCK_MONOTONIC：与 CLOCK_REALTIME 相反，它是以绝对时间为准，获取的时间为系统重启到现在的时间，更改系统时间对齐没有影响。
- param flags: 可以是 0 或者 TFD_CLOEXEC/TFD_NONBLOCK

### timerfd_settime

```c++
extern int timerfd_settime (int __ufd, int __flags, const struct itimerspec *__utmr,
        struct itimerspec *__otmr) __THROW;
```
