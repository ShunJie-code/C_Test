/**
 * @file p51_union.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief 学习联合体的使用
 * @version 0.1
 * @date 2023-07-23
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <stdio.h>
#include <string.h>

union Test
{
    int i;
    char str[10];
    double pi;
};

void Test1(void)
{
    printf("\n[%s] %s:\n", __DATE__, __FUNCTION__);
    union Test test;
    test.i = 10;
    test.pi = 3.1415;
    strcpy(test.str, "FishC");

    printf("addr of test.i : %p\n", &test.i);
    printf("addr of test.pi : %p\n", &test.pi);
    printf("addr of test.str : %p\n", &test.str);
    
    // 共用体的值会相互覆盖
    printf("test.i : %d\n", test.i);
    printf("test.pi : %.2f\n", test.i);
    printf("test.i : %s\n", test.str);

    printf("size of test = %zd\n", sizeof(test));
}

void Test2(void)
{
    printf("\n[%s] %s:\n", __DATE__, __FUNCTION__);
    double pi = 3.1415926;
    printf("pi = %.2f\n", pi);
    printf("pi = %.3f\n", pi);
    printf("pi = %.4f\n", pi);
}

void Test3(void)
{
    printf("\n[%s] %s:\n", __DATE__, __FUNCTION__);
    // 直接初始化 同类变量初始化 c99新特性初始化
    union Test data0 = {520};
    union Test data1 = data0;
    union Test data2 = {.str = "hello"};
    printf("%d\n", data0.i);
    printf("%d\n", data1.i);
    printf("%s\n", data2.str);
}

int main()
{
    Test1();
    Test2();
    Test3();
    return 0;
}