/**
 * @file p39_ma.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief c语言内存布局
 * @version 0.1
 * @date 2023-08-06
 * 此代码需要在linux下验证
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int g_uninit_var;
int g_init_var1 = 520;
int g_init_var2 = 880;

void func(void)
{
    return;
}

void Test1(void) 
{
    int local_var1;
    int local_var2;
        
    static int static_uninit_var;
    static int static_init_var = 456;

    const char *str1 = "I love you";
    char *str2 = "You are right";

    int *malloc_var = (int *)malloc(sizeof(int));
    // 只读区Text 代码段+常量
    printf("Text segment:\n");
    printf("addr of func = %#p\n", func);
    printf("addr of str1 = %#p\n", str1);
    printf("addr of str2 = %#p\n", str2);
    // 数据段
    printf("Initialized data segment:\n");
    printf("addr of global_init_var1 = %#p\n", &g_init_var1);
    printf("addr of global_init_var2 = %#p\n", &g_init_var2);
    printf("addr of static_init_var = %#p\n", &static_init_var);
    // bss段 block started by symbol 未初始化的全局变量和静态变量，自动初始化为0
    printf("BSS segment:\n");
    printf("addr of static_uninit_var = %#p\n", &static_uninit_var);
    printf("addr of global_uninit_var = %#p\n", &g_uninit_var);
    // 堆地址
    printf("addr of malloc_var = %#p\n", malloc_var);
    // 栈地址
    printf("addr of local_var2 = %#p\n", &local_var2);
    printf("addr of local_var1 = %#p\n", &local_var1);
    free(malloc_var);
}

void Test2(void)
{
    int *ptr1 = NULL;
    int *ptr2 = NULL;
    ptr1 = (int *)malloc(sizeof(int));
    ptr2 = (int *)malloc(sizeof(int));
    printf("Stack: %#p -> %#p\n", &ptr1, &ptr2);
    printf("Heap: %#p -> %#p\n", ptr1, ptr2);
    // relloc不够存放则堆的地址会发生改变
    ptr1 = realloc(ptr1, 20 * sizeof(int));
    printf("Heap: %#p -> %#p\n", ptr1, ptr2);
    free(ptr1);
    free(ptr2);
}

void Test3(void)
{
    char a = 0, b = 0;
    int *p = (int *)&b;
    *p = 258;
    printf("%d %d %p\n", a, b, p);
}

int main(void)
{
    Test1();
    // Test2();
    // Test3();
    return 0;
}