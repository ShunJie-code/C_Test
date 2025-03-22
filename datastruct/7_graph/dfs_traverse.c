// tips:这是C语言版，可能有的语法我掌握不全，那就先抄抄书上的代码
// 做到相对正确即可
#include <stdio.h>
#include <stdbool.h>
#include "graph.h"

typedef int Boolean;
Boolean visited[MAXVEX];

// 邻接矩阵的深度优先递归算法
static void MG_DFS(MGraph G, int i)
{
    // printf("%s_%d\n", __func__, __LINE__);
    int j;
    visited[i] = true;
    printf("%c ", G.vexs[i]); // 遍历到该点后，打印顶点
    for (j = 0; j < G.numVertexes; j++)
    {
        if (G.arc[i][j] == 1 && !visited[j]) // 不带权值，不是网，没被访问过就执行
            MG_DFS(G, j);
    }
}

void MGraphDfs(MGraph g)
{
    int i;
    for (i = 0; i < g.numVertexes; i++)
        visited[i] = false; // 将所有顶点状态都定义为未访问
    for (i = 0; i < g.numVertexes; i++)
        if (!visited[i])
        {
            // 对未访问的顶点调用DFS,若是连通图，只会执行1次
            printf("%s one times\n", __func__);
            MG_DFS(g, i);
        }
    printf("\n%s finish\n", __func__);
}

// 邻接表的深度优先递归算法
static void ALG_DFS(const GraphAdjList *alg, int i)
{
    EdgeNode *p;
    visited[i] = true;
    printf("%c ", alg->adjList[i].data);
    p = alg->adjList[i].firstegde;
    while (p)
    {
        if (!visited[p->adjvex])
        {
            ALG_DFS(alg, p->adjvex);
        }
        p = p->next;
    }
}

void ALGraphDfs(const GraphAdjList *g)
{
    int i;
    for (i = 0; i < g->numVertexes; i++)
    {
        visited[i] = false;
    }
    for (i = 0; i < g->numVertexes; i++)
    {
        if (!visited[i])
        {
            // 对未访问的顶点调用DFS,若是连通图，只会执行1次
            printf("%s one times\n", __func__);
            ALG_DFS(g, i);
        }
    }
    printf("\n%s finish\n", __func__);
}
