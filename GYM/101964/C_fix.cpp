#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define dbg(args...)                             \
    do                                           \
    {                                            \
        cout << "\033[32;1m" << #args << " -> "; \
        err(args);                               \
    } while (0)
#else
#define dbg(...)
#endif
void err()
{
    cout << "\033[39;0m" << endl;
}
template <template <typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args)
{
    for (auto x : a) cout << x << ' ';
    err(args...);
}
template <typename T, typename... Args>
void err(T a, Args... args)
{
    cout << a << ' ';
    err(args...);
}
/****************************************************************************************************/

const int N = 1 << 8;
int c[N];
vector<int> G[N];

inline void add_edge(int u, int v) { G[u].push_back(v), G[v].push_back(u); }

int d[N][N];

void bfs(int s, int d[])
{
    queue<int> q;
    d[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto& v : G[u])
        {
            if (~d[v]) continue;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
}

int main()
{
    int n, m;
    memset(d, -1, sizeof(d));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    for (int i = 1, u, v; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        add_edge(u, n + i);
        add_edge(n + i, v);
    }
    for (int i = 1; i < n + n; i++) bfs(i, d[i]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dbg(i, j, d[i][j]);
    for (int ans = 0;; ans++)
    {
        for (int i = 1; i < n + n; i++)
        {
            int cnt = 0;
            for (int j = 1; j <= n; j++)
                if (c[j] && d[i][j] <= ans) cnt++;
            if (cnt >= m) return printf("%d\n", ans), 0;
        }
    }
    return 0;
}