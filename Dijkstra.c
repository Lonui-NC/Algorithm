#include <stdio.h>
//author:Nic github 
//最短路径优先
typedef struct  node
{
    /* data */
    int matrix[N][M];//邻接矩阵
    int n;
    int e;

}MGraph;

void DijkstraPath(MGraph g,int *dist,int *path,int v0)
{
    int i,j,k;
    //一连串指针，表示对应有无完成访问
    bool *visited=(bool *)malloc(sizeof(bool)*g.n);
    for(i=0;i<g;n++)
    {
        //如果对应该点到另一点的距离有值
        if(g.matrix[v0][i]>0 && i!=v0)
        {
            dist[i]=g.matrix[v0][i];
            path[i]=v0;
        }
        else
        {
            dist[i]=INT_MAX;//表明为最大值，不可到达，便于筛选
            path[i]=-1;
        }
        //初始化起始值
        visited[i]=false;
        path[v0]=v0;
        dist[v0]=0;
    }
    visited[v0]=true;
    for (i = 1; i < g.n; ++i)
    {
        /* code */
        int min=INT_MAX;
        int u;
        //这一个循环是判断对应直接到V0点的最短距离
        for(j=0;j<g.n;j++)
        {
            //判断该节点有无访问过，且判断该节点到对应邻接矩阵的值是否最小
            if(visited[j]=false && dist[j]<min)
            {
                min=dist[j];
                u=j;
            }
        }
        visited[u]=true;
        //对应的点为到第j个点的值进行筛选
        for(k=0;k<g.n;k++)
        {
            //这一个是判断经过其他点相连
            if(visited[k]==false && g.matrix[u][k]>0 && min+g.matrix[u][k]<dist[k])
            {
                dist[k]=min+g.matrix[u][k];
                path[k]=u;
            }
        }
    }
}