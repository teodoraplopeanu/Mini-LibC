// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	char *d;

	for (d = destination; *source != '\0'; source++, d++)
		*d = *source;

	// Add '\0' at the end
	*d = *source;

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	char *d;

	for (d = destination; *source != '\0' && len != 0; source++, d++, len--)
		*d = *source;

	if (len > 0)
		*d = '\0';

	return destination;
}

char *strcat(char *destination, const char *source)
{
	char *d;

	for (d = destination; *d != '\0'; d++)
		;

	for(; *source != 0; source++, d++)
		*d = *source;

	*d = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	char *d;

	for (d = destination; *d != '\0'; d++)
		;

	for(; *source != 0 && len != 0; source++, d++, len--)
		*d = *source;

	*d = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	const char *p1 = str1;
	const char *p2 = str2;

	while (*p1 != '\0' && *p2 != '\0') {
		if (*p1 == *p2) {
			p1++;
			p2++;
			continue;
		}
		if (*p1 < *p2)
			return -1;
		if (*p1 > *p2)
			return 1;
	}

	if (*p1)
		return 1;

	if (*p2)
		return -1;

	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	const char *p1 = str1;
	const char *p2 = str2;

	while (*p1 != '\0' && *p2 != '\0' && len != 0) {
		if (*p1 == *p2) {
			p1++;
			p2++;
			len--;
			continue;
		}
		if (*p1 < *p2)
			return -1;
		if (*p1 > *p2)
			return 1;
	}

	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	const char *ptr = str;

	while (*ptr != '\0') {
		if (*ptr == c)
			return (char *)ptr;
		ptr++;
	}

	return NULL;
}

char *strrchr(const char *str, int c)
{
	const char *ptr = str;

	while (*ptr != '\0')
		ptr++;

	while (ptr != str) {
		if (*ptr == c)
			return (char *)ptr;
		ptr--;
	}

	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	size_t len = strlen(needle);

	const char *ptr = haystack;

	while (*(ptr + len) != '\0') {
		if (strncmp(ptr, needle, len) == 0)
			return (char *)ptr;
		ptr++;
	}

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	size_t len = strlen(needle);

	const char *ptr = haystack;

	while (*(ptr + len) != '\0')
		ptr++;

	while (ptr != haystack) {
		if (strncmp(ptr, needle, len) == 0)
			return (char *)ptr;
		ptr--;
	}

	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	char *dest_ptr = destination;
	const char *src_ptr = source;

	while (num != 0 && *src_ptr != 0) {
		*dest_ptr = *src_ptr;
		src_ptr++;
		dest_ptr++;
		num--;
	}

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char *dest_ptr = destination;
	const char *src_ptr = source;

	//char buf[num];
	char buf[10000];

	size_t num_copy = num;

	// Copy source to additional buffer
	while (num_copy != 0) {
		buf[num - num_copy] = *src_ptr;
		src_ptr++;
		num_copy--;
	}

	num_copy = num;

	// Copy buffer to destination
	while (num != 0) {
		*dest_ptr = buf[num_copy - num];
		dest_ptr++;
		num--;
	}

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const char *p1 = ptr1;
	const char *p2 = ptr2;

	while (num != 0) {
		if (*p1 == *p2) {
			p1++;
			p2++;
			num--;
			continue;
		}

		if (*p1 < *p2)
			return 1;

		if (*p1 > *p2)
			return -1;
	}

	return 0;
}

void *memset(void *source, int value, size_t num)
{
	char *ptr = source;

	while (num != 0) {
		*ptr = value;
		ptr++;
		num--;
	}

	return source;
}
