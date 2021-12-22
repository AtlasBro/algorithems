#include <iostream>
#include <cstring>
using namespace std;

int w,h,c,a;
int Sx,Sy,Ex,Ey;
int cnt,flag,tag;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
char maze[50][50];
int vis[50][50];
int que[2500][20];

void dfs(int x,int y,int cnt){
    if(maze[x][y]=='E'){
        printf("%d",cnt);
        tag=0;
        return;
    }
    if(tag) 
    for(int i=a+c,j=0;j<4,j++;i-=c){
        if(i<0) i=3;
        if(i>3) i=0;
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(tx>h||tx<1||ty<1||ty>w) continue;
        if(tag&&!vis[tx][ty]&&maze[tx][ty]!='#'){
            a=i;
            dfs(tx,ty,cnt+1);
        }
    }
}

void bfs() {
    int fir = 0, sec = 0;
    que[sec][0] = Sx;
    que[sec++][1] = Sy;
    int step = 1;
    while(fir < sec && !vis[Ex][Ey]) {
        int tmp = sec;
        step++;
        while(fir < tmp && !vis[Ex][Ey]) {
            int x = que[fir][0];
            int y = que[fir++][1];
            for(int i = 0; i < 4; i++) {
                int tx = x + dx[i];
                int ty = y + dy[i];
                if (tx > h || tx < 1 || ty > w || ty < 1) continue;
                if(!vis[tx][ty] && maze[tx][ty] != '#') {
                    que[sec][0] = tx;
                    que[sec++][1] = ty;
                    vis[tx][ty] = 1;
                }
            }
        }
    }
    printf("%d\n", step);
}

int main()
{
   int t, i, j;
    scanf("%d", &t);
    while (t--) {
        memset(maze, 0, sizeof(maze));
        memset(vis, 0, sizeof(vis));
        scanf("%d %d", &w, &h);
        getchar();
        for (i = 1; i <= h; i++) {
            for (j = 1; j <= w; j++) {
                scanf("%c", &maze[i][j]);
                if (maze[i][j] == 'S') Sx = i, Sy = j;
                else if (maze[i][j] == 'E') Ex = i, Ey = j;
            }
            getchar();
        }
        for (i = 0; i < 4; i++)
            if (maze[Sx+dx[i]][Sy+dy[i]] == '.') break;
        vis[Sx][Sy] = 1;
        a = i; tag = 1; c = -1;
        dfs(Sx, Sy, 1);
        a = i; c = 1; tag = 1;
        dfs(Sx, Sy, 1);
        bfs();
    }
    return 0;
}
