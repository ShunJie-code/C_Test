// tips:这是C语言版，可能有的语法我掌握不全，那就先抄抄书上的代码
// 做到相对正确即可
#include <stdio.h>
#include <stdbool.h>
#include "graph.h"

typedef int Boolean;
Boolean visited[MAX];

// 邻接矩阵的深度优先递归算法
void DFS(MGraph G, int i)
{
    int j;
    visited[i] = true;
    printf("%c", G.vexs[i]); // 遍历到该点后，打印顶点
    for (j = 0; j < G.numVertexes; j++)
    {
        if (G.arc[i][j] == 1 && !visited[j]) // 不带权值，不是网，没被访问过就执行
            DFS(G, j);
    }
}

// 邻接表的深度优先递归算法
void DfS(GraphAdjList GL, int i)
{
    EdgeNode *p;
    visited
}

// 遍历操作函数体
void DFSTraverse(MGraph G)
{
    int i;
    for (i = 0; i < G.numVertexes; i++)
        visited[i] = false; // 将所有顶点状态都定义为未访问
    for (i = 0; i < G.numVertexes; i++)
        if (!visited[i])
            DFS(G, i);
}