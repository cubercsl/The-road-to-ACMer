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

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        long long n, k;
        scanf("%lld%lld", &n, &k);
        long long t = sqrt(n);
        long long x, y;
        if (t * (t + 1) <= n)
            x = t * 2;
        else
            x = t * 2 - 1;
        k = x - k + 1;
        if (k <= t)
            y = k;
        else
            y = n / (x - k + 1);
        printf("%lld %lld\n", x, y);
    }
    return 0;
}