#include <bits/stdc++.h>
#define CLR(x) memset(x,0,sizeof(x))
using namespace std;

const int maxn=1002;
char maze[maxn][maxn];
int u[maxn][maxn];
int d[maxn][maxn];
int l[maxn][maxn];
int r[maxn][maxn];

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        CLR(u);
        CLR(d);
        CLR(l);
        CLR(r);
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%s",maze[i]);
        // 预处理四个方向
        for(int i=0;i<n;i++)
            for(int j=1;j<m;j++)
                l[i][j]=maze[i][j-1]=='x'?0:l[i][j-1]+1;
        for(int i=0;i<n;i++)
            for(int j=m-2;j>=0;j--)
                r[i][j]=maze[i][j+1]=='x'?0:r[i][j+1]+1;
        for(int j=0;j<m;j++)
            for(int i=1;i<n;i++)
                u[i][j]=maze[i-1][j]=='x'?0:u[i-1][j]+1;
        for(int j=0;j<m;j++)
            for(int i=n-2;i>=0;i--)
                d[i][j]=maze[i+1][j]=='x'?0:d[i+1][j]+1;
        // 搜索结果
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(maze[i][j]!='x')
                    ans=max(ans,u[i][j]+d[i][j]+l[i][j]+r[i][j]);
        printf("%d\n",ans);
    }
    return 0;
}
