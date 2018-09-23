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

typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1 << 17;
ll dp[N][2][2];
// u为根 实际结果i，现在结果j
struct Node
{
    int ch[2];
    int f;
};

Node G[N];

void dfs(int u)
{
    if (u == 0) return;
    int& lson = G[u].ch[0];
    int& rson = G[u].ch[1];
    int& f = G[u].f;
    dfs(lson), dfs(rson);
    if (f == -1)
    {
        for (int lx = 0; lx < 2; lx++)
            for (int rx = 0; rx < 2; rx++)
                for (int ly = 0; ly < 2; ly++)
                    for (int ry = 0; ry < 2; ry++)
                        (dp[u][!(lx & rx)][!(ly & ry)] += dp[lson][lx][ly] * dp[rson][rx][ry] % mod) %= mod;
    }
    else
    {
        for (int lx = 0; lx < 2; lx++)
            for (int rx = 0; rx < 2; rx++)
                for (int ly = 0; ly < 2; ly++)
                    for (int ry = 0; ry < 2; ry++)
                        (dp[u][!(lx & rx)][f] += dp[lson][lx][ly] * dp[rson][rx][ry] % mod) %= mod;
    }
    dbg(u, dp[u][0][0], dp[u][0][1], dp[u][1][0], dp[u][1][1]);
}

int main()
{
    dp[0][0][1] = dp[0][1][0] = 0;
    dp[0][0][0] = dp[0][1][1] = 1;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &G[i].ch[0], &G[i].ch[1], &G[i].f);
    dfs(1);
    printf("%lld\n", (dp[1][0][1] + dp[1][1][0]) % mod);
}