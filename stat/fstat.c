// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	int res = syscall(5, fd, st);

	if (res < 0) {
		errno = -res;
		return -1;
	}

	return 0;
}
