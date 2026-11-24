#include <stdio.h>
char * _strdup_printf(char * fmt, ...);
#define ERROR(fmt, ...) _strdup_printf("EE:" fmt " @(%s:%d)", ## __VA_ARGS__, __FILE__, __LINE__)
int main(int argc, char **argv){
  double tn = 0.25, h = 1e-12; char *m;
  if (argc > 1)  /* fixed call */
    m = ERROR("lsoda -- at t = %g and step size _C(h) = %g, the\n"
              "         error test failed repeatedly or\n"
              "         with fabs(_C(h)) = hmin\n", tn, h);
  else           /* line 868 as shipped */
    m = ERROR("lsoda -- at t = %g and step size _C(h) = %g, the\n",
              "         error test failed repeatedly or\n"
              "         with fabs(_C(h)) = hmin\n", tn, h);
  printf("%s\n", m); return 0;
}
