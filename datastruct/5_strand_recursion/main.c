/**
 * 32 递归和分治思想1，斐波那契数列
 * 33 递归和分治思想2，二分法，折半查找算法
 * 34 
 * 35
 * 36
 * 37
 * 38
 * 39
 * 40 kmp算法之实现及优化
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

// 验证KMP算法的next数组
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
}

// 验证完整的KMP算法
static void Test3(void)
{
    int index;
    char s[256] = " asdfasdfasdf";
    char t[256] = " df";
    char t1[256] = " gh";

    s[0] = strlen(s) - 1;
    t[0] = strlen(t) - 1;
    t1[0] = strlen(t1) - 1;

    index = Index_KMP(s, t, 1);
    printf("KMP: Index of %s in %s is %d\n", &t[1], &s[1], index);
    
    index = Index_KMP(s, t1, 1);
    printf("KMP: Index of %s in %s is %d\n", &t1[1], &s[1], index);

    index = Index_KMP_BETTER(s, t, 4);
    printf("KMP_BEETER: Index of %s in %s after 4 is %d\n", &t[1], &s[1], index);

    index = Index_KMP_BETTER(s, t1, 4);
    printf("KMP_BEETER: Index of %s in %s after 4 is %d\n", &t[1], &s[1], index);
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