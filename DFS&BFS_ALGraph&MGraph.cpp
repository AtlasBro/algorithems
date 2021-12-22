#include<stdio.h>
#include<queue>
using namespace std;

#define MaxVertexNum 100
typedef char VertexType;
typedef int EdgeType;

typedef struct ArcNode{
    int adjvex;             //该边的终点编号
    int weight;             //该边的权值
    struct ArcNode *nextarc;   //指向下一条边的指针
}ArcNode;                   //边结点类型
typedef struct Vnode{
    ArcNode *firstArc;      //指向第一条边的指针
    VertexType data[MaxVertexNum];//顶点其他信息
}Vnode,AdjList[MaxVertexNum];//AdjList是邻接表类型
typedef struct{
    AdjList vertices;       //邻接表
    int n,e;                //顶点数和边数
}ALGraph;//邻接表结构体

#define MAXV 100
#define INF 10000000
typedef struct{
    int no;         //顶点编号
    char data[MAXV];//数据域
}VertexType1;       //顶点类型
typedef struct{
    int edges[MAXV][MAXV]; //邻接矩阵的边数组
    int n,e;               //顶点数、边数
    VertexType1 vexs[MAXV];//存放顶点信息
}MGraph;//邻接矩阵结构体

int visited[MaxVertexNum];//记录顶点是否被访问的数组

void DFS(ALGraph *G,int v){//邻接表DFS
    ArcNode *p;
    printf("%d",v);
    visited[v]=1;
    p=G->vertices[v].firstArc;
    while(p!=NULL){
        if(visited[p->adjvex]==0){
            DFS(G,p->adjvex);
        }
        p=p->nextarc;
    }
}

void DFS(MGraph g,int v){//邻接矩阵DFS
    int w;
    printf("%d",v);
    visited[v]=1;
    for(w=0;w<g.n;w++){
        if(g.edges[v][w]!=0&&g.edges[v][w]!=INF&&visited[w]==0){
            DFS(g,w);
        }
    }
}

void BFS(ALGraph *G,int v){//邻接表BFS
    ArcNode* p;
    queue<int> qu;
    visited[MAXV];
    int w,i;
    memset(visited,0,sizeof(visited));
    printf("%d",v);
    visited[v]=1;
    qu.push(v);
    while(!qu.empty()){
        w=qu.front();
        qu.pop();
        p=G->vertices[w].firstArc;
        while(p!=NULL){
            if(visited[p->adjvex]==0){
                printf("%d",p->adjvex);
                visited[p->adjvex]==1;
                qu.push(p->adjvex);
            }
            p=p->nextarc;
        }
    }
}

void BFS(MGraph g,int v){//邻接矩阵BFS
    queue<int> qu;
    visited[MAXV];
    int w,i;
    memset(visited,0,sizeof(visited));
    printf("%d",v);
    qu.push(v);
    while(!qu.empty()){
        w=qu.front();
        qu.pop();
        for(i=0;i<g.n;i++){
            if(g.edges[w][i]!=0&&g.edges[w][i]!=INF&&visited[i]==0){
                visited[i]==1;
                qu.push(i);
            }
        }
    }
}

bool ExistPath(ALGraph *G,int u,int v){//邻接表DFS判断是否存在简单路径
    int w;
    ArcNode *p;
    visited[u]=1;
    if(u==v)
        return true;
    p=G->vertices[u].firstArc;
    while(p!=NULL){
        w=p->adjvex;
        if(visited[w]==0){
            bool flag=ExistPath(G,w,v);
            if(flag) return true;
        }
        p=p->nextarc;
    }
    return false;
}

void Findapath(ALGraph *G,int u,int v,vector<int>apath,vector<int>&path){//DFS找简单路径
    int w;
    ArcNode *p;
    visited[u]=1;
    apath.push_back(u);     //将顶点u加入到apath路径中
    if(u==v){               //找到一条路径
        path=apath;         //将apath复制到path
        return;             //返回true
    }
    p=G->vertices[u].firstArc;
    while(p!=NULL){
        w=p->adjvex;        //相邻点的编号
        if(visited[w]==0){
            Findapath(G,w,v,apath,path);
        }
        p=p->nextarc;       //指向顶点u的下一个相邻点
    }
}
