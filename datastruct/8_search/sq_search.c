#include <stdio.h>

void CheckSearchResult(int index, int key)
{
    if (index != 0)
        printf("Element %d index is %d\n", key, index);
    else
        printf("Element %d is not found\n", key);
}

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

int SqSearchBetter(int *a, int n, int key)
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

