// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>

int puts(const char *s)
{
	int res = write(1, s, strlen(s));

	if (res < 0) {
		errno = -res;
		return -1;
	}

	int res2 = write(1, "\n", 1);
	if (res2 < 0) {
		errno = -res2;
		return -1;
	}

	return res;
}
