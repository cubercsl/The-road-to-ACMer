#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 3005;
bool G[maxn][maxn];

bool flag;
bool vis[30];
int n;
void dfs(int s, int u, int cnt)
{
    if (flag) return;
    if (cnt == 3)
    {
        if (s == u)
            flag = true;
        return;
    }
    if (vis[u]) return;
    vis[u] = true;
    for (int i = 0; i < n; i++)
        if (G[u][i])
            dfs(s, i, cnt + 1);
    vis[u] = false;
}
void dfs1(int s, int u, int cnt)
{
    if (flag) return;
    if (cnt == 3)
    {
        if (s == u)
            flag = true;
        return;
    }

    if (vis[u]) return;
    vis[u] = true;
    for (int i = 0; i < n; i++)
        if (!G[u][i])
            dfs1(s, i, cnt + 1);
    vis[u] = false;
}

void solve()
{
    flag = 0;
    for (int i = 0; !flag && i < n; i++)
    {
        clr(vis, 0);
        dfs(i, i, 0);
    }
    for (int i = 0; !flag && i < n; i++)
    {
        clr(vis, 0);
        dfs1(i, i, 0);
    }
    if (flag)puts("Bad Team!");
    else puts("Great Team!");
}


int main()
{
#ifndef ONLINE_JUDGE
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--)
    {
        clr(G, 0);
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
                int fr;
                scanf("%d", &fr);
                G[i][j] = G[j][i] = fr;
            }
        if (n > 5) puts("Bad Team!");
        else if (n < 3) puts("Great Team!");
        else solve();
    }
    return 0;
}
