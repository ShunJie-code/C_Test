/**
 * @file orderTableSearch.c
 * @author your name (you@domain.com)
 * @brief 有序表查找
 * @version 0.1
 * @date 2025-12-22
 * 
 * @copyright Copyright (c) 2025
 * 
 */
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

int InterpolationSearch(int *a, int n, int key)
{
    printf("%s_%d\n", __func__, __LINE__);
    int low = 1, high = n;
    while (low <= high)
    {
        // 差值计算mid
        int mid = low + (high - low) * (key - a[low]) / (a[high] - a[low]);
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