#include <iostream>
#include <cstring>
using namespace std;

const int N = 35;
int vis[N][N];
int p,q,flag;
char b[500];
int dx[8]={-2,-1,-2,-1,2,1,2,1};    //水平方向移动
int dy[8]={1,2,-1,-2,1,2,-1,-2};    //垂直方向移动

void dfs(int x,int y,int cnt){
    if(cnt==p*q){   //当完全走完整个棋盘时
        cout<<"A1";
        for(int i=2;i<2*cnt;i++){
            cout<<b[i]; //输出行走路径
        }
        cout<<endl<<endl;
        flag=1;
        return;
    }
    for(int i=0;i<8&&!flag;i++){
        int tx=x+dx[i],ty=y+dy[i];
        if(tx<1||tx>p||ty<1||ty>q) continue;    //超出范围则执行下一次循环
        if(!vis[tx][ty]){
            vis[tx][ty]=1;
            b[2*cnt]='A'+ty-1;
            b[2*cnt+1]='1'+tx-1;
            dfs(tx,ty,cnt+1);
            vis[tx][ty]=0;
        }
    }
}

int main()
{
    int t,ca=0;
    cin>>t;
    while(t--){
        cin>>p>>q;
        cout<<"Scenario #"<< ++ca <<':'<<endl;
        memset(vis,0,sizeof(vis));
        flag=0;
        vis[1][1]=1;
        dfs(1,1,1);
        if(!flag) cout<<"impossible"<<endl<<endl;
    }
    return 0;
}
