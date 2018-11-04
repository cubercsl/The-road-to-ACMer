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

const int N = 51;
long long f[N];

int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n, k, q;
        scanf("%d%d%d", &n, &k, &q);
        f[0] = 1;
        for (int i = 1; i < N; i++) f[i] = (f[i - 1] * i) % q;
        if (n <= k)
        {
            printf("Case #%d: %lld\n", ++kase, f[n]);
            continue;
        }
        long long ans = f[k] * ((n - k) * (n - k) - 2 * (n - k) + 2) % q;
        ans = (ans + f[k] * (n - k) * k) % q;
        ans = (ans + f[k] * (n - k - 1)) % q;
        printf("Case #%d: %lld\n", ++kase, ans);
    }
    return 0;
}