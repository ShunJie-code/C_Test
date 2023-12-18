/**
 * @file p20_array.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief 二维数据
 * @version 0.1
 * @date 2023-12-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

int main(void)
{
    int a[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%3d ", a[i][j]);
        }
        putchar('\n');
    }
    return 0;    
}