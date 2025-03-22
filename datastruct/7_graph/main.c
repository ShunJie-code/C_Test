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
 */
#include <stdio.h>
#include "graph.h"

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

int main(void)
{
    Test2();
    return 0;
}