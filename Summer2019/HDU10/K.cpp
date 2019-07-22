#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 20;
typedef long long ll;
typedef pair<ll, ll> P;
vector<P> G[N];
ll dis[N], dis2[N];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) G[i].clear();
        for (int i = 0, u, v, w; i < m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            --u, --v;
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
        priority_queue<P, vector<P>, greater<P>> q;
        for (int i = 0; i < n; i++) dis[i] = 1e18;
        for (int i = 0; i < n; i++) dis2[i] = 1e18;
        dis[0] = 0;
        q.push({0, 0});
        while (!q.empty())
        {
            auto x = q.top();
            q.pop();
            ll u = x.second, d = x.first;
            if (dis2[u] < d) continue;
            for (auto& e : G[u])
            {
                int v = e.first;
                ll d2 = d + e.second;
                if (dis[v] > d2)
                {
                    swap(dis[v], d2);
                    q.push({dis[v], v});
                }
                if (dis2[v] > d2 && dis[v] <= d2)
                {
                    dis2[v] = d2;
                    q.push({dis2[v], v});
                }
            }
        }
        printf("%lld\n", dis2[n - 1]);
    }
}