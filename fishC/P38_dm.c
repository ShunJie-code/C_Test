/**
 * @file P38_dm.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief 动态内存管理
 * @version 0.1
 * @date 2023-08-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

void Test1(void)
{
    int *ptr = NULL;
    int i;

    ptr = (int *)malloc(N * sizeof(int));
    if (ptr == NULL) {
        exit(1);
    }

    memset(ptr, 0, N * sizeof(int));

    for (i = 0; i < N; i++) {
        printf("%d ", ptr[i]);
    }
    putchar('\n');
    free(ptr);
}

/**
 * @brief calloc 分配内存空间并初始化为0
 * 
 */
void Test2(void)
{
    int i, num;
    int count;
}
int main(void)
{
    Test1();
    return 0;
}