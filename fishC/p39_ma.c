/**
 * @file p39_ma.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief c语言内存布局
 * @version 0.1
 * @date 2023-08-06
 * 
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

    printf("addr of func = %#p\n", func);
    printf("addr of str1 = %#p\n", str1);
    printf("addr of str2 = %#p\n", str2);
    printf("addr of global_init_var1 = %#p\n", &g_init_var1);
    printf("addr of global_init_var2 = %#p\n", &g_init_var2);
    printf("addr of global_uninit_var = %#p\n", &g_uninit_var);
    printf("addr of static_init_var = %#p\n", &static_init_var);
    printf("addr of static_uninit_var = %#p\n", &static_uninit_var);
    printf("addr of malloc_var = %#p\n", malloc_var);
   
    printf("addr of local_var2 = %#p\n", &local_var2);
    printf("addr of local_var1 = %#p\n", &local_var1);
    free(malloc_var);
}

int main(void)
{
    Test1();
    return 0;
}