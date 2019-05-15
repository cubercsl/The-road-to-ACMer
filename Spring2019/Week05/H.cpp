#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
vector<pair<int, int>> G[N];
int deg[N];
long long dis[N][2];
bool vis[N][2];

int main()
{
    int n, m, s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 0, u, v, w; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        G[v].emplace_back(u, w);
        deg[u]++;
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    for (int i = 0; i < n; i++) dis[i][0] = 0, dis[i][1] = 1e18;
    dis[t][0] = dis[t][1] = 0;
    q.emplace(0, t << 1);
    q.emplace(0, t << 1 | 1);
    while (!q.empty())
    {
        auto x = q.top();
        q.pop();
        int u = x.second >> 1;
        int d = x.second & 1;
        if (vis[u][d]) continue;
        vis[u][d] = true;
        fprintf(stderr, "%d %d\n", u, d);
        if (u == s && d == 0) return printf("%lld\n", dis[s][0]), 0;
        if (d == 0)
        {
            for (auto& [v, w] : G[u])
            {
                if (dis[v][1] > dis[u][0] + w)
                {
                    dis[v][1] = dis[u][0] + w;
                    q.emplace(dis[v][1], v << 1 | 1);
                }
            }
        }
        else
        {
            for (auto& [v, w] : G[u])
            {
                dis[v][0] = max(dis[v][0], dis[u][1] + w);
                if (--deg[v] == 0) q.emplace(dis[v][0], v << 1);
            }
        }
    }
    puts("infinity");
}