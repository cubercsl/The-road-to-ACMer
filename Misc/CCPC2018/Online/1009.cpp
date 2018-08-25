#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
vector<int> G[N];
int dp[N];
vector<tuple<int, int, int> > edges;
typedef long long ll;
const int mod = 1e9 + 7;
void dfs(int u, int fa)
{
    dp[u] = 1;
    for (auto& v : G[u])
    {
        if (v == fa) continue;
        dfs(v, u);
        dp[u] += dp[v];
    }
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        edges.clear();
        if (n == 1)
        {
            puts("0");
            continue;
        }
        for (int i = 1; i <= n; i++) G[i].clear(), dp[i] = 0;
        for (int i = 1, x, y, z; i < n; i++)
        {
            scanf("%d%d%d", &x, &y, &z);
            G[x].push_back(y);
            G[y].push_back(x);
            edges.emplace_back(x, y, z);
        }
        dfs(1, 0);
        ll ans = 0;
        for (auto& e : edges)
        {
            int u, v, w;
            tie(u, v, w) = e;
            ans = (ans + ((1LL * dp[v] * (n - dp[v]) % mod) * w % mod)) % mod;
        }
        ll f = 1;
        for (int i = 2; i < n; i++) f = f * i % mod;
        printf("%lld\n", ans * 2 % mod * f % mod);
    }
}