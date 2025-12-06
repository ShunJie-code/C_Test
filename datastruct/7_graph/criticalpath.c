#include <stdio.h>
#include <stdlib.h>
#include "criticalpath.h"

int *etv;    // 顶点事件最早发生时间
int *ltv;    // 顶点事件最晚发生时间

int *stack2; // 存储拓扑序列的栈
int top2;    // 存储拓扑序列的栈指针

/**
 * 
 * @brief 关键路径拓扑排序
 * 
 * @param g 
 * @return int 
 */
int CpTopologicalSort(PGraphAdjList g)
{
    EdgeNode *e;
    int i, k, gettop;
    int top = 0; /* 用于栈指针下标 */
    int count = 0;
    int *stack; /* 栈，存储入度为0的顶点下标 */
    stack = (int *)malloc(g->numVertexes * sizeof(int));
    if (stack == NULL)
        return -1;
    for (i = 0; i < g->numVertexes; i++)
    {
        if (g->adjList[i].in == 0)
            stack[top++] = i;     // 从0开始入栈；哪怕每个节点的入度都为0，也不会越界
    }
    top2 = 0;
    etv = (int *)malloc(g->numVertexes * sizeof(int));  // 事件最早发生时间
    for (i = 0; i < g->numVertexes; i++)
    {
        etv[0] = 0;
    }
    stack2 = (int *)malloc(g->numVertexes * sizeof(int));
    while (top != 0)
    {
        gettop = stack[--top];
        printf("->%d", g->adjList[gettop].data);
        count++;
        stack2[top2++] = gettop;
        for (e = g->adjList[gettop].firstegde; e; e = e->next)
        {
            k = e->adjvex;
            if (--g->adjList[k].in == 0)
                stack[top++] = k;
            // 求各顶点时间最早发生的时间值
            if ((etv[gettop] + e->weight) > etv[k])
                etv[k] = etv[gettop] + e->weight;
        }
    }
    putchar('\n');
    if (count < g->numVertexes)
    {
        free(stack);
        return -1;
    }
    else
    {
        free(stack);
        return 0;
    }
}

void CriticalPath(PGraphAdjList g)
{
    EdgeNode *e;
    int i;
    int j;
    int k;
    int gettop;
    int ete;                // 弧最早发生时间
    int lte;                // 弧最晚发生时间
    CpTopologicalSort(g);
    ltv = (int *)malloc(g->numVertexes * sizeof(int));
    for (i = 0; i < g->numVertexes; i++)
    {
        ltv[i] = etv[g->numVertexes - 1];
    }
    while (top2 != 0)
    {
        gettop = stack2[--top2];
        for (e = g->adjList[gettop].firstegde; e; e = e->next)
        {
            k = e->adjvex;
            if (ltv[k] - e->weight < ltv[gettop])
                ltv[gettop] = ltv[k] - e->weight;
        }
    }
    // 求ete,lte,和关键活动路径
    for ( j = 0; j < g->numVertexes; j++)
    {
        for (e = g->adjList[j].firstegde; e; e = e->next)
        {
            k = e->adjvex;
            ete = etv[j];
            lte = ltv[k] - e->weight;
            if (ete == lte)
            {
                printf("<v%d,v%d> length: %d\n", 
                    g->adjList[j].data, 
                    g->adjList[k].data, 
                    e->weight);
            }
        }
    }
    free(etv);
    free(ltv);
    free(stack2);
}