#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
map<pii, int> maps;
const int maxn = 1e5 + 5;
vector<int> G[maxn];
int a[maxn];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        maps[make_pair(u, v)] = 1;
        maps[make_pair(v, u)] = 1;
    }
    for(int i=1;i<=n;i++) a[i] = i;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(maps.find({i,j}) == maps.end()){
                puts("YES");
                int t = 1;
                a[i] = n;
                a[j] = n-1;
                for(int k=1;k<=n;k++)
                    if(k != i && k != j)
                        a[k] = t++;
                for(int k=1;k<=n;k++) printf("%d ",a[k]);
                a[j] = n;
                puts("");
                for(int k=1;k<=n;k++) printf("%d ",a[k]);
                puts("");
                return 0;
            }
        }
    }
    puts("NO");
}