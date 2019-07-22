#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int d[4];
vector<pair<int, int>> G[4];
void addedge(int u, int v, int w)
{
    G[u].emplace_back(v, w);
    G[v].emplace_back(u, w);
}

struct HeapNode
{
    ll d;
    int u;
    HeapNode(ll d, int u) : d(d), u(u) {}
    bool operator<(const HeapNode& rhs) const
    {
        return d > rhs.d;
    }
};
ll dp[4][60005];
bool vis[4][60005];

void solve(ll k, int mod)
{
    memset(dp, 0x3f, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    dp[1][0] = 0;
    priority_queue<HeapNode> q;
    q.push(HeapNode(0, 1));
    while (!q.empty())
    {
        auto x = q.top();
        q.pop();
        int u = x.u;
        ll d = x.d;
        if (vis[u][d % mod]) continue;
        vis[u][d % mod] = true;
        for (auto& e : G[u])
        {
            int v = e.first, w = e.second;
            if (dp[v][(d + w) % mod] > dp[u][d % mod] + w)
            {
                dp[v][(d + w) % mod] = dp[u][d % mod] + w;
                q.push(HeapNode(dp[v][(d + w) % mod], v));
            }
        }
    }
    ll ans = LONG_LONG_MAX;
    for (int i = 0; i < mod; i++)
    {
        if (dp[1][i] >= k)
            ans = min(ans, dp[1][i]);
        else
        {
            ll tmp = (k - dp[1][i] + mod - 1) / mod * mod + dp[1][i];
            ans = min(ans, tmp);
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll k;
        scanf("%lld", &k);
        for (int i = 0; i < 4; i++) G[i].clear();
        for (int i = 0; i < 4; i++) scanf("%d", &d[i]), addedge(i, (i + 1) & 3, d[i]);
        solve(k, min(d[0], d[1]) * 2);
    }
}