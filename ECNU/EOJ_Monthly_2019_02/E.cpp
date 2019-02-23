#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 20;
const int INF = 0x3f3f3f3f;
int a[N], p[N], dp[N], d[N], dd[N];
vector<int> G[N];
bool vis[N];
bool check(int m, int n)
{
    for (int i = 0; i < n; i++)
        p[i] = (a[i] >= m) ? 1 : -1, dp[i] = -INF, d[i] = dd[i];
    queue<int> q;
    dp[0] = p[0];
    q.push(0);
    for (int i = 1; i < n; i++)
        if (!d[i])
            dp[i] = -INF, q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto& v : G[u])
        {
            dp[v] = max(dp[v], dp[u] + p[v]);
            if (--d[v] == 0) q.push(v);
        }
    }
    // printf("%d: ", m);
    // for (int i = 0; i < n; i++) printf("%d ", dp[i]);
    // puts("");
    return dp[n - 1] >= 0;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0, u, v; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        --u, --v;
        dd[v]++;
        G[u].push_back(v);
    }
    queue<int> q;
    q.push(0);
    vis[0] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto& v : G[u])
            if (!vis[v]) vis[v] = true, q.push(v);
    }
    for (int i = 0; i < n; i++)
        if (!vis[i])
            for (auto& v : G[i]) --dd[v];
    int l = 0, r = INF, ans = -1;
    while (l <= r)
    {
        int m = l + r >> 1;
        if (check(m, n))
            l = m + 1, ans = m;
        else
            r = m - 1;
    }
    printf("%d\n", ans);
}