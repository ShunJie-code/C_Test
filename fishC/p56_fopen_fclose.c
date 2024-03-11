/**
 * @file p56_fopen_fclose.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief 打开和关闭文件
 * @version 0.1
 * @date 2023-07-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <stdlib.h>

void Test1(void)
{
    FILE *fp;
    int ch = 0;
    fp = fopen("hello.txt", "r");
    if (fp == NULL) 
    {
        printf("Fail to open file!\n");
        exit(EXIT_FAILURE);
    }
    while (ch != EOF)
    {
        ch = getc(fp);
        putchar(ch);
    }
    fclose(fp);
}

int main()
{
    Test1();
    return 0;
}