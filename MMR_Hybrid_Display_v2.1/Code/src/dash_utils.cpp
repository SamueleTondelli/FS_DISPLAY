#include "../include/dash_utils.hpp"

// https://stackoverflow.com/a/7666577
unsigned long hashCstr(char* key)
{
	unsigned long hash = 5381;
	int c;

	while (c = *key++)
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash;
}

int compCstr(char* s1, char* s2)
{
	return strcmp(s1, s2);
}

void safeStringCopy(const char* src, char* dst, size_t dstSize)
{
	size_t cpySize = strlen(src) < (dstSize - 1) ? strlen(src) : dstSize - 1;
	memcpy(dst, src, cpySize);
	dst[cpySize] = 0;
}
