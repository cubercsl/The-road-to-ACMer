#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int par[maxn], dis[maxn];
int n, m;

void init()
{
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        dis[i] = 0;
    }
}

int search(int x)
{
    if (par[x] == x) return x;
    else
    {
        int root = search(par[x]);
        if (par[x] != root)
            dis[x] += dis[par[x]];
        return par[x] = root;
    }
}

bool same(int x, int y)
{
    return search(x) == search(y);
}

void unite(int x, int y)
{
    x = search(x);
    if (x == search(y))
        return;
    par[x] = y;
    dis[x]++;
}

int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        init();
        for (int i = 0; i < m; i++)
        {
            int t, x, y;
            scanf("%d%d%d", &t, &x, &y);
            if (t == 1)
            {
                unite(x, y);
            }
            else
            {
                if (same(x, y))
                {
                    printf("Yes %d\n", dis[y] - dis[x]);
                }
                else printf("No\n");
            }
        }
    }
}
