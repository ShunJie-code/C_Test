/**
 * @file array.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief 从函数返回数组
 * @version 0.1
 * @date 2023-06-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

int *GetRandom()
{
    static int r[10];       // 方法1动态申请，方法2静态局部变量
    // int r[10];           // 不能返回
    int i;
    srand((unsigned)time(NULL));
    for (i = 0; i < 10; i++)
    {
        r[i] = rand();
        printf("r[%d]     = %10d\n", i, r[i]);
    }
    return r;
}

static void Test1(void)
{
    int *p;
    int i;
    p = GetRandom();
    for (i = 0; i < 10; i++)
    {
        printf("*(p + %d) = %10d\n", i, *(p + i));
    }
}

void GetRandomArray(int *arr, const uint32_t len)
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < len; i++)
    {
        arr[i] = rand();
        printf("%d: arr[%d]   = %10d\n", __LINE__, i, arr[i]);
    }
}

static void Test2(void)
{
    uint32_t len = 10;
    int arr[len];
    GetRandomArray(arr, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d: arr[%d]   = %10d\n", __LINE__, i, arr[i]);
    }
}

int main()
{
    Test2();
    return 0;
}