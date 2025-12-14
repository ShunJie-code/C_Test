/**
 * 第8章 查找算法
 * 70 顺序查找
 * 
 * 74 二叉排序树
 */
#include <stdio.h>
#include <stdlib.h>
#include "common_8.h"
#include "search.h"
typedef void (*TestFunc)(void);

// 8.3 顺序查找/线性查找
void Test0(void)
{
    int a[] = {0, 1, 2, 3, 4, 5}; // 注意 0 查找不到，a[0]不存值
    int key = 8;
    ShowTimeStamp();
    int index = SqSearch(a, sizeof(a) / sizeof(int) - 1, key);
    CheckSearchResult(index, key);
    key = 5;
    index = SqSentinelSearch(a, sizeof(a) / sizeof(int) - 1, key);
    CheckSearchResult(index, key);
    ShowTimeStamp();
}

// 8.4 有序表查找
void Test1(void)
{
    int a[] = {0, 1, 2, 3, 4, 5}; // 注意 0 查找不到，a[0]不存值
    int key = 1;
    int index = BinarySearch(a, sizeof(a) / sizeof(int) - 1, key);
    CheckSearchResult(index, key);
    printf("%s\n", __func__);
}

void Test2(void)
{
    printf("%s\n", __func__);
}

void Test3(void)
{
    printf("%s\n", __func__);
}

void Test4(void)
{
    printf("%s\n", __func__);
}

void Test5(void)
{
    printf("%s\n", __func__);
}

int main(int argc, char* argv[])
{
    int testNum = -1;
    int testLength;
    TestFunc testFunc[] = {Test0, Test1, Test2,
                           Test3, Test4, Test5};
    testLength = sizeof(testFunc) / sizeof(TestFunc);

    for (int i = 0; i < argc; i++)
    {
        printf("The %d param is %s\n", i, argv[i]); // The 0 param is ./main
        if (i >= 1)
        {
            testNum = atoi(argv[i]);
            if (testNum >= 0 && testNum < testLength)
                testFunc[testNum]();
            else
                printf("Please enter a correct test number, max is %d\n", testLength);
        }
    }
    return 0;
}