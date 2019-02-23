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
int vis[N];
vector<int> G[N];
void dfs(int u)
{
    vis[u] = true;
    for (auto& v : G[u])
    {
        if (!vis[v])
            dfs(v);
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, x; i < m; i++)
    {
        scanf("%d", &x);
        vector<int> vec(x);
        for (int i = 0; i < x; i++) scanf("%d", &vec[i]);
        for (int i = x - 2; ~i; i--) G[vec[i + 1] - 1].push_back(vec[i] - 1);
    }
    int ans = n;
    for (int i = 0; i < n; i++)
    {
        memset(vis, 0, sizeof(vis));
        dfs(i);
        int tmp = accumulate(vis, vis + n, 0);
        ans = min(ans, tmp);
    }
    printf("%d\n", ans);
    return 0;
}