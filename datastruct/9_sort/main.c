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

#define TESTNUM 6
// #define MAXSIZE 10

typedef void (*TestFunc)(void);

static void ShowSqList(const SqList *ls)
{
    // todo show the SqList
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
    for (int i = 1; i <= ls2.length; i++)
        printf("%d ", ls2.r[i]);
    printf("\n");

    ls2 = ls;
    printf("Before InsertSort:\n");
    for (int i = 1; i <= ls2.length; i++)
        printf("%d ", ls2.r[i]);
    printf("\n");

    InsertSort(&ls2);
    printf("After InsertSort:\n");
    for (int i = 1; i <= ls2.length; i++)
        printf("%d ", ls2.r[i]);
    printf("\n");

    ls2 = ls;
    SelectSort(&ls2);
    printf("After SelectSort:\n");
    for (int i = 1; i <= ls2.length; i++)
        printf("%d ", ls2.r[i]);
    printf("\n");
}

void Test1(void)
{

}

void Test2(void)
{

}

void Test3(void)
{

}

void Test4(void)
{

}

void Test5(void)
{

}

static void RunFromEnterNum(int argc, char *argv[])
{
    int testNum = -1;
    TestFunc testFunc[TESTNUM] = {Test0, Test1, Test2,
                                  Test3, Test4, Test5};
    for (int i = 0; i < argc; i++)
    {
        printf("The %d param is %s\n", i, argv[i]);
        if (i >= 1)
        {
            testNum = atoi(argv[i]);
            if (testNum >= 0 && testNum < TESTNUM)
                testFunc[testNum]();
            else
                printf("Please enter a correct test number\n");
        }
    }
} 

int main(int argc, char* argv[])
{
    RunFromEnterNum(argc, argv);
    return 0;
}