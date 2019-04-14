#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define dbg(args...)                             \
    do                                           \
    {                                            \
        cout << "\033[32;1m" << #args << " -> "; \
        err(args);                               \
    } while (0)
#else
#define dbg(...)
#endif
void err()
{
    cout << "\033[39;0m" << endl;
}
template <template <typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args)
{
    for (auto x : a) cout << x << ' ';
    err(args...);
}
template <typename T, typename... Args>
void err(T a, Args... args)
{
    cout << a << ' ';
    err(args...);
}
/****************************************************************************************************/

const int maxn = 1 << 17;
vector<pair<int, int>> G[maxn];
int pre[maxn], lowlink[maxn], sccno[maxn], dfs_clock, scc_cnt;
stack<int> S;
inline void init(int n)
{
    for (int i = 0; i < n; i++) G[i].clear();
}
inline void add_edge(int u, int v, int c)
{
    G[u].emplace_back(v, c);
    G[v].emplace_back(u, c);
}
void dfs(int u, int fa)
{
    pre[u] = lowlink[u] = ++dfs_clock;
    S.push(u);
    for (auto& [v, c] : G[u])
    {
        if (v == fa) continue;
        if (!pre[v])
        {
            dfs(v, u);
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
    memset(sccno, 0, sizeof(int) * n), memset(pre, 0, sizeof(int) * n);
    for (int i = 0; i < n; i++)
        if (!pre[i]) dfs(i, -1);
}

char buf[maxn];

namespace Tree
{
vector<pair<int, int>> G[maxn];

bool vis[maxn];
int H[maxn], A[maxn];
long long dp[maxn];
void init(int n)
{
    for (int i = 0; i < n; i++) G[i].clear();
    memset(H, 0, sizeof(int) * n);
    memset(A, 0, sizeof(int) * n);
    memset(dp, 0, sizeof(long long) * n);
    memset(vis, 0, sizeof(bool) * n);
}
void add_edge(int u, int v, int c)
{
    G[u].emplace_back(v, c);
    G[v].emplace_back(u, c);
}
void debug(int n)
{
    for (int u = 0; u < n; u++)
        for (auto& [v, e] : G[u]) dbg(u, v, e);
}
void dfs(int u, int fa)
{
    vis[u] = true;
    for (auto& [v, c] : G[u])
    {
        if (vis[v]) continue;
        dfs(v, u);
        dp[u] += dp[v];
        dp[u] += 1LL * (H[v] + A[v]) * c;
        H[u] += H[v];
        A[u] += A[v];
    }
    int x = min(H[u], A[u]);
    H[u] -= x;
    A[u] -= x;
}
void fuck(int n)
{
    for (int i = 0; i < n; i++) dbg(dp[i], H[i], A[i]);
}
} // namespace Tree

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        scanf("%s", buf);
        init(n);
        for (int i = 0, u, v, c; i < m; i++)
        {
            scanf("%d%d%d", &u, &v, &c);
            --u, --v;
            add_edge(u, v, c);
        }
        find_scc(n);
        Tree::init(scc_cnt);
        for (int u = 0; u < n; u++)
        {
            for (auto& [v, c] : G[u])
            {
                if (sccno[u] == sccno[v]) continue;
                int x = sccno[u] - 1, y = sccno[v] - 1;
                Tree::add_edge(x, y, c);
            }
        }
        for (int i = 0; i < n; i++)
        {
            Tree::H[sccno[i] - 1] += buf[i] == 'H';
            Tree::A[sccno[i] - 1] += buf[i] == 'A';
        }
        Tree::debug(scc_cnt);
        Tree::dfs(0, -1);
        Tree::fuck(scc_cnt);
        printf("%lld\n", Tree::dp[0]);
    }

    return 0;
}