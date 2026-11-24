#include <stdio.h>
#include <string.h>
char * _strdup_printf(char * fmt, ...);
int main(void){ char *m=_strdup_printf("EE:[lsoda] %d steps taken before reaching tout @(%s:%d)", 1, "lsoda.c", 728); printf("[%s] len=%zu\n", m, strlen(m)); return 0; }
