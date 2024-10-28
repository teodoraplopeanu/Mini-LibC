#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <time.h>

int nanosleep(struct timespec *req, struct timespec *rem)
{
    int res = syscall(35, req, rem);

    if (res < 0) {
        errno = -res;
        return -1;
    }

    return 0;
}
