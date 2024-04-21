#include<stdio.h>
typedef char VertexType;  //顶点类型定义
typedef int EdgeType;   
#define MAXVEX 100
#define INFINITY 65535
typedef struct
{
    VertexType vexs[MAXVEX];//顶点表
    EdgeType arc[MAXVEX][MAXVEX];
    int numVertexes,numEdges;
}MGraph;

//建立无向网图的邻接矩阵表示
void CreateMgraph(MGraph *G){
    int i,j,k,w;
    printf("输入顶点数和边数：\n");
    scanf("%d,%d,&G->numsVertexes,&G->numEdges");
    for (i=0;i<G->numVertexes;i++)
        scanf(&G->vexs[i]);
    for(i=0;i<G->numVertexes;i++)
        for(j=0;j<G->numVertexes;j++)
            G->arc[i][i]=INFINITY;
    for(k=0;k<G->numEdges;k++){
        printf("输入边的下标i，j和权w:\n");
        scanf("%d,%d,%d",&i,&j,&w);
        G->arc[i][j]=w;
        G->arc[j][i]=G->arc[i][j];
    }

}