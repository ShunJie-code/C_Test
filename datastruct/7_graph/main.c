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
 * 63 最小生成树-Prim
 * 64 最小生成树-kruskal
 * 65 最短路径-dijkstra
 * 66 最短路径-floyd
 * 67 拓扑排序
 * 68 关键路径
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graph.h"
#include "mtly.h"
#include "mcst.h"

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
    MGraphCreateFromBook(&graph);
    printf("----------Prim--------\n");
    MiniSpanTreePrim(graph);
    printf("----------Kruskal--------\n");
    MiniSpanTreeKruskal(graph);
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
    // Test5();
    return 0;
}
