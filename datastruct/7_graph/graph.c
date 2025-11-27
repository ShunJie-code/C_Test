#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

static void AssignmentEdge(MGraph *g, int i, int j, int w)
{
    g->arc[i][j] = w;
    g->arc[j][i] = g->arc[i][j];
    // printf("边[%d][%d] = %d\n", j, i, g->arc[j][i]);
}
/**
 * @brief 插入有向边
 * 
 * @param i 
 * @param j 
 * @param g 
 */
static void InsertDirEdge(int i, int j, GraphAdjList *g)
{
    EdgeNode *e;
    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e->adjvex = j;
    // 头插法
    e->next = g->adjList[i].firstegde;
    g->adjList[i].firstegde = e;
}

/**
 * @brief 插入有向边-带权值
 * 
 * @param i 
 * @param j 
 * @param weight 
 * @param g 
 */
static void InsertWeightDirEdge(int i, int j, int weight, GraphAdjList *g)
{
    EdgeNode *e;
    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e->adjvex = j;
    e->weight = weight;
    // 头插法
    e->next = g->adjList[i].firstegde;
    g->adjList[i].firstegde = e;
}

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
            g->arc[i][j] = INFINITY;
    for (k = 0; k < g->numEdges; k++)
    {
        printf("3 输入边的下标(从0开始)和权(i,j,w):\n");
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
    printf("2 请输入每个顶点的数据(1 2 3 ...):\n");
    for (i = 0; i < g->numVertexes; i++)
    {
        scanf(" %d", &g->adjList[i].data);
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
        // 无向图需要
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = i;

        e->next = g->adjList[j].firstegde;
        g->adjList[j].firstegde = e;
    }
}

void MGraphCreateForMiniSpanTree(MGraph *g)
{
    int i, j;
    g->numVertexes = 9;
    g->numEdges = 15;
    printf("1 图顶点数 %d 边数 %d\n", g->numVertexes, g->numEdges);
    printf("2 %s每个顶点的数据: ", __func__);
    for (i = 0; i < g->numVertexes; i++)
    {
        g->vexs[i] = 'a' + i;
        printf("%c ", g->vexs[i]);
    }
    printf("\n");

    for (i = 0; i < g->numVertexes; i++)
        for (j = 0; j < g->numVertexes; j++)
            g->arc[i][j] = INFINITY;
    AssignmentEdge(g, 0, 1, 10);
    AssignmentEdge(g, 0, 5, 11);
    AssignmentEdge(g, 1, 2, 18);
    AssignmentEdge(g, 1, 6, 16);
    AssignmentEdge(g, 1, 8, 12);
    AssignmentEdge(g, 2, 3, 22);
    AssignmentEdge(g, 2, 8,  8);
    AssignmentEdge(g, 3, 4, 20);
    AssignmentEdge(g, 3, 6, 24);
    AssignmentEdge(g, 3, 7, 16);
    AssignmentEdge(g, 3, 8, 21);
    AssignmentEdge(g, 4, 5, 26);
    AssignmentEdge(g, 4, 7,  7);
    AssignmentEdge(g, 5, 6, 17);
    AssignmentEdge(g, 6, 7, 19);
}

void MGraphCreateForShortestPath(MGraph *g)
{
    int i, j;
    g->numVertexes = 9;
    g->numEdges = 16;
    printf("1 教材图顶点数 %d 边数 %d\n", g->numVertexes, g->numEdges);
    printf("2 %s每个顶点的数据: ", __func__);
    for (i = 0; i < g->numVertexes; i++)
    {
        g->vexs[i] = 'a' + i;
        printf("%c ", g->vexs[i]);
    }
    printf("\n");

    for (i = 0; i < g->numVertexes; i++)
        for (j = 0; j < g->numVertexes; j++)
            g->arc[i][j] = INFINITY;
    AssignmentEdge(g, 0, 1, 1);
    AssignmentEdge(g, 0, 2, 5);
    AssignmentEdge(g, 1, 2, 3);
    AssignmentEdge(g, 1, 3, 7);
    AssignmentEdge(g, 1, 4, 5);
    AssignmentEdge(g, 2, 4, 1);
    AssignmentEdge(g, 2, 5, 7);
    AssignmentEdge(g, 3, 4, 2);
    AssignmentEdge(g, 3, 6, 3);
    AssignmentEdge(g, 4, 5, 3);
    AssignmentEdge(g, 4, 6, 6);
    AssignmentEdge(g, 4, 7, 9);
    AssignmentEdge(g, 5, 7, 5);
    AssignmentEdge(g, 6, 7, 2);
    AssignmentEdge(g, 6, 8, 7);
    AssignmentEdge(g, 7, 8, 4);
}

