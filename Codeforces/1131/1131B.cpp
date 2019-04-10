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

int solve(int px, int py, int x, int y)
{
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> vec;
    vec.emplace_back(0, 0);
    for (int i = 0, x, y; i < n; i++)
    {
        cin >> x >> y;
        vec.emplace_back(x, y);
    }
    int ans = 1;
    for (int i = 1; i < n + 1; i++)
    {
        int x = vec[i].first, y = vec[i].second;
        int px = vec[i - 1].first, py = vec[i - 1].second;
        if (px == py)
            ans += min(x, y) - px;
        else if (px < py)
        {
            if (x >= py)
                ans += min(x, y) - py + 1;
        }
        else
        {
            if (y >= px)
                ans += min(x, y) - px + 1;
        }
    }
    cout << ans << endl;
    return 0;
}