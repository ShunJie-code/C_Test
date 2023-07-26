/**
 * @file p52_enum.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief 学习枚举类型的使用
 * @version 0.1
 * @date 2023-07-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <time.h>
// 枚举常量，int类型，默认从0开始
enum Week {
    sun, mon, tue, wed, thu, fri, sat
};

void Test1(void)
{
    printf("[%s] %s :\n", __DATE__, __FUNCTION__);
    enum Week today;
    struct tm *p;
    time_t t;

    time(&t);
    p = localtime(&t);
    today = p->tm_wday;

    switch (today)
    {
        case mon:
        case tue:
        case wed:
        case thu:
        case fri:
            printf("work day!\n");
            break;
        case sat:
        case sun:
            printf("holiday!\n");
            break;
    default:
        printf("Error\n");
        break;
    }
}

void Test2(void)
{
    printf("[%s] %s :\n", __DATE__, __FUNCTION__);
    enum Color {red = 10, green, blue};
    enum Color rgb;
    // c可以枚举变量++， Cpp不行
    for (rgb = red; rgb <= blue; rgb++) {
        printf("rgb = %d\n", rgb);
    }
}

void Test3(void)
{
    printf("[%s] %s :\n", __DATE__, __FUNCTION__);

    enum NewColor {red, green, blue = 10, yellow};

    printf("red = %d\n", red);
    printf("green = %d\n", green);
    printf("blue = %d\n", blue);
    printf("yellow = %d\n", yellow);
}

int main()
{
    Test1();
    Test2();
    Test3();
    return 0;
}