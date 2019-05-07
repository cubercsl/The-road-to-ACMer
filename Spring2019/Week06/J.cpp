#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 20;
int fa[N], id[N];
vector<int> G[N];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void unite(int x, int y)
{
    x = find(x), y = find(y);
    if (x > y) swap(x, y);
    fa[y] = x;
}

bool vis[N];

void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    iota(fa, fa + n, 0);
    static int ans[N];
    for (int i = 0; i < n; i++) G[i].clear(), vis[i] = false;
    for (int i = 0, u, v; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
        unite(u, v);
    }
    int tot = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; i++)
        if (find(i) == i) q.push(i), vis[i] = true, tot++;
    int sz = 0;
    while (!q.empty())
    {
        int u = q.top();
        ans[sz++] = u + 1;
        q.pop();
        for (auto& v : G[u])
        {
            if (vis[v]) continue;
            vis[v] = true;
            q.push(v);
        }
    }
    printf("%d\n", tot);
    for (int i = 0; i < sz; i++) printf("%d%c", ans[i], " \n"[i == sz - 1]);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) solve();
}
