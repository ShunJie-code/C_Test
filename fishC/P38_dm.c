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
 * Test2 与 Test1 的写法等价
 */
void Test2(void)
{
    int i;
    int *ptr;
    ptr = (int *)calloc(N, sizeof(int));
    for (i = 0; i < N; i++) {
        printf("%d ", ptr[i]);
    }
    putchar('\n');
    free(ptr);
}

void Test3(void)
{
    // realloc 重新指定大小、内存节能
    int i, num;
    int count = 0;
    int *ptr = NULL;
    do
    {
        printf("Please enter a int: ");
        scanf("%d", &num);
        count++;
        ptr = (int *)realloc(ptr, count * sizeof(int));
        if (ptr == NULL) {
            exit(1);
        }
        ptr[count - 1] = num;
    } while (num != -1);

    printf("What you enter are: ");
    for (i = 0; i < count; i++) {
        printf("%d ", ptr[i]);
    }
    putchar('\n');
    free(ptr);
}
int main(void)
{
    Test1();
    Test2();
    Test3();
    return 0;
}