#include <bits/stdc++.h>
using namespace std;

const int maxn = 155;
vector<int> G[maxn], query[maxn], id[maxn];
int par[maxn], ans[maxn];
bool vis[maxn];

void init()
{
    for (int i = 0; i < maxn; i++)
    {
        G[i].clear();
        par[i] = i;
        vis[i] = 0;
        query[i].clear();
        id[i].clear();
    }
}

int find(int x)
{
    return par[x] == x ? x : find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    par[y] = x;
}

void dfs(int u)
{
    vis[u] = 1;
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (vis[v])
            continue;
        dfs(v);
        unite(u, v);
    }
    for (int i = 0; i < query[u].size(); i++)
    {
        int v = query[u][i];
        if (!vis[v])
            continue;
        ans[id[u][i]] = find(v);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n, m, u, v;
        scanf("%d", &n);
        init();
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &u, &v);
            query[u].push_back(v);
            query[v].push_back(u);
            id[u].push_back(i);
            id[v].push_back(i);
        }
        dfs(0);
        printf("Case %d:\n", ++kase);
        for (int i = 0; i < m; i++)
        {
            if (i)
                putchar(' ');
            printf("%d", ans[i]);
        }
        puts("");
    }
    return 0;
}
