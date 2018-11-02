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

const int N = 5005;
int a[N], b[N];
int dp[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i), b[i] = (a[i] >= m);
    for (int i = 1; i <= n; i++) b[i] += b[i - 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
        if (i == 0 || dp[i])
            for (int j = i + 1; j <= n; j++)
                if ((b[j] - b[i]) * 2 > j - i) dp[j] = max(dp[j], dp[i] + 1);
    printf("%d\n", dp[n]);
    return 0;
}