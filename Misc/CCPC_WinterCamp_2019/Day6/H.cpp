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
const int mod = 119 << 23 | 1;

int f[333][100001];
int s1[100001], s2[100001];
void init(int n)
{
    s1[0] = 1;
    int m = sqrt(n) + 1;
    for (int i = 1; i < m; i++)
    {
        for (int j = i; j <= n; j++)
        {
            s1[j] = ((ll)s1[j] + (ll)s1[j - i]) % mod;
        }
    }
    f[0][0] = 1;
    s2[0] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = m; j <= n; j++)
        {
            f[i][j] = ((ll)f[i][j - i] + (ll)f[i - 1][j - m]) % mod;
            s2[j] = ((ll)s2[j] + (ll)f[i][j]) % mod;
        }
    }
}

ll p(int n)
{
    ll ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans += 1LL * s1[i] * s2[n - i] % mod;
        ans %= mod;
    }
    return ans;
}

int main()
{
    init(100000);
    int n;
    // while(cin >> n) cout << p(n) << endl;
    while (cin >> n)
    {
        ll ans = (p(n) - p(n - 1)) % mod;
        ans = (ans - p(n - 2)) % mod;
        ans = (ans + p(n - 3)) % mod;
        ans = (ans + mod) % mod;
        cout << ans << '\n';
    }
}