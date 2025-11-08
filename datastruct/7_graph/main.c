/**
 * 第7章 图
 * 55 图的定义与术语
 * 56 图的定义与术语
 * 57 图的存储结构
 * 58 图的存储结构 (邻接图、邻接表)
 * 59 图的存储结构 (十字链表，邻接多重表，边集数组)
 *      十字链表：解决邻接表无法同时获取有向图出度和入度的问题
 *      邻接多重表：
 * 60 图的遍历-深度优先
 * 61 马踏连营算法，马可以遍历棋盘所有的点
 * 62 图的遍历-广度优先
 * 63 最小生成树-Prim：普里姆
 * 64 最小生成树-kruskal：克鲁斯卡尔
 * 65 最短路径-dijkstra: 迪杰斯特拉
 * 66 最短路径-floyd：弗洛伊德
 * 67 拓扑排序
 * 68 关键路径
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graph.h"
#include "mtly.h"
#include "mcst.h"
#include "shortestpath.h"
#include "topologicalsort.h"

/**
 * @brief 测试字符读取
 *
 */
void Test0(void)
{
    char ch1, ch2, ch3;
    printf("Enter three characters: ");
    scanf(" %c %c %c", &ch1, &ch2, &ch3); // 注意空格
    // 在格式字符串中添加空格，可以跳过任何空白字符（包括空格和换行符）
    printf("You entered: %c, %c, %c\n", ch1, ch2, ch3);
}

// 测试邻接矩阵————创建图，dfs,bfs
void Test1(void)
{
    MGraph graph;
    MGraphCreate(&graph);
    MGraphDfs(graph);
    MGraphBfs(graph);
}

// 测试邻接表————创建图，dfs,bfs
void Test2(void)
{
    GraphAdjList graph;
    ALGraphCreate(&graph);
    ALGraphDfs(&graph);
}

/**
 * @brief 测试自己写的马踏联营
 *
 */
void Test3(void)
{
    clock_t start;
    clock_t finish;
    // clock 返回 ns, CLOCKS_PER_SEC = 1000 000
    start = clock();
    Mtly(0, 0);
    finish = clock();
    printf("%s-%d Use time %f s\n",
           __func__,
           __LINE__,
           (double)(finish - start) / CLOCKS_PER_SEC);
}

/**
 * @brief 测试AI给的马踏联营算法
 * 
 */
void Test4(void)
{
    clock_t start;
    clock_t finish;
    start = clock();
    int startX = 0, startY = 0;
    SolveKnightTour(startX, startY);
    finish = clock();
    printf("%s-%d Use time %f s\n",
           __func__,
           __LINE__,
           (double)(finish - start) / CLOCKS_PER_SEC);
}

/**
 * @brief 测试最小生成树
 *
 */
void Test5(void)
{
    MGraph graph;
    MGraphCreateForMiniSpanTree(&graph);
    printf("----------Prim--------\n");
    MiniSpanTreePrim(graph);
    printf("----------Kruskal--------\n");
    MiniSpanTreeKruskal(graph);
}

/**
 * @brief 测试最短路径算法_Dijkstra
 * 
 */
void Test6(void)
{
    MGraph graph;
    MGraphCreateForShortestPath(&graph);
    ShortestPath path;
    PathDistance dist;
    int startVex = 0; // 起点顶点下标
    ShortestPathDijkstra(graph, startVex, &path, &dist);
    printf("Shortest path from vertex %c:\n", graph.vexs[startVex]);
    for (int i = 0; i < graph.numVertexes; i++)
    {
        if (dist[i] < INFINITY)
        {
            printf("到顶点%d--%c 的最短路径长度为 %d, 前驱顶点为 %d--%c\n",
                   i, graph.vexs[i], dist[i], path[i], graph.vexs[path[i]]);
        }
        else
        {
            printf("到顶点 %c 无法到达\n", graph.vexs[i]);
        }
    }
    printf("完整路径: ");
    int endVex = 8; // 终点顶点下标
    while (path[endVex] != -1) // 输出路径
    {
        printf("%d->", endVex);
        if (path[endVex] == startVex)
        {
            printf("%d", startVex);
            // printf("\n起点顶点 %c ", graph.vexs[startVex]);
            putchar('\n');
            break;
        }
        endVex = path[endVex]; // 继续向前查找
    }
}

/**
 * @brief 测试最短路径算法_Floyd
 * 
 */
void Test7(void)
{
    MGraph graph;
    PathDistanceMatrix path;
    ShortestPathMatrix dist;
    int k;
    int start = 0;
    int end = VEXNUM - 1;
    MGraphCreateForShortestPath(&graph);
    ShortestPathFloyd(graph, &path, &dist);
    for (int i = 0; i < VEXNUM; i ++)
        printf("%d\t", path[i][VEXNUM - 1]);
    printf("\n");
    k = path[start][end];
    printf("Shortest path: %d", start);
    while (k != end)
    {
        printf("->%d", k);
        k = path[k][end];
    }
    printf("->%d\n", end);
}

/**
 * @brief 测试拓扑排序算法
 * 
 */
void Test8(void)
{
    GraphAdjList graph;
    ALGraphCreateForTopoSort(&graph);
    int ret = TopologicalSort(&graph);
    printf("%s_%d finish, ret = %d\n", __func__, __LINE__, ret);
}

static void RunFromEnterNum(int argc, char *argv[])
{
    int testNum = -1;
    for (int i = 0; i < argc; i++)
    {
        printf("The %d param is %s\n", i, argv[i]);
        if (i >= 1)
        {
            testNum = atoi(argv[i]);
            switch (testNum)
            {
            case 0:
                Test0();
                break;
            case 1:
                Test1();
                break;
            case 2:
                Test2();
                break;
            case 3:
                Test3();
                break;
            case 4:
                Test4();
                break;
            case 5:
                Test5();
                break;
            case 6:
                Test6();
                break;
            case 7:
                Test7();
                break;
            case 8:
                Test8();
                break;
            default:
                printf("Please enter a correct test number\n");
                break;
            }
        }
    }
} 

int main(int argc, char *argv[])
{
    RunFromEnterNum(argc, argv);
    return 0;
}
