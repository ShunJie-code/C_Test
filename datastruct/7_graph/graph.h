#ifndef GRAPH_H
#define GRAPH_H

#define MAXVEX 100
#define INFINITY 65535

typedef char VertexType; // 顶点类型定义
typedef int EdgeType;

/**
 * @brief 方法：邻接矩阵、邻接表
 * 目的：表示无向图和有向图
 */
typedef struct
{
    VertexType vexs[MAXVEX]; // 顶点表
    EdgeType arc[MAXVEX][MAXVEX]; // Adjacency Matrix
    int numVertexes, numEdges;
} MGraph;

void CreateMGraph(MGraph *g);


#endif
