#define MaxVertexNum 100
typedef char VertexType;
typedef int EdgeType;
typedef struct{
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexnum,arcnum;
}MGraph;//邻接矩阵结构体

typedef struct ArcNode{
    int adjvex;
    struct ArcNode *next;
    //InfoType info;//网的边权值
}ArcNode;
typedef struct Vnode{
    ArcNode *firstArc;//指向第一条弧的指针
    VertexType data;
}Vnode,AdjList[MaxVertexNum];
typedef struct{
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;//邻接表结构体