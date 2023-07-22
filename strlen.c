/**
 * @file strlen.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief string.h库函数strlen用法
 * @version 0.1
 * @date 2023-04-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <string.h>

int main()
{
    char str[50];
    int len;

    strcpy(str, "This is runoob.com");
    len = strlen(str);
    printf("|%s|'s length is |%d|\n", str, len);

    return 0;
}
