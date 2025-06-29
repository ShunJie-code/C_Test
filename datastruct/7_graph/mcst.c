#include "mcst.h"
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
        // 打印生成最小路径树的过程
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

static int Find(int parent[], int f)
{
    // 查找顶点i的根节点
    while (parent[f] > 0)
    {
        f = parent[f];
    }
    return f;
}

void MiniSpanTreeKruskal(MGraph graph)
{
    // Kruskal算法实现
    int i, j;
    int parent[MAXVEX];                 // 存储每个顶点的父节点，用于判断边与边是否形成回路
    Edge edges[MAXVEX * MAXVEX];    // 存储所有边，边集数组
    int edgeCount = 0;

    // 初始化父节点
    for (i = 0; i < graph.numVertexes; i++)
    {
        parent[i] = 0; 
    }
    
    // 初始化边集
    for (i = 0; i < graph.numVertexes; i++)
    {
        for (j = i + 1; j < graph.numVertexes; j++)
        {
            if (graph.arc[i][j] != INFINITY)
            {
                edges[edgeCount].begin = i;
                edges[edgeCount].end = j;
                edges[edgeCount].weight = graph.arc[i][j];
                edgeCount++;
            }
        }
    }

    // 按边权排序-冒泡排序算法
    for (i = 0; i < edgeCount - 1; i++)
    {
        for (j = edgeCount - 2; j >= i; j--)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // Kruskal算法核心
    for (i = 0; i < edgeCount; i++)
    {
        int startRoot = Find(parent, edges[i].begin);
        int endRoot = Find(parent, edges[i].end);
        if (startRoot != endRoot) // 如果不在同一集合中
        {
            printf("Edge (%c, %c) with weight %d\n", 
                graph.vexs[edges[i].begin], graph.vexs[edges[i].end], edges[i].weight);
            parent[startRoot] = endRoot; // 合并集合
        }
    }
}