#include "shortestpath.h"

void ShortestPathDijkstra(MGraph graph, int v0, ShortestPath *path, PathDistance *dist)
{
    int visited[VEXNUM] = {0}; // 访问标志数组 1 表示已访问，0表示未访问
    int i, j, k;
    int minDist;

    // 初始化路径和距离
    for (i = 0; i < VEXNUM; i++) {
        (*dist)[i] = graph.arc[v0][i];
        (*path)[i] = (graph.arc[v0][i] < INFINITY) ? v0 : -1; // 如果有边则设置起点为前驱
    }
    visited[v0] = 1; // 标记起点已访问

    for (i = 1; i < VEXNUM; i++) {
        minDist = INFINITY; // 初始化最小距离为无穷大
        k = -1;

        // 找到未访问的最小距离顶点
        for (j = 0; j < VEXNUM; j++) {
            if (!visited[j] && (*dist)[j] < minDist) {
                minDist = (*dist)[j];
                k = j;
            }
        }

        if (k == -1) break; // 如果没有可访问的顶点，退出循环

        visited[k] = 1; // 标记该顶点已访问

        // 更新其他顶点的距离和路径
        for (j = 0; j < VEXNUM; j++) {
            if (!visited[j] && graph.arc[k][j] < INFINITY) {
                if ((*dist)[k] + graph.arc[k][j] < (*dist)[j]) {
                    (*dist)[j] = (*dist)[k] + graph.arc[k][j];
                    (*path)[j] = k; // 更新前驱节点
                }
            }
        }
    }
}
