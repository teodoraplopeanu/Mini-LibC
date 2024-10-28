#ifndef __TIME_H__
#define __TIME_H__	1

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    long int time;
} time_t;

struct timespec {
    time_t tv_sec;
    long int tv_nsec;
};

int nanosleep(struct timespec *req, struct timespec *rem);

#ifdef __cplusplus
}
#endif

#endif
