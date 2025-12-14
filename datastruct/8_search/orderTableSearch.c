#include <stdio.h>
#include "search.h"

int BinarySearch(int *a, int n, int key)
{
    printf("%s_%d\n", __func__, __LINE__);
    int low = 1, high = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return 0; // 未找到
}