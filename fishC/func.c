#include <stdio.h>

extern int g_count;

void func(void)
{
    printf("count = %d\n", g_count);
}