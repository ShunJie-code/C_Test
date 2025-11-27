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
typedef unsigned short EdgeType;

typedef struct 
{
    int begin;  // 边的起点
    int end;    // 边的终点
    EdgeType weight; // 边的权值
}Edge;


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
    int adjvex;                 // 邻接点域，存储该顶点对应的下标
    EdgeType weight;
    struct EdgeNode *next;      // 链域，指向下一个邻接点
}EdgeNode;

#ifdef NO_DIR_GRAPH
typedef struct VertexNode
{
    VertexType data;
    EdgeNode *firstegde;
}VertexNode, AdjList[MAXVEX]; // 重定义了MAXVEX个结构体的数组类型
#else
typedef struct VertexNode
{
    int in;                  // 顶点入度
    int data;
    EdgeNode *firstegde;
}VertexNode, AdjList[MAXVEX]; // 重定义了MAXVEX个结构体的数组类型
#endif

typedef struct 
{
    AdjList adjList;
    int numVertexes, numEdges;  // 图中的顶点数和边数
}GraphAdjList, *PGraphAdjList;
// endregion 邻接表

/**
 * @brief 邻接矩阵，建立无向网、无向图
 * 
 * @param g 
 */
void MGraphCreate(MGraph *g);

/**
 * @brief 邻接矩阵，DFS遍历
 * 
 * @param g 
 */
void MGraphDfs(MGraph g);

/**
 * @brief 邻接矩阵，BFS遍历
 * 
 * @param g 
 */
void MGraphBfs(MGraph g);

/**
 * @brief 邻接表，建立无向网、无向图
 * 
 * @param g 
 */
void ALGraphCreate(GraphAdjList *g);

/**
 * @brief 邻接表，Dfs遍历
 * 
 * @param g 
 */
void ALGraphDfs(const GraphAdjList *g);

/**
 * @brief 邻接表，Bfs遍历
 * 
 * @param g 
 */
void ALGraphBfs(const GraphAdjList *g);

void MGraphCreateForMiniSpanTree(MGraph *g);

/**
 * @brief 为最短路径算法创建图-邻接矩阵
 * 
 * @param g 
 */
void MGraphCreateForShortestPath(MGraph *g);

/**
 * @brief 为拓扑排序创建图-邻接表
 * 
 */
void ALGraphCreateForTopoSort(GraphAdjList *g);

/**
 * @brief 为关键路径算法创建图-邻接表
 * 
 */
void ALGraphCreateForCriticalPath(GraphAdjList *g);

#endif
