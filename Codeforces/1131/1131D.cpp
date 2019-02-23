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

const int N = 1 << 10;
char s[N][N];

vector<int> G[N << 1];
int deg[N << 1];

void add_edge(int x, int y)
{
    G[x].push_back(y);
    deg[y]++;
}

int fa[N << 1];
int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void unite(int x, int y)
{
    x = find(x), y = find(y);
    fa[x] = y;
}
int dp[N << 1];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    for (int i = 0; i < n + m; i++) fa[i] = i;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == '=')
                unite(i, n + j);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == '<')
                add_edge(find(i), find(n + j));
            else if (s[i][j] == '>')
                add_edge(find(n + j), find(i));
    for (int i = 0; i < n + m; i++) add_edge(n + m, find(i));
    queue<int> q;
    q.push(n + m);
    memset(dp, -1, sizeof(dp));
    dp[n + m] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto& v : G[u])
        {
            dp[v] = max(dp[v], dp[u] + 1);
            if (--deg[v] == 0) q.push(v);
        }
    }

    for (int i = 0; i < n + m; i++)
    {
        if (find(i) != i) continue;
        if (dp[i] < 0) return puts("No"), 0;
        if (deg[i] != 0) return puts("No"), 0;
    }
    puts("Yes");
    for (int i = 0; i < n; i++) printf("%d ", dp[find(i)]);
    puts("");
    for (int i = n; i < n + m; i++) printf("%d ", dp[find(i)]);

    return 0;
}