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

void ShortestPathDijkstra(MGraph graph, int v0, ShortestPath *path, PathDistance *dist);
#endif