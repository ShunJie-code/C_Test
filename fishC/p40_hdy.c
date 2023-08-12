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

// 宏定义支持嵌套，求个地球体积
#define R 6371
#define V PI * R * R * R * 4 / 3
void Test2(void)
{
    printf("Earth's volume is %f\n", V);
}

// 带参数的宏定义
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
void Test3(void)
{
    int x, y;
    printf("Please enter two int:");
    scanf("%d%d", &x, &y);
    printf("%d is the Max\n", MAX(x, y));
}

#define SQUARE(x) ((x) * (x))
void Test4(void)
{
    double x;
    int y;
    printf("Please enter a double: ");
    scanf("%lf", &x);
    printf("Square of double is %lf\n", SQUARE(x));
    printf("Please enter a int: ");
    scanf("%d", &y);
    printf("Square of int is %d\n", SQUARE(y));
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    return 0;
}