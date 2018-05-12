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

const int maxn = 1 << 17;
int id[maxn], f[maxn];
vector<int> G[maxn];
int pre[maxn], lowlink[maxn], sccno[maxn], dfs_clock, scc_cnt;
stack<int> S;
inline void init(int n)
{
    for (int i = 0; i < n; i++) G[i].clear();
}
inline void add_edge(int u, int v) { G[u].pb(v); }
void dfs(int u)
{
    pre[u] = lowlink[u] = ++dfs_clock;
    S.push(u);
    for (auto& v : G[u])
    {
        if (!pre[v])
        {
            dfs(v);
            lowlink[u] = min(lowlink[u], lowlink[v]);
        }
        else if (!sccno[v])
            lowlink[u] = min(lowlink[u], pre[v]);
    }
    if (lowlink[u] == pre[u])
    {
        scc_cnt++;
        for (;;)
        {
            int x = S.top();
            S.pop();
            sccno[x] = scc_cnt;
            if (x == u) break;
        }
    }
}
void find_scc(int n)
{
    dfs_clock = 0, scc_cnt = 0;
    clr(sccno, 0), clr(pre, 0);
    for (int i = 1; i <= n; i++)
        if (!pre[i]) dfs(i);
}

ll ff[maxn];
int out[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    cin >> n;
    iota(id, id + maxn, 0);
    for (int i = 1; i <= n; i++) cin >> f[i];
    int q;
    cin >> q;
    while (q--)
    {
        static int op;
        cin >> op;
        if (op == 1)
        {
            static int x, l, r;
            cin >> x >> l >> r;
            for (int i = l; i <= r; i++) add_edge(id[x], id[i]);
        }
        else
        {
            static int x, v;
            cin >> x >> v;
            f[++n] = v;
            id[x] = n;
        }
    }
    find_scc(n);
    for (int i = 1; i <= n; i++) ff[sccno[i]] += f[i];
    for (int u = 1; u <= n; u++)
    {
        for (auto& v : G[u])
        {
            if (sccno[u] == sccno[v]) continue;
            out[sccno[u]]++;
        }
    }
    ll ans = 1e18;
    for (int i = 1; i <= scc_cnt; i++)
        if (out[i] == 0) ans = min(ans, ff[i]);
    cout << ans << endl;
    return 0;
}
