// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int truncate(const char *path, off_t length)
{
	int res = syscall(76, path, length);

	if (res < 0) {
		errno = -res;
		return -1;
	}

	return 0;
}
