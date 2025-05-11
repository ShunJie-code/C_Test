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

void Mtly(int startX, int startY)
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
    if (Travelchess(startX, startY, 1))
        printf("Success!\n");
    else
        printf("Fail!\n");
}

// 解法2
#define BOARD_SIZE 8

// 马的 8 种可能移动方向
int moveX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int moveY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

// 检查 (x, y) 是否在棋盘内且未被访问过
static bool isSafe(int x, int y, int board[BOARD_SIZE][BOARD_SIZE])
{
    return (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] == -1);
}

// 深度优先搜索函数
static bool dfs(int x, int y, int moveCount, int board[BOARD_SIZE][BOARD_SIZE])
{
    if (moveCount == BOARD_SIZE * BOARD_SIZE)
    {
        return true;
    }
    int nextX, nextY;
    for (int i = 0; i < 8; i++)
    {
        nextX = x + moveX[i];
        nextY = y + moveY[i];
        if (isSafe(nextX, nextY, board))
        {
            board[nextX][nextY] = moveCount;
            if (dfs(nextX, nextY, moveCount + 1, board))
            {
                return true;
            }
            else
            {
                board[nextX][nextY] = -1; // 回溯
            }
        }
    }
    return false;
}

// 解决马踏联营问题
bool SolveKnightTour(int startX, int startY)
{
    int board[BOARD_SIZE][BOARD_SIZE];
    // 初始化棋盘，所有格子标记为未访问
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = -1;
        }
    }
    // 标记起始位置
    board[startX][startY] = 0;
    if (dfs(startX, startY, 1, board))
    {
        // 打印棋盘
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                printf("%3d", board[i][j]);
            }
            printf("\n");
        }
        return true;
    }
    else
    {
        printf("没有找到解决方案。\n");
        return false;
    }
}