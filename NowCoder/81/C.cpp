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
vector<int> G[maxn];
int pre[maxn], lowlink[maxn], sccno[maxn], dfs_clock, scc_cnt;
stack<int> S;
int ans[maxn];

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
            ans[scc_cnt] = min(ans[scc_cnt], x);
            if (x == u) break;
        }
    }
}
void find_scc(int n)
{
    dfs_clock = 0, scc_cnt = 0;
    clr(sccno, 0), clr(pre, 0);
    for (int i = 0; i < n; i++)
        if (!pre[i]) dfs(i);
}

int deg[maxn];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    clr(ans, 0x3f);
    int n, m;
    scanf("%d%d", &n, &m);
    while (m--)
    {
        static int u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        add_edge(u, v);
    }
    find_scc(n);
    for (int u = 0; u < n; u++)
    {
        for (auto& v : G[u])
            if (sccno[u] != sccno[v])
                deg[v]++;
    }
    vector<int> v;
    int cnt = 0;
    for (int i = 1; i <= scc_cnt; i++)
        if (deg[i] == 0) v.pb(ans[i] + 1), cnt++;
    sort(v.begin(), v.end());
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++)
        printf("%d%c", v[i], " \n"[i == cnt - 1]);

    return 0;
}