#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <time.h>

unsigned int sleep(unsigned int seconds)
{
    struct timespec wait = {{seconds}, 0};

	return nanosleep(&wait, NULL);
}
