#include<stdio.h>
#define VertexType char
#define MaxVertexNum 100
typedef struct ArcNode{ //边表
    int adjvex;
    struct ArcNode *nextArc;
}ArcNode;
typedef struct VNode{   //顶点表结点
    VertexType data;
    ArcNode *firstArc;
}VNode,adjList[MaxVertexNum];
typedef struct{
    adjList vertices;
    int vexnum,arcnum;
}ALGraph;

int d=-1;
int visited[MaxVertexNum];

void FindPath(ALGraph *G,int u,int v,int path[],int d){
    int w,i;
    ArcNode *p;
    d++;
    path[d]=u;
    visited[u]=1;
    if(u==v){
        printf("%d",path[i]);
    }
    p=G->vertices[u].firstArc;
    while(p!=NULL){
        w=p->adjvex;
        if(visited[w]==0){
            FindPath(G,w,v,path,d);
        }
        p=p->nextArc;
    }
    visited[u]=0;
}
