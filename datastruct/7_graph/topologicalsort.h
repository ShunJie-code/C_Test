#ifndef TOPOLOGICALSORT_H
#define TOPOLOGICALSORT_H

#include "graph.h"
/**
 * @brief 拓扑排序
 * 
 * @param g 
 * @return int 无回路则放回0，并输出拓扑排序的结果；有回路则返回-1
 */
int TopologicalSort(GraphAdjList g);

#endif