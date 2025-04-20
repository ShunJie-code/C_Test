#include <stdio.h>
#include "mtly.h"

#define BOARD_SIZE 8

// 马的 8 种可能移动方向
int moveX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int moveY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

// 检查 (x, y) 是否在棋盘内且未被访问过
bool isSafe(int x, int y, int board[BOARD_SIZE][BOARD_SIZE])
{
    return (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] == -1);
}

// 深度优先搜索函数
bool dfs(int x, int y, int moveCount, int board[BOARD_SIZE][BOARD_SIZE])
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
bool solveKnightTour(int startX, int startY)
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
