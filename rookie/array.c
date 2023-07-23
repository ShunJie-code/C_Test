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

int *GetRandom()
{
    static int r[10];
    // int r[10];
    int i;
    srand((unsigned)time(NULL));
    for (i = 0; i < 10; i++)
    {
        r[i] = rand();
        printf("r[%d] = %d\n", i, r[i]);
    }
    return r;
}

int main()
{
    int *p;
    int i;
    p = GetRandom();
    for (i = 0; i < 10; i++)
    {
        printf("*(p + %d) = %d\n", i, *(p + i));
    }
    return 0;
}
