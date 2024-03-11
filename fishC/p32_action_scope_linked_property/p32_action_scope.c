/**
 * @file p32_action_scope.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief 作用域和连接属性
 * @version 0.1
 * @date 2023-10-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

// 1 大括号里面代码的是代码块作用域
static void Test1(void)
{
    int i = 100;
    {
        int i = 110;
        {
            int i = 120;
            printf("i = %d\n", i);
        }
        printf("i = %d\n", i);
    }
    printf("i = %d\n", i);
}

// 2 任何在代码块外声明的变量都具备文件作用域
int count;
void a(void);
void b(void);
static void Test2(void)
{
    a();
    b();
    count++;
    printf("count = %d\n", count);
}

int main(void)
{
    Test1();
    Test2();
    return 0;
}
