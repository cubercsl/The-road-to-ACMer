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
const int mod = 1e9 + 7;
const double eps = 1e-6;

struct BIT
{
    const static int N = 1 << 20;
    int a[N];
    BIT() { clr(a, 0); }
    void update(int x, int v)
    {
        for (int i = x; i < N; i+= i & -i) a[i] += v;
    }
    int query(int x)
    {
        int t = 0;
        for (int i = x; i; i -= i & -i) t += a[i];
        return t;
    }
} t;

vector<vector<int> > G;
vector<int> fa;
vector<int> in, out;
int dfn;
void dfs(int u, int p, int d)
{
    fa[u] = p, in[u] = ++dfn;
    t.update(in[u], d), t.update(in[u] + 1, -d);
    for (auto& v : G[u])
        if (v != p) dfs(v, u, d + 1);
    out[u] = dfn;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int n, k;
    cin >> n >> k;
    dfn = 0;
    G.resize(n + 1);
    fa.resize(n + 1);
    in.resize(n + 1);
    out.resize(n + 1);
    for (int i = 1, u, v; i < n; i++)
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(n, -1, 1);
    vector<bool> vis(n + 1);
    for (int i = n, cnt = 0; i; i--)
    {
        if (vis[i]) continue;
        int len = t.query(in[i]);
        if (cnt + len <= n - k)
        {
            for (int u = i; ~u && !vis[u]; u = fa[u])
            {
                vis[u] = true, cnt++;
                t.update(in[u], -1), t.update(out[u] + 1, 1);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i]) cout << i << " ";
    return 0;
}