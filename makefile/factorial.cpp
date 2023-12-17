/**
 * @file factorial.cpp
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief 递归求阶乘
 * @version 0.1
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "functions.h"

int Factorial(int n)
{
    if (n == 1) 
    {
        return 1;
    }
    else
    {
        return n * Factorial(n - 1);
    }
}