#include <stdio.h>
#include "graph.h"

// 通过邻接矩阵建立无向网图
void CreateMGraph(MGraph *g)
{
    int i, j, k, w;
    printf("输入顶点数和边数:\n");
    scanf("%d,%d", &g->numVertexes, &g->numEdges);
    printf("请输入每个顶点的数据:\n");
    for (i = 0; i < g->numVertexes; i++)
        scanf(" %c", &g->vexs[i]);
    for (i = 0; i < g->numVertexes; i++)
        for (j = 0; j < g->numVertexes; j++)
            g->arc[i][i] = INFINITY;
    for (k = 0; k < g->numEdges; k++)
    {
        printf("输入边的下标i, j和权w:\n");
        scanf("%d,%d,%d", &i, &j, &w);
        g->arc[i][j] = w;
        g->arc[j][i] = g->arc[i][j];
        printf("图顶点vexs[%d] = %c\n", i, g->vexs[i]);
        printf("邻接矩阵arc[%d][%d] = %d\n", j, i, g->arc[j][i]);
    }
}