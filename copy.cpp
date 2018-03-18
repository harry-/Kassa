#include "copy.h"

bool copy2(const char* from, char* to)
{
#ifdef msvs
	if (strcpy_s(to, strlen(from) + 1, from)) // returns 0 on success
		return false;
	return true;
#elif gcc
	strncpy(to, from, strlen(from) + 1);
#endif
}