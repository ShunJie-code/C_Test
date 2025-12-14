#include <stdio.h>
#include "search.h"

int SqSearch(int *a, int n, int key)
{
    printf("%s_%d\n", __func__, __LINE__);
    int i;
    for (i = 1; i <= n; i++)
    {
        if (a[i] == key)
        {
            return i;
        }
    }
    return 0;
}

int SqSentinelSearch(int *a, int n, int key)
{
    printf("%s_%d\n", __func__, __LINE__);
    int i = n;
    a[0] = key;
    // 优点在于不需要判断i<n
    while (a[i] != key)
    {
        i--;
    }
    return i;
}


