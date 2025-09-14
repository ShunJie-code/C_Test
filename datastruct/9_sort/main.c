/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 第九章 排序算法
 * @version 0.1
 * @date 2025-05-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "common_9.h"

// #define MAXSIZE 10

typedef void (*TestFunc)(void);

static void ShowSqList(const SqList *ls)
{
    for (int i = 1; i <= ls->length; i++)
        printf("%d ", ls->r[i]);
    printf("\n");
}

void Test0(void)
{
    SqList ls = {
        .r = {0, 9, 1, 5, 8, 3, 7, 4, 6, 2},
        .length = 9
    };
    SqList ls2;
    ls2 = ls;
    BubbleSort(&ls2);
    printf("After BubbleSort:\n");
    ShowSqList(&ls2);

    ls2 = ls;
    printf("Before InsertSort:\n");
    ShowSqList(&ls2);

    InsertSort(&ls2);
    printf("After InsertSort:\n");
    ShowSqList(&ls2);

    ls2 = ls;
    SelectSort(&ls2);
    printf("After SelectSort:\n");
    ShowSqList(&ls2);
}

void Test1(void)
{
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
        // printf("The %d param is %s\n", i, argv[i]); // The 0 param is ./main
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