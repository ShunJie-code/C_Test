/**
 * 32 递归和分治思想1，斐波那契数列
 * 33 递归和分治思想2，二分法，折半查找算法
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "recursion.h"
#include "kmp.h"

static void Test1(void)
{
    int i;
    int a[40];
    a[0] = 0;
    a[1] = 1;
    printf("1 迭代方法:\n");
    printf("%d %d ", a[0], a[1]);
    for (i = 2; i < 40; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
        printf("%d ", a[i]);
    }
    putchar('\n');
    printf("2 递归方法:\n");
    for (i = 0; i < 40; i++)
        printf("%d ", Fib(i));
    putchar('\n');
    printf("3 递归方法计算阶乘, 请输入n: ");
    scanf("%d", &i);
    printf("%d! = %d\n", i, Factorial(i));
    ReversePrint();
    return;
}

static void Test2(void)
{
    // char T[256] = " abcabx";
    char S[256] = " dsdsdabcabcabcx";
    char T[256] = " abcabcx";
    int next[256];
    int nextVal[256];
    S[0] = strlen(S) - 1;
    T[0] = strlen(T) - 1;
    printf("length of s and t is %d, %d\n", S[0], T[0]);
    GetNext(T, next);
    for (int i = 1; i <= T[0]; i++)
    {
        printf("%d ", next[i]);
    }
    putchar('\n');
    printf("GetNextVal:\n");
    GetNextVal(T, nextVal);
    for (int i = 1; i <= T[0]; i++)
    {
        printf("%d ", nextVal[i]);
    }
    putchar('\n');
    int index = Index_KMP(S, T, 2);
    printf("Index of T in S is %d\n", index);
}

static void Test3(void)
{
     
}
static void Test4(void)
{
     
}
static void Test5(void)
{
     
}
static void Test6(void)
{
     
}
int main(int argc, char *argv[])
{
    int testNum = 0;
    for (int i = 0; i < argc; i++)
    {
        printf("The %d param is %s\n", i, argv[i]);
        if (1 == i)
            testNum = atoi(argv[i]);
    }
    switch (testNum)
    {
    case 1:
        Test1();
        break;
    case 2:
        Test2();
        break;
    case 3:
        Test3();
        break;
    case 4:
        Test4();
        break;
    case 5:
        Test5();
        break;
    case 6:
        Test6();
        break;
    default:
        printf("Please enter a test number!\n");
        break;
    }
    return 0;
}