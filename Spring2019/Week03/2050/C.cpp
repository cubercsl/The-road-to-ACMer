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

ll n, m, k, a, b, c;
ll f(ll x)
{
    ll ans = 1e18;
    for (int i = 0; i <= (x + 1) / 2; i++)
        ans = min(ans, a * i + (x - i * 2 + 2) / 3 * b);
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld%lld%lld%lld%lld%lld", &n, &m, &k, &a, &b, &c);
        ll ans = 1e18;
        for (int i = 0; i < k + 1; i++)
        {
            ll t = c * (k - i) + f(n + i) + f(m + i);
            ans = min(ans, t);
        }
        printf("%lld\n", ans);
    }
    return 0;
}