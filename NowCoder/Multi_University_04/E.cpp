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

const int maxn = 505;
vector<int> G[maxn];
int pre[maxn], lowlink[maxn], sccno[maxn], dfs_clock, scc_cnt;
stack<int> S;

void add_edge(int u, int v)
{
    G[u].pb(v);
}

void dfs(int u)
{
    pre[u] = lowlink[u] = ++dfs_clock;
    S.push(u);
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
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
    clr(sccno, 0);
    clr(pre, 0);
    for (int i = 1; i <= n; i++)
        if (!pre[i]) dfs(i);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        vector<int> v(m), in(n + 1);
        for (auto& t : v) scanf("%d", &t);
        for (int i = 1; i <= n; i++)
        {
            G[i].clear();
            int tot, v;
            scanf("%d", &tot);
            while (tot--)
            {
                scanf("%d", &v);
                add_edge(i, v);
            }
        }
        find_scc(n);
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < G[i].size(); j++)
            {
                int u = sccno[i];
                int v = sccno[G[i][j]];
                if (u != v)
                    in[v]++;
            }
        for (auto& t : v) t = sccno[t];
        sort(v.begin(), v.end());
        bool flag = 0;
        int ans = 0;
        for (int i = 1; i <= scc_cnt; i++)
        {
            if (in[i] == 0)
            {
                if (binary_search(v.begin(), v.end(), i))
                    ans++;
                else
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag)
            puts("-1");
        else
            printf("%d\n", ans);
    }
    return 0;
}