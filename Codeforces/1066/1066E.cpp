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

const int N = 1 << 18;
const int mod = 119 << 23 | 1;
char s[N], t[N];

int a[N];

int main()
{
    memset(s, '0', sizeof(s));
    memset(t, '0', sizeof(t));
    int n, m;
    scanf("%d%d", &n, &m);
    if (n == m)
        scanf("%s%s", s, t);
    else if (n > m)
        scanf("%s%s", s, t + n - m), m = n;
    else if (n < m)
        scanf("%s%s", s + m - n, t), n = m;
    // puts(s);
    // puts(t);
    for (int i = 0; i < m; i++) a[i] = t[i] - '0';
    for (int i = 1; i < m; i++) a[i] += a[i - 1];
    long long ans = 0;
    for (int i = n - 1, b = 1; ~i; i--, b = 2LL * b % mod)
        if (s[i] == '1') ans = (ans + 1LL * b * a[i]) % mod;
    printf("%lld\n", ans);
    return 0;
}