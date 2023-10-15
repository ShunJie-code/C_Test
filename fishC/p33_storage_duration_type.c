/**
 * @file p33_storage_duration_type.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief 生存期和存储类型
 * @version 0.1
 * @date 2023-10-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

/* 
代码块中声明的变量默认的存储类型就是‘自动变量’ auto关键字可以省略
存放在CPU的寄存器中的变量为‘寄存器变量’，不可以获取地址
*/ 
void Test1(void)
{
    short a;
    register int i = 520;
    // printf("Addr of i: %p\n", &i); //error: address of register variable 'i' requested
}

// static 和 extern具有静态存储器
void Test2(void)
{
    static int count = 0; // 作用域不变，生存期发生改变
    printf("count = %d\n", count);
    count++;
}
extern void func(void);
int g_count = 520;

int main()
{
    Test1();
    for (int i = 0; i < 5; i++)
    {
        Test2();
    }
    func();
     
    return 0;
}