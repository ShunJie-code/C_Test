/**
 * @file malloc.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief
 * @version 0.1
 * @date 2023-06-29
 *
 * @copyright Copyright (c) 2023
 *
 */

// 内存泄露分两种，1种是没有用free释放内存，第2种是指向的地址丢失
#include <stdio.h>

void test1(void)
{
    char buf[1024] = {0};
    sprintf(buf, "this is %s.", "cool boy");
    printf("buf : %s\n", buf);
}
int main(void)
{
    test1();
    return 0;
}