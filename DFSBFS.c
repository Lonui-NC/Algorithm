#include <stdio.h>
//author:Nic github 
//DFS BFS
int visited[N];
void DFS(Graph G,int v)
{
    visited[v]=1;
    //访问操作
    Visit(v);
    for(w=FirstAdjVex(G,v,w);w>=0;w=NextAdjVex(G,v,w))
    {
        if(!visited[w])
            DFS(G,w);//对v的未访问节点进行深度优先搜索
    }
}

//DFS 不停搜索直至从该点进入为不可能深入的地方中
void DFSSearch(Graph G)
{
    for(v=0;v<G.vexnum;++v)
    {
        visited[v]=0;
    }
    for(v=0;v<G.vexnum;++v)
    {
        if(!visited[v])
            DFS(G,v);
    }
}

void BFSSearch(Graph G)
{
    for(v=0;v<G.vexnum;v++)
    {
        visited[v]=0;
    }
    InitQueue(Q);
    for(v=0;v<G.vexnum;v++)
    {
        if(!visited[v])
        {
            visited[v]=1;
            Visit(v);
            EnQueue(Q,v);
            while(!QueueEmpty(Q))
            {
                DeQueue(Q,u);
                for(w=FirstAdjVex(G,u);w>=0;w=NextAdjVex(G,u,w))
                {
                    if(!visited[w])
                    {
                        visited[w]=1;
                        Visit(w);
                        EnQueue(Q,w);
                    }
                }
            }
        }
    }
}