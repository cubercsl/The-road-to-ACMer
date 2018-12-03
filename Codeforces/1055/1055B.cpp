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

const int N = 1 << 17;
long long a[N];

int main()
{
    int n, m, l;
    scanf("%d%d%d", &n, &m, &l);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] > l && a[i - 1] <= l) ans++;

    for (int i = 0, op, t, d; i < m; i++)
    {
        scanf("%d", &op);
        if (op == 0)
        {
            printf("%d\n", ans);
            continue;
        }
        scanf("%d%d", &t, &d);
        if (a[t] <= l && a[t] + d > l)
        {
            if (a[t - 1] > l && a[t + 1] > l)
                ans--;
            else if (a[t - 1] <= l && a[t + 1] <= l)
                ans++;
        }
        a[t] += d;
    }
    return 0;
}