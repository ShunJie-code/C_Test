/**
 * @file shortestpath.h
 * @author your name (you@domain.com)
 * @brief 最短路径
 * @version 0.1
 * @date 2025-07-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H
#include "graph.h"
#define VEXNUM 9
typedef int ShortestPath[VEXNUM];
typedef int PathDistance[VEXNUM];

typedef int ShortestPathMatrix[VEXNUM][VEXNUM];
typedef int PathDistanceMatrix[VEXNUM][VEXNUM];

/**
 * @brief 求一个顶点到所有顶点的最短路径
 * 
 * @param graph 
 * @param v0 
 * @param path 
 * @param dist 
 */
void ShortestPathDijkstra(MGraph graph, int v0, ShortestPath *path, PathDistance *dist);
/**
 * @brief 求所有顶点到所有顶点的最短路径
 * 
 * @param graph 
 * @param path 
 * @param dist 
 */
void ShortestPathFloyd(MGraph graph, PathDistanceMatrix *path, ShortestPathMatrix *dist);
#endif