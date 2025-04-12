#include <stdio.h>
#include <stdlib.h>
#include "mtly.h"
#define X 8
#define Y 8
int chess[X][Y];

/**
 * @brief 找到基于x,y下一个可走的位置
 *
 * @param x
 * @param y
 * @param count
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

/**
 * @brief 深度优先遍历棋盘
 * 
 * @param x 位置坐标
 * @param y 位置坐标
 * @param tag 标记变量，每走一步加1
 * @return int 
 */
int Traverlchess(int x, int y, int tag)
{
    chess[x][y] = count;
    if (count == X * Y - 1)
    {
        return 1;
    }
    for (int i = 0; i < 8; i++)
    {
        int nextx = x;
        int nexty = y;
        if (Nextxy(&nextx, &nexty, i) == 1)
        {
            if (Traverlchess(nextx, nexty, count + 1) == 1)
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
}