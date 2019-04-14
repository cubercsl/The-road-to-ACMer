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

int dp[12][12][12][12];
const int INF = 0x3f3f3f3f;

int dfs(int pos, int a, int b, int c)
{
    if (pos == 10)
        return -INF * (a != 0 || b != 0 || c != 0);
    int& ans = dp[pos][a][b][c];
    if (~ans) return ans;
    ans = -INF;
    ans = max(ans, dfs(pos + 1, a, b, c));
    if (a > 0)
        ans = max(ans, dfs(pos + 1, a - 1, b, c) + 1);
    if (b > 0)
        ans = max(ans, dfs(pos + 1, a, b - 1, c) + 1);
    if (c > 0)
        ans = max(ans, dfs(pos + 1, a, b, c - 1) + 1);
    if (min({a, b, c}) > 0)
        ans = max(ans, dfs(pos + 1, a - 1, b - 1, c - 1) + 1);
    if (min(a, b) > 0)
        ans = max(ans, dfs(pos + 1, a - 1, b - 1, c));
    if (min(a, c) > 0)
        ans = max(ans, dfs(pos + 1, a - 1, b, c - 1));
    if (min(b, c) > 0)
        ans = max(ans, dfs(pos + 1, a, b - 1, c - 1));
    return ans;
}
int cnt[3][2];

int main()
{
    int T;
    scanf("%d", &T);
    memset(dp, -1, sizeof(dp));
    while (T--)
    {
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < 3; i++)
        {
            static char s[12];
            scanf("%s", s);
            for (int j = 0; s[j]; j++) cnt[i][s[j] - '0']++;
        }
        int ans = dfs(0, cnt[0][1], cnt[1][1], cnt[2][1]);
        for (int i = 0; i < 10; i++) printf("%d", i < ans);
        puts("");
    }
    return 0;
}