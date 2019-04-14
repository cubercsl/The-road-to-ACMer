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
ll dp[N][N];
ll a[N], b[N], c[N];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
        memset(dp, -1, sizeof(dp));
        dp[0][0] = m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (~dp[i][j])
                {
                    ll x = min(dp[i][j], b[i]);
                    if (x > a[i])
                        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], x - a[i] + c[i]);
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + c[i]);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= n; i++)
            if (dp[n][i] >= 0)
                ans = max(ans, i);
        printf("%d\n", ans);
    }
    return 0;
}