// Meteor Shower, POJ3669

/*Sample Input
4
0 0 2
2 1 2
1 1 2
0 3 5
*/

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int INF= 0x3f3f3f3f;
typedef pair <int,int> PII;
int tx[]= {1,0,-1,0};
int ty[]= {0,1,0,-1};

int vis[302][302];

void bfs()
{
    queue<PII> q;
    while(!q.empty())
        q.pop();
    if(vis[0][0]==INF)
    {
        printf("0\n");
        return;
    }
    vis[0][0]=0;
    q.push(make_pair(0,0));
    while(!q.empty())
    {
        PII tmp=q.front();
        q.pop();
        int x=tmp.first;
        int y=tmp.second;
        for(int i=0; i<4; i++)
        {
            int nx=x+tx[i],ny=y+ty[i];
            int time=vis[x][y]+1;
            if(nx<0||ny<0)
                continue;
            if(vis[nx][ny]==INF)
            {
                printf("%d\n",time);
                return;
            }
            if(time>=vis[nx][ny])
                continue;
            vis[nx][ny]=time;
            q.push(make_pair(nx,ny));
        }
    }
    printf("-1\n");
}

int main()
{
    int m;
    scanf("%d",&m);
    memset(vis,0x3f,sizeof(vis));
    while(m--)
    {
        int x,y,t;
        scanf("%d%d%d",&x,&y,&t);
        vis[x][y]=min(t,vis[x][y]);
        for(int i=0; i<4; i++)
        {
            int nx=x+tx[i],ny=y+ty[i];
            if(nx<0||ny<0)
                continue;
            vis[nx][ny]=min(t,vis[nx][ny]);
        }
    }
    bfs();
    return 0;
}
