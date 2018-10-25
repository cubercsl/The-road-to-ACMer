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
    int n;
    scanf("%d", &n);
    ll ans = 0;
    int x, mm =1e9;
    for (int i = 0, x; i < n; i++)
    {
        scanf("%d", &x);
        ans += x;
        mm = min(mm, x);
    }
    ans += 1LL * mm * (n - 2);
    printf("%lld\n", ans);
    return 0;
}