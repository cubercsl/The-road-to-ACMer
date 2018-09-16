#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
bool red[N];
typedef long long ll;

vector<pair<int, int>> G[N];
vector<int> sp;
ll dep[N], dis[N];
int dfn[N];

pair<int, int> dp[21][N << 1];
void init(int n)
{
    for (int i = 0; i <= n; i++) G[i].clear();
    sp.clear();
}
void dfs(int u, int fa)
{
    dfn[u] = sp.size();
    sp.push_back(u);
    for (auto& e : G[u])
    {
        int& v = e.first;
        int& w = e.second;
        if (v == fa) continue;
        dep[v] = dep[u] + w;
        if (!red[v])
            dis[v] = dis[u] + w;
        else
            dis[v] = 0;
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

bool check(const vector<int>& t, ll k, int v)
{
    for (auto& u : t)
        if (dep[u] - dep[v] > k) return false;
    return true;
}

void build(vector<int>& vec)
{
    sort(vec.begin(), vec.end(), [&](int x, int y) { return dfn[x] < dfn[y]; });
    ll l = 0, r = 0;
    for (auto& u : vec) r = max(r, dis[u]);
    vector<int> t;

    ll ans = 0;

    while (l <= r)    
    {
        ll mid = l + r >> 1;
        t.clear();

        for (auto& u : vec)
            if (dis[u] > mid) t.push_back(u);
        if (t.size() <= 1)
        {
            r = mid - 1, ans = mid;
            continue;
        }
        int vlca = t[0];
        for (int i = 1; i < t.size(); i++) vlca = lca(vlca, t[i]);
        if (check(t, mid, vlca))
            r = mid - 1, ans = mid;
        else
            l = mid + 1;
    }
    printf("%lld\n", ans);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m, q;
        scanf("%d%d%d", &n, &m, &q);
        for (int i = 1; i <= n; i++) red[i] = false;
        init(n);
        for (int i = 0, r; i < m; i++)
        {
            scanf("%d", &r);
            red[r] = true;
        }
        for (int i = 1, u, v, w; i < n; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            G[u].emplace_back(v, w);
            G[v].emplace_back(u, w);
        }
        dfs(1, 0);
        initrmq();
        while (q--)
        {
            static int k;
            scanf("%d", &k);
            vector<int> vec(k);
            for (int i = 0; i < k; i++) scanf("%d", &vec[i]);
            build(vec);
        }
    }
}