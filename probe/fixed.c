#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
char * _strdup_printf(char * fmt, ...) {
	va_list va;
	va_start(va, fmt);
#ifdef _WIN32
	int s = _vscprintf(fmt, va);
#else
	int s = vsnprintf(NULL, 0, fmt, va);
#endif
	va_end(va);
	if (s < 0)
		return NULL;
	char * rt = malloc(s + 1);
	if (rt == NULL)
		return NULL;
	va_start(va, fmt);
	vsnprintf(rt, s + 1, fmt, va);
	va_end(va);
	return rt;
}
