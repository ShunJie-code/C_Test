#include "kmp.h"

void GetNext(char *T, int *next)
{
    int j = 0;
    int i = 1;
    next[1] = 0;
    while (i < T[0])
    {
        if (0 == j || T[i] == T[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}