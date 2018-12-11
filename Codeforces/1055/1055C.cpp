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

int main()
{
    ll la, ra, ta;
    ll lb, rb, tb;
    cin >> la >> ra >> ta;
    cin >> lb >> rb >> tb;
    ll g = gcd(ta, tb);
    if (la > lb)
    {
        swap(la, lb);
        swap(ra, rb);
    }
    ll tmp = (lb - la) / g * g;
    lb -= tmp, rb -= tmp;
    ll ans = min(ra, rb) + 1 - max(la, lb);
    lb -= g, rb -= g;
    ans = max(ans, min(ra, rb) + 1 - max(la, lb));
    ans = max(0LL, ans);
    cout << ans << endl;
    return 0;
}