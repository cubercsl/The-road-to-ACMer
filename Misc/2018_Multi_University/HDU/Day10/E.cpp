#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

const int maxn = 1 << 17;
vector<int> G[maxn], sp;
int dep[maxn], dfn[maxn];
PII dp[21][maxn << 1];
void init(int n)
{
    for (int i = 0; i < n; i++) G[i].clear();
    sp.clear();
}
void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    dfn[u] = sp.size();
    sp.push_back(u);
    for (auto& v : G[u])
    {
        if (v == fa) continue;
        dfs(v, u);
        sp.push_back(u);
    }
}
void initrmq()
{
    int n = sp.size();
    for (int i = 0; i < n; i++) dp[0][i] = {dfn[sp[i]], sp[i]};
    for (int i = 1; (1 << i) <= n; i++)
        for (int j = 0; j + (1 << i) - 1 < n; j++)
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);
}
int lca(int u, int v)
{
    int l = dfn[u], r = dfn[v];
    if (l > r) swap(l, r);
    int k = 31 - __builtin_clz(r - l + 1);
    return min(dp[k][l], dp[k][r - (1 << k) + 1]).second;
}

int fa[maxn], val[maxn];

vector<int> pos[maxn];
int ans[maxn];
int mx;
inline void solve(int g)
{
    int cnt = 0;
    vector<int> Node;
    for (int j = g; j <= mx; j += g)
        for (auto& v : pos[j]) Node.push_back(v);
    sort(Node.begin(), Node.end(), [&](int x, int y) {
        return dfn[x] < dfn[y];
    });
    for (int i = 1; i < Node.size(); i++)
    {
        int u = lca(Node[i - 1], Node[i]);
        ans[u] = max(ans[u], g);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &fa[i]);
        G[fa[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", val + i);
        pos[val[i]].push_back(i);
    }
    ::mx = *max_element(val + 1, val + n + 1);
    dfs(1, 0);
    initrmq();
    for (int i = mx; i; i--) solve(i);
    for (int i = 1; i <= n; i++) printf("%d\n", ans[i] ? ans[i] : -1);
}