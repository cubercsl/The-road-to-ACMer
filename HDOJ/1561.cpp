// The more, The Better, HDU1561

/*Sample Input
3 2
0 1
0 2
0 3
7 4
2 2
0 1
0 4
2 1
7 1
7 6
2 2
0 0
*/

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

const int maxn = 205;
int val[maxn];
int dp[maxn][maxn];
bool vis[maxn];
vector <int> G[maxn];
int n,m;

void init(int n)
{
    for (int i = 0; i <= n; i++)
        G[i].clear();
    clr(dp, 0);
    clr(vis, 0);
}

void add_edge(int u, int v)
{
    G[u].pb(v);
}

void dfs(int u)
{
    vis[u] = true;
    dp[u][1] = val[u];
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (vis[v]) continue;
        dfs(v);
        for (int j = m + 1; j > 1; j--)
            for (int k = 1; k < j; k++)
                dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k]);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    while (cin >> n >> m, n + m)
    {
        int a, b;
        init(n);
        for (int i = 1; i <= n; i++)
        {
            cin >> a >> b;
            add_edge(a, i);
            val[i] = b;
        }
        dfs(0);
        cout << dp[0][m+1] << endl;
    }
    return 0;
}
