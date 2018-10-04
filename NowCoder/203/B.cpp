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
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
vector<int> G[maxn];
ll dp[3][maxn];
ll Pow(ll a, ll n)
{
    ll t = 1;
    for (; n; n >>= 1, a = (a * a % mod))
        if (n & 1) t = (t * a % mod);
    return t;
}
ll inv(ll a)
{
    return Pow(a, mod - 2);
}
void dfs1(int now, int fa)
{
    dp[0][now] = 1;
    for (auto& v : G[now])
    {
        if (v == fa) continue;
        dfs1(v, now);
        dp[0][now] = (dp[0][now] * (dp[0][v] + 1)) % mod;
    }
}
void dfs2(int now, int fa)
{
    vector<ll> vec1, vec2;
    vec1.push_back(1), vec2.push_back(1);
    for (auto& v : G[now])
    {
        if (v == fa)
            vec1.push_back(1), vec2.push_back(1);
        else
            vec1.push_back(dp[0][v] + 1), vec2.push_back(dp[0][v] + 1);
    }
    vec1.push_back(1), vec2.push_back(1);
    for (int i = 1; i <= G[now].size(); i++)
        vec1[i] = (vec1[i] * vec1[i - 1]) % mod;
    for (int i = G[now].size(); i >= 1; i--)
        vec2[i] = (vec2[i] * vec2[i + 1]) % mod;
    int x = 0;
    for (auto& v : G[now])
    {
        ++x;
        if (v == fa) continue;
        dp[1][v] = (vec1[x - 1] * vec2[x + 1] % mod * dp[1][now] + 1) % mod;
        dbg(now, v, dp[1][v]);
        dfs2(v, now);
    }
}
int main()
{
    int n;
    scanf("%d", &n);

    int u, v;
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1, 0);
    dp[1][1] = 1;
    dfs2(1, 0);
    for (int i = 1; i <= n; i++)
        // dbg(i, dp[0][i], dp[1][i]);
        printf("%lld\n", (dp[1][i] * dp[0][i]) % mod);
    return 0;
}