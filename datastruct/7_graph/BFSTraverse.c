//邻接矩阵的广度遍历算法
#include "Gragh_def.h"
void BFSTraverse(MGraph G){
    int i,j;
    Queue Q;
    for(i=0;i<G.numVertexes;i++)
        visited[i]=FALSE;
    InitQueue(&Q);          //初始化一辅助用的队列
    for(i=0;i<G.numVertexes;i++)
    {
        if(!visited[i])
        {
            visited[i]=TRUE;
            printf("%c",G.vexs[i]);
            EnQueue(&Q,i);
            while(!QueueEmpty(Q))//队列非空,!!!连通图靠这个队列即可遍历所有
            {
                DeQueue(&Q,&i);//关键是理解队列的剔除与插入
                for(j=0;j<G.numVertexes;j++){
                    if(G.arc[i][j]==1&&!visited[j])
                    {
                        visited[j]=TRUE;
                        printf("%c",G.vexs[j]);
                        EnQueue(&Q,j);
                    }
                }
            }
        }
    }
}