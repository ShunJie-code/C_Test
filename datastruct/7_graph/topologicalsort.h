/**
 * @file topologicalsort.h
 * @author your name (you@domain.com)
 * @brief topological sort header file
 * @version 0.1
 * @date 2025-11-08
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef TOPOLOGICALSORT_H
#define TOPOLOGICALSORT_H

#include "graph.h"
/**
 * @brief 拓扑排序，对有向图构造拓扑排序，顶点全部输出代表是AOV网
 *        满足若从顶点Vi到Vj有一条路径，则在顶点序列中，顶点Vi必在顶点Vj之前
 * @param g 
 * @return int 无回路则放回0，并输出拓扑排序的结果；有回路则返回-1
 */
int TopologicalSort(PGraphAdjList g);

#endif