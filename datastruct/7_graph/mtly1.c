#include <stdio.h>
#include <stdlib.h>
#include "mtly.h"
#define X 8
#define Y 8
static int chess[X][Y];

/**
 * @brief 找到基于x,y下一个可走的位置
 *
 * @param x
 * @param y
 * @param count
 * @return int 可以走返回1，否则返回0
 */
int Nextxy(int *x, int *y, int count)
{
    switch (count)
    {
    case 0:
        if (*x + 2 < X &&
            *y - 1 >= 0 &&
            chess[*x + 2][*y - 1] == 0)
        {
            *x += 2;
            *y -= 1;
            return 1;
        }
        break;
    case 1:
        if (*x + 1 < X &&
            *y - 2 >= 0 &&
            chess[*x + 1][*y - 2] == 0)
        {
            *x += 1;
            *y -= 2;
            return 1;
        }
        break;
    case 2:
        if (*x - 1 >= 0 &&
            *y - 2 >= 0 &&
            chess[*x - 1][*y - 2] == 0)
        {
            *x -= 1;
            *y -= 2;
            return 1;
        }
        break;
    case 3:
        if (*x - 2 >= 0 &&
            *y - 1 >= 0 &&
            chess[*x - 2][*y - 1] == 0)
        {
            *x -= 2;
            *y -= 1;
            return 1;
        }
        break;
    case 4:
        if (*x - 2 >= 0 &&
            *y + 1 < Y &&
            chess[*x - 2][*y + 1] == 0)
        {
            *x -= 2;
            *y += 1;
            return 1;
        }
        break;
    case 5:
        if (*x - 1 >= 0 &&
            *y + 2 < Y &&
            chess[*x - 1][*y + 2] == 0)
        {
            *x -= 1;
            *y += 2;
            return 1;
        }
        break;
    case 6:
        if (*x + 1 < X &&
            *y + 2 < Y &&
            chess[*x + 1][*y + 2] == 0)
        {
            *x += 1;
            *y += 2;
            return 1;
        }
        break;
    case 7:
        if (*x + 2 < X &&
            *y + 1 < Y &&
            chess[*x + 2][*y + 1] == 0)
        {
            *x += 2;
            *y += 1;
            return 1;
        }
        break;
    default:
        break;
    }
    return 0;
}

void ShowChess(void)
{
    int i;
    int j;
    for (i = 0; i < X; i++)
    {
        for (j = 0; j < Y; j++)
        {
            printf("%2d\t", chess[i][j]);
        }
        printf("\n");
    }
    // printf("\n");
}

/**
 * @brief 深度优先遍历棋盘
 *
 * @param x 位置坐标
 * @param y 位置坐标
 * @param tag 标记变量，每走一步加1
 * @return int
 */
int Travelchess(int x, int y, int tag)
{
    chess[x][y] = tag;
    if (tag == 64)
    {
        // 打印棋盘
        ShowChess();
        return 1;
    }
    for (int i = 0; i < 8; i++)
    {
        int nextx = x;
        int nexty = y;
        if (Nextxy(&nextx, &nexty, i) == 1)
        {
            if (Travelchess(nextx, nexty, tag + 1) == 1)
            {
                return 1;
            }
            else
            {
                chess[nextx][nexty] = 0;
            }
        }
    }
    return 0;
}

void Mtly(void)
{
    int i;
    int j;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            chess[i][j] = 0;
        }
    }
    if (Travelchess(0, 0, 1))
        printf("Success!\n");
    else
        printf("Fail!\n");
}