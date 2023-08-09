/**
 * @file p40_hdy.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief 高级宏定义,本质还是替换
 * @version 0.1
 * @date 2023-08-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#define PI 3.14

void Test1(void)
{
    double r;
    double s;
    printf("Please enter circular' radius:\n");
    scanf("%lf", &r);
    s = r * r * PI;
    printf("Circular area: %.2lf\n", s);
}
int main()
{
    Test1();
    return 0;
}