#include <stdio.h>

void CheckSearchResult(int index, int key)
{
    if (index != 0)
        printf("Element %d index is %d\n", key, index);
    else
        printf("Element %d is not found\n", key);
}

int SQ_Search(int *a, int n, int key)
{
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

int SQ_SearchBetter(int *a, int n, int key)
{
    int i = n;
    a[0] = key;
    // 优点在于不需要判断i<n
    while (a[i] != key)
    {
        i--;
    }
    return i;
}