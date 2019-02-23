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

const int N = 1 << 17;
vector<int> G[N];

int dp[N], a[N], d[N];

void dfs(int u, int fa)
{
    dp[u] = a[u];
    for (auto& v : G[u])
    {
        if (v == fa) continue;
        d[v] = d[u] + 1;
        dfs(v, u);
        dp[u] += dp[v];
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1, u, v; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        if (a[i]) dp[i]--;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i] + d[i]);
    printf("%d\n", ans);
    return 0;
}