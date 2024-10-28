// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	void *area = (void *)mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);

	if (area == MAP_FAILED)
		return NULL;

	if (mem_list_head.next == NULL)
		mem_list_init();

	mem_list_add(area, size);
	return area;
}

void *calloc(size_t nmemb, size_t size)
{
	void *area = (void *)mmap(NULL, nmemb * size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);

	if (area == MAP_FAILED)
		return NULL;

	if (mem_list_head.next == NULL)
		mem_list_init();

	mem_list_add(area, size);
	return area;
}

void free(void *ptr)
{
	if (ptr == NULL)
		return;

	struct mem_list *item = mem_list_find(ptr);
	if (item != NULL) {
		// Deallocate memory
		munmap(ptr, item->len);
		// Remove the block from the list
		mem_list_del(ptr);
	}
}

void *realloc(void *ptr, size_t size)
{
	return mremap(ptr, size, size, MREMAP_MAYMOVE);
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	return mremap(ptr, nmemb * size, nmemb * size, MREMAP_MAYMOVE);
}
