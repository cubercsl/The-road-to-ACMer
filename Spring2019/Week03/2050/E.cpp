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

const int N = 10005;
char s[N];

int dp[N][13][13];

int dfs(int pos, int x, int y)
{
    if (s[pos] == '\0') return 0;
    if (~dp[pos][x][y]) return dp[pos][x][y];
    int ans = 0;
    if (s[pos] == 'A' || s[pos] == '?')
    {
        if (x == 10 && y == 10)
            ans = max(ans, dfs(pos + 1, x, y - 1));
        else if (x == 10)
            ans = max(ans, 1 + dfs(pos + 1, 0, 0));
        else
            ans = max(ans, dfs(pos + 1, x + 1, y));
    }
    if (s[pos] == 'B' || s[pos] == '?')
    {
        if (x == 10 && y == 10)
            ans = max(ans, dfs(pos + 1, x - 1, y));
        else if (y == 10)
            ans = max(ans, 1 + dfs(pos + 1, 0, 0));
        else
            ans = max(ans, dfs(pos + 1, x, y + 1));
    }
    return dp[pos][x][y] = ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s);
        memset(dp, -1, sizeof(dp));
        printf("%d\n", dfs(0, 0, 0));
    }
    return 0;
}