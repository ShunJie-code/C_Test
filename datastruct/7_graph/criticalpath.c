#include <stdio.h>

#include "criticalpath.h"

// etv 顶点最早发生时间
// ltv 顶点最晚发生时间
// ete 弧最早发生时间
// lte 弧最晚发生时间

int *etv;    // 事件最早发生时间
int *ltv;    // 事件最晚发生时间
int *stack2; // 存储拓扑序列的栈
int top2;    // 栈指针


int CpTopologicalSort(PGraphAdjList g)
{
    EdgeNode *e;
    int i, k, gettop;
    int top = 0; /* 用于栈指针下标 */
    int count = 0;
    int *stack; /* 栈，存储入度为0的顶点下标 */
    stack = (int *)malloc(g->numVertexes * sizeof(int));
    if (!stack)
        return -1;
    for (i = 0; i < g->numVertexes; i++)
    {
        if (g->adjList[i].in == 0)
            stack[top++] = i;     // 从0开始入栈；哪怕每个节点的入度都为0，也不会越界
    }
    top2 = 0;
    etv = (int *)malloc(g->numVertexes * sizeof(int));
    while (top != 0)
    {
        gettop = stack[--top];
        printf("->%d", g->adjList[gettop].data);
        count++;
        for (e = g->adjList[gettop].firstegde; e; e = e->next)
        {
            k = e->adjvex;
            if (--g->adjList[k].in == 0)
                stack[top++] = k;
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
