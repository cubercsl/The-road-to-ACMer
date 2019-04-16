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

typedef long long ll;
const int N = 40;
const int mod = 1e9 + 7;
ll G[N];
int a[N];
int dp[2][1 << 20];

int Pow(int a, int n = mod - 2)
{
    int t = 1;
    for (; n; n >>= 1, a = 1LL * a * a % mod)
        if (n & 1) t = 1LL * t * a % mod;
    return t;
}

void dfs(int l, int r, ll S, ll T, int cur, const int& d, const int& offset)
{
    if (l == r)
    {
        dp[d][S >> offset] = cur;
        return;
    }
    dfs(l + 1, r, S, T, cur, d, offset);
    if (!(T >> l & 1)) dfs(l + 1, r, S | (1LL << l), T | G[l], 1LL * cur * a[l] % mod, d, offset);
}

void fwt(int f[], int m)
{
    int n = __builtin_ctz(m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (j & (1 << i))
                (f[j] += f[j ^ (1 << i)]) %= mod;
}

int solve(int n)
{
    memset(dp, 0, sizeof(dp));
    dfs(0, n / 2, 0, 0, 1, 0, 0);
    dfs(n / 2, n, 0, 0, 1, 1, n / 2);
    fwt(dp[1], 1 << (n - n / 2));
    int ans = 0;
    for (int S = 0; S < (1 << (n / 2)); S++)
    {
        ll T = (1LL << n) - 1;
        for (int i = 0; i < n / 2; i++)
            if (S >> i & 1) T &= ~G[i];
        T >>= (n / 2);
        (ans += 1LL * dp[0][S] * dp[1][T] % mod) %= mod;
    }
    return ans;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), a[i] %= mod;
    for (int i = 0, u, v; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        --u, --v;
        G[u] |= 1LL << v;
        G[v] |= 1LL << u;
    }
    int Ex = solve(n);
    for (int i = 0; i < n; i++) a[i] = 1LL * a[i] * a[i] % mod;
    int Ex2 = solve(n);
    for (int i = 0; i < n; i++) a[i] = 1;
    int cnt = solve(n);
    int inv = Pow(cnt);
    dbg(Ex, Ex2, cnt);
    Ex = 1LL * Ex * inv % mod;
    Ex2 = 1LL * Ex2 * inv % mod;
    int ans = (Ex2 - 1LL * Ex * Ex % mod + mod) % mod;
    printf("%d\n", ans);
}