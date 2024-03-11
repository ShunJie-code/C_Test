/**
 * @file p35_hanoi_tower.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief 1 前n-1 借助Z 从x->y
 *        2 将n 移动到z
 *        3 将Y上n - 1 借助X 到Z
 *        4    
 * @version 0.1
 * @date 2023-10-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

void Hanoi(int n, char x, char y, char z)
{
    if (n == 1)
    {
        printf("%c --> %c\n", x, z);
    }
    else
    {
        Hanoi(n - 1, x, z, y);
        printf("%c --> %c\n", x, z);
        Hanoi(n - 1, y, x, z);
    }
}

int main(void)
{
    int n;
    printf("Please enter a number:");
    scanf("%d", &n);
    Hanoi(n, 'X', 'Y', 'Z');
    return 0;
}
