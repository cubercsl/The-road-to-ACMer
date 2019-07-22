#include <bits/stdc++.h>
using namespace std;

const int P = 43;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> G(n);
    vector<int> d(n);
    vector<pair<int, int>> edges;
    for (int i = 0, u, v; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        --u, --v;
        G[u].push_back(v);
        edges.emplace_back(u, v);
        ++d[v];
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (!d[i]) q.push(i);
    vector<int> order(n);
    int sz = 0;
    while (!q.empty())
    {
        int u = q.front();
        order[u] = sz++;
        q.pop();
        for (auto& v : G[u])
            if (!--d[v])
                q.push(v);
    }
    int u, v;
    for (auto& e : edges)
    {
        tie(u, v) = e;
        u = order[u], v = order[v];
        int cnt = 0;
        while (u ^ v)
        {
            cnt++;
            u /= P, v /= P;
        }
        printf("%c\n", "RGB"[cnt - 1]);
    }
}