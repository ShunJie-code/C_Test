/**
 * @file p34_recursion.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief 递归
 * @version 0.1
 * @date 2023-10-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

static void Recursion(void);

// 无休止的递归，会出现段错误
static void Recursion(void)
{
    static int count = 6;
    printf("Hi!\n");
    if (--count)
    {
        Recursion();
    }
}

// 写一个阶乘
long Fact(int num)
{
    long result;
    for (result = 1; num > 1; num--)
    {
        result *= num;
    }
    return result;
}

// 改成递归
long RecursionFact(int num)
{
    long result;
    if (num > 0)
    {
        result = num * RecursionFact(num - 1);
    }
    else
    {
        result = 1;
    }
    return result;
}

int main(void)
{
    // Recursion();
    long a = 6;
    // printf("%zd\n", sizeof(long)); // 4
    // printf("%zd\n", sizeof(long long)); // 8 
    printf("%ld! = %ld\n", a, Fact(a));
    printf("%ld! = %ld\n", a, RecursionFact(a));

    return 0;
}