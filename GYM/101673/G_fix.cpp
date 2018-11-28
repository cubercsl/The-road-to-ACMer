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

const int N = 1 << 7;
int dp[N][N][2];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(n);
    for (auto& t : a) scanf("%d", &t);
    vector<int> vec;
    vec.push_back(m);
    for (; vec.back();) vec.push_back(vec.back() * 2 / 3);
    dbg(vec);
    m = vec.size();
    memset(dp, 0xc0, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            // 00
            dp[i + 1][0][0] = max(dp[i + 1][0][0], dp[i][j][0]);
            // 01
            dp[i + 1][j + 1][1] = max(dp[i + 1][j + 1][1], dp[i][j][0] + min(vec[j], a[i]));
            // 11
            dp[i + 1][j + 1][1] = max(dp[i + 1][j + 1][1], dp[i][j][1] + min(vec[j], a[i]));
            // 10
            dp[i + 1][max(0, j - 1)][0] = max(dp[i + 1][max(0, j - 1)][0], dp[i][j][1]);
        }
    int ans = 0;
    for (int i = 0; i < m; i++) ans = max({ans, dp[n][i][0], dp[n][i][1]});
    printf("%d\n", ans);
    return 0;
}