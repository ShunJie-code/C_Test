/**
 * @file mcst.h
 * @author your name (you@domain.com)
 * @brief 最小生成树 minimum cost spanning tree
 * 为使生成树上的边权之和最小
 * @version 0.1
 * @date 2025-05-25
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "graph.h"
/**
 * @brief 最小生成树 Prim算法，点少边多
 * Prim算法是从一个顶点开始，逐步扩展生成树，每次选择与生成树相连的最小边。
 * 
 * @param graph 图的邻接矩阵表示
 */
void MiniSpanTreePrim(MGraph graph);

/**
 * @brief 最小生成树 Kruskal算法，边少点多
 * kruskal算法是将图中的所有边按权值从小到大排序，然后逐一选择边，加入生成树中，前提是不形成回路。
 * @param graph 图的边集表示
 */
void MiniSpanTreeKruskal(MGraph graph); 