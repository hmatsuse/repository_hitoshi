#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#define MAX(x, y) (x>y ? x : y)
#define MIN(x, y) (x<y ? x : y)
#define ABS(x) (x>0 ? x : -x)

typedef struct s_t
{
    int width;
    int dot;
    int val;
    int plen;
    char c;
}              t_f;

int ft_printf(char *s, ...);

#endif