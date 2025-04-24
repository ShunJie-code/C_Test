/**
 * @file graph.h
 * @author your name (you@domain.com)
 * @brief 通过邻接矩阵、邻接表，表示无向图和有向图
 * @version 0.1
 * @date 2025-02-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef GRAPH_H
#define GRAPH_H

#define MAXVEX 100
#define INFINITY 65535

typedef char VertexType; // 顶点类型定义
typedef int EdgeType;

// region 邻接矩阵
typedef struct
{
    VertexType vexs[MAXVEX];        // 顶点表
    EdgeType arc[MAXVEX][MAXVEX];   // 边表，Adjacency Matrix
    int numVertexes, numEdges;
} MGraph;
// endrigion 邻接矩阵

// region 邻接表
typedef struct EdgeNode
{
    int adjvex;
    EdgeType weight;
    struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode
{
    VertexType data;
    EdgeNode *firstegde;
}VertexNode, AdjList[MAXVEX]; // 重定义了MAXVEX个结构体的数组类型

typedef struct 
{
    AdjList adjList;
    int numVertexes, numEdges;  // 图中的顶点数和边数
}GraphAdjList;
// endregion 邻接表

/**
 * @brief 邻接矩阵--建立无向网、无向图
 * 
 * @param g 
 */
void MGraphCreate(MGraph *g);

/**
 * @brief 邻接矩阵--DFS遍历
 * 
 * @param g 
 */
void MGraphDfs(MGraph g);

/**
 * @brief 邻接矩阵--BFS遍历
 * 
 * @param g 
 */
void MGraphBfs(MGraph g);

/**
 * @brief 邻接表————建立无向网、无向图
 * 
 * @param G 
 */
void ALGraphCreate(GraphAdjList *g);

void ALGraphDfs(const GraphAdjList *g);

#endif
