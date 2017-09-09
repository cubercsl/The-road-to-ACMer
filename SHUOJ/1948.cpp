#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;

const int maxn = 1e5 + 5;
vector<PII> G[maxn];
int val[maxn];

inline void init(int n)
{
    for (int i = 1; i <= n; i++)
        G[i].clear();
    clr(val, 0);
}

inline void add_edge(int u, int v, int w)
{
    G[u].pb(mp(v, w));
}

void dfs(int u, int p, int cur)
{
    val[u] = cur;
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i].X;
        int w = G[u][i].Y;
        if (v == p) continue;
        dfs(v, u, cur ^ w);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n, m, u, v, w;
        scanf("%d%d", &n, &m);
        init(n);
        for (int i = 1; i < n; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            add_edge(u, v, w);
            add_edge(v, u, w);
        }
        dfs(1, 0, 0);
        printf("Case %d:\n", ++kase);
        while (m--)
        {
            scanf("%d%d", &u, &v);
            printf("%d\n", val[u] ^ val[v]);
        }
    }
    return 0;
}
