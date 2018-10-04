#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 19;
int col[N], vis[N], fa[N];
vector<int> G[N];

vector<int> c;
bool dfs(int u, int d)
{
    vis[u] = true;
    col[u] = d;
    for (auto& v : G[u])
    {
        c.push_back(v);
        if (vis[v] && col[v] != (col[u] ^ 1)) return false;
        if (!vis[v] && !dfs(v, d ^ 1)) return false;
        c.pop_back();
    }
    return true;
}

bool judge(int n)
{
    for (int i = 1; i <= n; i++)
    {
        c.clear();
        if (!vis[i] && !dfs(i, 0)) return false;
    }
    return true;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if (judge(n))
    {
        puts("0");
        for (int i = 1; i <= n; i++) printf("%d%c", col[i], " \n"[i == n]);
    }
    else
    {
        reverse(c.begin(), c.end());
        vector<int> ans;
        ans.push_back(c[0]);
        for (int i = 1; i < c.size(); i++)
        {
            if(c[i] != c[0])
            {
                ans.push_back(c[i]);
            }
            else
                break;
        }
        int m = ans.size();
        printf("%d\n", m);
        for (int i = 0; i < m; i++) printf("%d%c", ans[i], " \n"[i == m - 1]);
    }
}