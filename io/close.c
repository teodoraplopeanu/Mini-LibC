// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	int res = syscall(3, fd);

	if (res == -1)
		return -1;

	return 0;
}
