/**
 * @file BFSTraverse.c
 * @author your name (you@domain.com)
 * @brief 邻接矩阵的广度遍历算法,Breadth first search
 * @version 0.1
 * @date 2025-02-15
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <stdio.h>
#include <stdbool.h>
#include "graph.h"
#include "linkqueue.h"

static bool visited[MAXVEX];

void BFS_Traverse(MGraph G)
{
    int i, j;
    LinkQueue q;
    for (i = 0; i < G.numVertexes; i++)
        visited[i] = false;
    // 初始化一辅助用的队列
    LQInit(&q);
    for (i = 0; i < G.numVertexes; i++)
    {
        printf("%s_%d\n", __func__, __LINE__);
        if (!visited[i])
        {
            visited[i] = true;
            printf("%c ", G.vexs[i]);
            LQEnter(&q, i);
            while (LQEmpty(&q) == FALSE) // 队列非空,!!!连通图靠这个队列即可遍历所有
            {
                printf("%s_%d\n", __func__, __LINE__);
                LQOut(&q, &i); // 关键是理解队列的剔除与插入
                for (j = 0; j < G.numVertexes; j++)
                {
                    // 默认是图不是网，所以边的权为1
                    if (G.arc[i][j] == 1 && !visited[j])
                    {
                        visited[j] = TRUE;
                        printf("%c ", G.vexs[j]);
                        LQEnter(&q, j);
                    }
                }
            }
        }
    }
}

void MGraphBfs(MGraph g)
{
    BFS_Traverse(g);
}
