/**
 * @file Classic100_5.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief 输入三个数，将这三个数从小到大输出
 * @version 0.1
 * @date 2023-03-28
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <stdio.h>

int main(void)
{
    printf("please enter 3 int number:\n");
    int x, y, z;
    int temp;
    // 取值要加取址符号
    scanf("%d%d%d", &x, &y, &z);
    if (x > y)
    {
        temp = x;
        x = y;
        y = temp;
    }
    if (x > z)
    {
        temp = x;
        x = z;
        z = y;
        y = temp;
    }
    else if (y > z)
    {
        temp = z;
        z = y;
        y = temp;
    }
    printf("%d %d %d\n", x, y, z);
    return 0;
}