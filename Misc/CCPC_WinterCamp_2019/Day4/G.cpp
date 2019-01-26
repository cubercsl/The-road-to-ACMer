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
const int N = 1 << 10;
const int mod = 1e9 + 7;

ll dp[N][N];
ll inv2 = mod + 1 >> 1;
ll f(int n, int k)
{
    if (~dp[n][k]) return dp[n][k];
    if (n == 1) return 1;
    return dp[n][k] = (f(n - 1, k - 1) + f(n - 1, k + 1)) % mod * inv2 % mod * k % mod;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    n++;
    cout << f(n, 1) << endl;
    return 0;
}