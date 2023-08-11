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
    // #undef PI // 支持去宏定义
    s = r * r * PI;
    printf("Circular area: %.2lf\n", s);
}
// 求个体积
#define R 6613

// 带参数的宏定义
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
void Test2(void)
{
    int x, y;
    printf("Please enter two int:");
    scanf("%d%d", &x, &y);
    printf("%d is the Max", MAX(x, y));
}

#define squre(x) ((x) * (x))
void Test3(void)
{
    
}
int main()
{
    Test1();
    return 0;
}