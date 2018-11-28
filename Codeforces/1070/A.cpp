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

int dp[500][5005];
int p[500][5005];
int px[500][5005];
int py[500][5005];

int main()
{
    int d, n;
    memset(dp, -1, sizeof(dp));
    cin >> d >> n;
    dp[0][0] = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty())
    {
        auto t = q.front();
        dbg(t.first, t.second);
        q.pop();
        for (int i = 0; i < 10; i++)
        {
            int x = (t.first * 10 + i) % d;
            int y = t.second + i;
            if (y > n) continue;
            if (~dp[x][y]) continue;
            dp[x][y] = dp[t.first][t.second] + 1;
            p[x][y] = i;
            px[x][y] = t.first, py[x][y] = t.second;
            q.push({x, y});
        }
    }
    if (~dp[0][n])
    {
        int x = 0, y = n;
        string ans;
        do
        {
            int t = p[x][y];
            ans.push_back('0' + t);
            int xx = px[x][y];
            int yy = py[x][y];
            x = xx, y = yy;
        } while (x + y);
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    else
        cout << -1 << endl;
    return 0;
}