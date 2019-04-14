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

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        int ans = 0;
        cin >> n >> m;
        vector<multiset<int>> dp(n + 1);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1, x; j <= m; j++)
            {
                cin >> x;
                auto it = dp[i - 1].find(x);
                if (it != dp[i - 1].end())
                {
                    ans++;
                    dp[i - 1].erase(it);
                }
                dp[i].insert(x);
            }
        }
        cout << ans << endl;
    }
    return 0;
}