void ALGraphCreateForTopoSort(GraphAdjList *g)
{
    int i;
    g->numVertexes = 14;
    g->numEdges = 20;

    for (i = 0; i < g->numVertexes; i++)
    {
        g->adjList[i].data = i;
        g->adjList[i].firstegde = NULL;
    }

    g->adjList[0].in = 0;
    g->adjList[1].in = 0;
    g->adjList[2].in = 2;
    g->adjList[3].in = 0;
    g->adjList[4].in = 2;
    g->adjList[5].in = 3;
    g->adjList[6].in = 1;
    g->adjList[7].in = 2;
    g->adjList[8].in = 2;
    g->adjList[9].in = 2;
    g->adjList[10].in = 1;
    g->adjList[11].in = 2;
    g->adjList[12].in = 1;
    g->adjList[13].in = 2;

    InsertDirEdge(0, 4, g);
    InsertDirEdge(0, 5, g);
    InsertDirEdge(0, 11, g);
    InsertDirEdge(1, 2, g);
    InsertDirEdge(1, 4, g);
    InsertDirEdge(1, 8, g);
    InsertDirEdge(2, 5, g);
    InsertDirEdge(2, 6, g);
    InsertDirEdge(2, 9, g);
    InsertDirEdge(3, 2, g);
    InsertDirEdge(3, 13, g);
    InsertDirEdge(4, 7, g);
    InsertDirEdge(5, 8, g);
    InsertDirEdge(5, 12, g);
    InsertDirEdge(6, 5, g);
    InsertDirEdge(8, 7, g);
    InsertDirEdge(9, 10, g);
    InsertDirEdge(9, 11, g);
    InsertDirEdge(10, 13, g);
    InsertDirEdge(12, 9, g);
}

void ALGraphCreateForCriticalPath(GraphAdjList *g)
{
    int i;
    g->numVertexes = 10;
    g->numEdges = 13;

    for (i = 0; i < g->numVertexes; i++)
    {
        g->adjList[i].data = i;
        g->adjList[i].firstegde = NULL;
    }

    g->adjList[0].in = 0;
    g->adjList[1].in = 1;
    g->adjList[2].in = 1;
    g->adjList[3].in = 2;
    g->adjList[4].in = 2;
    g->adjList[5].in = 1;
    g->adjList[6].in = 1;
    g->adjList[7].in = 2;
    g->adjList[8].in = 1;
    g->adjList[9].in = 2;

    InsertWeightDirEdge(0, 1, 3, g);
    InsertWeightDirEdge(0, 2, 4, g);
    InsertWeightDirEdge(1, 3, 5, g);
    InsertWeightDirEdge(1, 4, 6, g);
    InsertWeightDirEdge(2, 3, 8, g);
    InsertWeightDirEdge(2, 5, 7, g);
    InsertWeightDirEdge(3, 4, 3, g);
    InsertWeightDirEdge(4, 6, 9, g);
    InsertWeightDirEdge(4, 7, 4, g);
    InsertWeightDirEdge(5, 7, 6, g);
    InsertWeightDirEdge(6, 9, 2, g);
    InsertWeightDirEdge(7, 8, 5, g);
    InsertWeightDirEdge(8, 9, 3, g);
}