#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void MGraphCreate(MGraph *g)
{
    int i, j, k, w;
    printf("1 请输入顶点数和边数(n,m):\n");
    scanf("%d,%d", &g->numVertexes, &g->numEdges);
    printf("2 请输入每个顶点的数据(a b c ...):\n");
    for (i = 0; i < g->numVertexes; i++)
        scanf(" %c", &g->vexs[i]);
    for (i = 0; i < g->numVertexes; i++)
        for (j = 0; j < g->numVertexes; j++)
            g->arc[i][i] = INFINITY;
    for (k = 0; k < g->numEdges; k++)
    {
        printf("3 输入边的下标和权(i,j,w):\n");
        scanf("%d,%d,%d", &i, &j, &w);
        g->arc[i][j] = w;
        g->arc[j][i] = g->arc[i][j];
        printf("图顶点vexs[%d] = %c\n", i, g->vexs[i]);
        printf("邻接矩阵arc[%d][%d] = %d\n", j, i, g->arc[j][i]);
    }
}

void ALGraphCreate(GraphAdjList *g)
{
    int i;
    int j;
    int k;
    EdgeNode *e;
    printf("1 请输入顶点和边数(n,m):\n");
    scanf("%d,%d", &g->numVertexes, &g->numEdges);
    printf("2 请输入每个顶点的数据(a b c ...):\n");
    for (i = 0; i < g->numVertexes; i++)
    {
        scanf(" %c", &g->adjList[i].data);
        g->adjList[i].firstegde = NULL;
    }
    for (k = 0; k < g->numEdges; k++)
    {
        printf("3 输入边Vi Vj上的顶点序号(i,j): \n");
        scanf("%d,%d", &i, &j);
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = j;
        // 头插法
        e->next = g->adjList[i].firstegde;
        g->adjList[i].firstegde = e;

        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = i;

        e->next = g->adjList[j].firstegde;
        g->adjList[j].firstegde = e;
    }
}