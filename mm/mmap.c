// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	void *area = (void *)syscall(9, addr, length, prot, flags, fd, offset);

	// Handle mmap errors
	if ((long)area == -EBADF) {
		errno = EBADF;
		return MAP_FAILED;
	}

	if ((long)area == -EINVAL) {
		errno = EINVAL;
		return MAP_FAILED;
	}

	if ((long)area == -EACCES) {
		errno = EACCES;
		return MAP_FAILED;
	}

	if ((long)area == -ENODEV) {
		errno = ENODEV;
		return MAP_FAILED;
	}

	// Return a pointer to the allocated area (if there was no error)
	return area;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	void *area = (void *)syscall(25, old_address, old_size, new_size, flags);

	// Handle mremap errors
	if ((long)area == -EBADF) {
		errno = EBADF;
		return MAP_FAILED;
	}

	if ((long)area == -EINVAL) {
		errno = EINVAL;
		return MAP_FAILED;
	}

	if ((long)area == -EACCES) {
		errno = EACCES;
		return MAP_FAILED;
	}

	if ((long)area == -ENODEV) {
		errno = ENODEV;
		return MAP_FAILED;
	}

	// Return a pointer to the allocated area (if there was no error)
	return area;
}

int munmap(void *addr, size_t length)
{
	int res = syscall(11, addr, length);

	if (res < 0) {
		errno = -res;
		return -1;
	}

	return 0;
}
