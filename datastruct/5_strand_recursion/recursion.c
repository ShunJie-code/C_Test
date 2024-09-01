#include <stdio.h>
#include "recursion.h"

// 斐波那契数列
int Fib(uint16_t i)
{
    if (i < 2)
        return i;
    return Fib(i - 1) + Fib(i - 2);
}

// 计算阶乘
int Factorial(uint32_t n)
{
    if (0 == n)
        return 1;
    else
        return n * Factorial(n - 1);
}

// 倒序输出字符串
void ReversePrint(void)
{
    char c;
    scanf("%c", &c);
    if (c != '#')
    {
        ReversePrint();
    }
    if (c != '#')
    {
        printf("%c", c);
    }   
}
