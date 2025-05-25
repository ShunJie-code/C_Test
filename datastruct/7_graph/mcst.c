#include "mcst.h"
#include "graph.h"
#include <stdio.h>

void MiniSpanTreePrim(MGraph graph)
{
    // Prim算法实现
    int min, i, j, k;
    int adjvex[MAXVEX]; // 存储已加入生成树的顶点
    int lowcost[MAXVEX]; // 存储每个顶点到生成树的最小边权
    adjvex[0] = 0; // 从第一个顶点开始
    lowcost[0] = 0; // 第一个顶点到生成树的边权为0
    for (i = 1; i < graph.numVertexes; i++)
    {
        lowcost[i] = graph.arc[0][i]; // 初始化边权
        adjvex[i] = 0;
    }
    for (i = 1; i < graph.numVertexes; i++)
    {
        min = INFINITY;
        k = 0;
        for (j = 1; j < graph.numVertexes; j++)
        {
            if (lowcost[j] < min && lowcost[j] != 0)
            {
                min = lowcost[j];
                k = j; // 找到最小边权的顶点
            }
        }
        printf("Edge (%c, %c) with weight %d\n", graph.vexs[adjvex[k]], graph.vexs[k], min);
        lowcost[k] = 0; // 标记已加入生成树
        for (j = 1; j < graph.numVertexes; j++)
        {
            if (graph.arc[k][j] < lowcost[j])
            {
                // 把下一层的赋值给lowcost
                lowcost[j] = graph.arc[k][j];
                adjvex[j] = k; // 更新边权和顶点
            }
        }
    }
}