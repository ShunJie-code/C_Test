/**
 * @file string.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief string.h 库函数练习
 * @version 0.1
 * @date 2023-07-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <string.h>
// #include <endian.h>

void Test1(void)
{
    printf("[%s] %s :\n", __DATE__, __FUNCTION__);

    char str[50];
    int len;
    
    strcpy(str, "This is runoob.com");
    // strlen's return is size_t; size_t is unsigned int
    len = strlen(str);
    printf("|%s|'s length is |%d|\n", str, len); // 字符串长度返回值是18 
}

void Test2(void)
{
    printf("[%s] %s :\n", __DATE__, __FUNCTION__);
    char buf[1024] = {0};
    sprintf(buf, "this is %s.", "cool boy");
    printf("buf : %s\n", buf);
}

int main()
{
    Test1();
    Test2();
    return 0;
}