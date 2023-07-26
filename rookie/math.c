/**
 * @file math.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief 验证数学计算
 * @version 0.1
 * @date 2023-07-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

void Test1(void)
{
    printf("[%s] %s :\n", __DATE__, __FUNCTION__);
    int a, b;
    a = 119;
    b = a /10;
    printf("b = %d\n", b);
}

void Test2(void)
{
    printf("[%s] %s :\n", __DATE__, __FUNCTION__);
    int int_a = 1;
    int int_b = 3;
    int int_c = MIN(int_a, int_b);
    printf("int MIN(a, b) = %d\n", int_c);
    double double_a = 1.78;
    double double_b = 2.99;
    double double_c = MAX(double_a, double_b);
    printf("double MAX(a, b) = %f\n", double_c);
}

int main()
{
    Test1();
    Test2();
    return 0;
}