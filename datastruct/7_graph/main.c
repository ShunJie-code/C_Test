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
 */
#include <stdio.h>
#include <time.h>
#include "graph.h"
#include "mtly.h"

void Test0(void)
{
    char ch1, ch2, ch3;
    printf("Enter three characters: ");
    scanf(" %c %c %c", &ch1, &ch2, &ch3);  // 注意空格
    // 在格式字符串中添加空格，可以跳过任何空白字符（包括空格和换行符）
    printf("You entered: %c, %c, %c\n", ch1, ch2, ch3);
}

// 测试邻接矩阵————创建图，dfs,bfs
void Test1(void)
{
    MGraph graph;
    MGraphCreate(&graph);
    MGraphDfs(graph);
}

// 测试邻接表————创建图，dfs,bfs
void Test2(void)
{
    GraphAdjList graph;
    ALGraphCreate(&graph);
    ALGraphDfs(&graph);
}

void Test3(void)
{
    clock_t start;
    clock_t finish;
    start = clock();
    Mtly();
    finish = clock();
    printf("%s-%d Use time %f s\n", 
        __func__,
        __LINE__,
        (double)(finish - start)/CLOCKS_PER_SEC);
}

int Test4() {
    clock_t start;
    clock_t finish;
    start = clock();
    int startX = 0, startY = 0;
    solveKnightTour(startX, startY);
    finish = clock();
    printf("%s-%d Use time %f s\n", 
            __func__,
            __LINE__,
            (double)(finish - start)/CLOCKS_PER_SEC);
    return 0;
}    

int main(void)
{
    Test4();
    Test3();

    return 0;
}