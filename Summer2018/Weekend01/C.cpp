#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
vector<int> G[N];
int used[N];
int linker[N];
int T;

bool dfs(int u)
{
    for (int i = 0; i < G[u].size(); i++)
    {
        int& v = G[u][i];
        if (used[v] != T)
        {
            used[v] = T;
            if (linker[v] == -1 || dfs(linker[v]))
            {
                linker[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    memset(linker, -1, sizeof(linker));
    scanf("%d", &n);
    for (int i = 0, u, v; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        G[u].push_back(i);
        G[v].push_back(i);
    }
    for (int i = 1; i < N; i++)
    {
        ++T;
        if (!dfs(i)) return printf("%d\n", i - 1), 0;
    }
    assert(false);
    return 0;
}