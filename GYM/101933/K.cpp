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

const int N = 1 << 12;
vector<int> G[N];

const int mod = 1e9 + 7;
typedef long long ll;

ll Pow(ll a, ll n)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1) (t *= a) %= mod;
    return t;
}

ll C[N][N];
ll dp[N];

ll dfs(int u, int k)
{
    dp[u] = u == 0 ? k : k - 1;
    for (auto& v : G[u])
        dp[u] = dp[u] * dfs(v, k) % mod;
    return dp[u];
}

int main()
{
    C[0][0] = 1;
    for (int i = 1; i < N; i++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1, x; i < n; i++)
    {
        scanf("%d", &x);
        G[x].push_back(i);
    }
    ll mu = 1;
    ll ans = 0;
    for (int i = k; i > 0; i--)
    {
        dfs(0, i);
        ans = ans + mu * C[k][i] * dp[0] % mod;
        ans = (ans + mod) % mod;
        mu *= -1;
    }
    printf("%lld\n", ans);
    return 0;
}