#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 10;
int deg[N];
vector<pair<int, int>> G[N];

int dp[N];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v, w; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        --u, --v;
        G[u].emplace_back(v, w);
        deg[v]++;
    }
    queue<int> q;
    memset(dp, 0xc0, sizeof(dp));
    for (int i = 0; i < n; i++)
        if (deg[i] == 0)
        {
            dp[i] = 0;
            q.push(i);
        }
    while(!q.empty())
    {
        int u= q.front();
        q.pop();
        for (auto&[v, w] : G[u])
        {
            dp[v] = max(dp[u] + w, dp[v]);
            if (--deg[v] == 0) q.push(v);
        }
    }
    printf("%d\n", *max_element(dp, dp + n));
}
