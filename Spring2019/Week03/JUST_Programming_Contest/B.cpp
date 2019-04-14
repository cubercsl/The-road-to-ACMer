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
int a[N];
int dp[N], ans[N];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m, q;
        scanf("%d%d%d", &n, &m, &q);
        memset(a, 0, sizeof(a));
        for (int i = 0, l, r; i < n; i++)
        {
            scanf("%d%d", &l, &r);
            for (int j = l; j <= r; j++) a[j] = 1;
        }
        for (int i = 1, j = 0; i <= m; i++)
        {
            ans[i] = 0;
            if (a[i])
                dp[i] = j = 0;
            else
                dp[i] = ++j;
            ans[dp[i]] = i;
        }
        ans[m + 1] = 0;
        for (int i = m; i; i--) ans[i] = max(ans[i + 1], ans[i]);
        while (q--)
        {
            static int k;
            scanf("%d", &k);
            if (ans[k])
                printf("%d %d\n", ans[k] - k + 1, ans[k]);
            else
                puts("-1 -1");
        }
    }
    return 0;
}