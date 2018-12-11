#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int G[N][N];

int pre[N], low[N];
int sccno[N];
int n, clk;
stack<int> s;
vector<vector<int>> scc;
void dfs(int u)
{
    pre[u] = low[u] = ++clk;
    s.push(u);
    for (int v = 0; v < n; v++)
        if (G[u][v])
        {
            if (!pre[v])
            {
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
            else if (!~sccno[v])
                low[u] = min(low[u], pre[v]);
        }
    if (low[u] == pre[u])
    {
        scc.emplace_back();
        for (;;)
        {
            int x = s.top();
            s.pop();
            scc.back().push_back(x);
            sccno[x] = scc.size() - 1;
            if (x == u) break;
        }
    }
}

int nG[N][N];
int deg[N];

int main()
{
    memset(sccno, -1, sizeof(sccno));
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &G[i][j]);

    for (int i = 0; i < n; i++)
        if (!pre[i]) dfs(i);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (sccno[i] != sccno[j] && G[i][j])
                nG[sccno[i]][sccno[j]] = 1;

    for (int i = 0; i < scc.size(); i++)
        for (int j = 0; j < scc.size(); j++)
            deg[j] += nG[i][j];

    queue<int> q;
    for (int i = 0; i < scc.size(); i++)
        if (!deg[i]) q.push(i);

    vector<int> ord;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        ord.push_back(u);
        for (int v = 0; v < scc.size(); v++)
            if (nG[u][v] && --deg[v] == 0) q.push(v);
    }

    printf("%d %d %d\n", 5, 20, static_cast<int>(4 * scc.size()));

    for (auto& u : ord)
    {
        char field[4][20][6] = {
            {
                ".#...",
                "#####",
                ".#...",
                "#####",
                ".#...",
                "#####",
                ".#...",
                "#####",
                ".#...",
                "#####",
                ".#...",
                "#####",
                ".#...",
                "#####",
                ".#...",
                "#####",
                ".#...",
                "#####",
                ".#...",
                "#####",
            },
            {
                "..##.",
                "#####",
                "..##.",
                "#####",
                "..##.",
                "#####",
                "..##.",
                "#####",
                "..##.",
                "#####",
                "..##.",
                "#####",
                "..##.",
                "#####",
                "..##.",
                "#####",
                "..##.",
                "#####",
                "..##.",
                "#####",
            },
            {
                "..#..",
                ".####",
                "..#..",
                ".####",
                "..#..",
                ".####",
                "..#..",
                ".####",
                "..#..",
                ".####",
                "..#..",
                ".####",
                "..#..",
                ".####",
                "..#..",
                ".####",
                "..#..",
                ".####",
                "..#..",
                ".####",
            },
            {
                "###.#",
                "#####",
                "###.#",
                "#####",
                "###.#",
                "#####",
                "###.#",
                "#####",
                "###.#",
                "#####",
                "###.#",
                "#####",
                "###.#",
                "#####",
                "###.#",
                "#####",
                "###.#",
                "#####",
                "###.#",
                "#####",
            }};
        for (auto& id : scc[u])
            field[2][id << 1][0] = id + '1';
        for (int v = 0; v < scc.size(); v++)
            if (nG[v][u]) field[0][v << 1][1] = '.';
        field[2][u << 1][2] = '.';
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 20; j++)
                puts(field[i][j]);
            puts("");
        }
    }
}