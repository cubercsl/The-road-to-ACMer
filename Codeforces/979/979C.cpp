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

const int N = 1 << 19;
vector<int> G[N];
int sz[N], fa[N];

void dfs(int u, int p)
{
    sz[u] = 1, fa[u] = p;
    for (auto& v : G[u])
    {
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 1; i < n; i++)
    {
        static int u, v;
        cin >> u >> v;
        G[u].pb(v), G[v].pb(u);
    }
    dfs(x, -1);
    int t = y;
    while (fa[t] != x) t = fa[t];
    ll ret = 1LL * n * (n - 1) - 1LL * sz[y] * (n - sz[t]);
    cout << ret << endl;
    return 0;
}
