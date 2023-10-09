/**
 * @file p53_bit_field.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief 位域
 * @version 0.1
 * @date 2023-10-09
 *
 * @copyright Copyright (c) 2023
 * 位域的宽度不能大于数据类型的长度，否则直接error
 */
#include <stdio.h>

void Test1(void)
{
    // 位域只支持 unsigned 变量，无法取地址
    struct Test
    {
        unsigned int a : 1;
        unsigned int b : 1;
        unsigned int c : 2;
        unsigned int d : 2;
        unsigned int   : 4; // 无名位域也可以
        unsigned int e : 20;
    };

    struct Test test;
    test.a = 0;
    test.b = 1;
    test.c = 2;
    // test.d = 4; 两位只能存0 1 2 3，4会超出范围 

    printf("a = %d, b = %d, c = %d\n", test.a, test.b, test.c);
    printf("size of test = %d\n", sizeof(test)); // 一个int的大小4个字节 32位
}

int main(void)
{
    Test1();
    return 0;
}