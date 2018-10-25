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
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> vec;
    vector<int> lv;
    for (int i = 0, x, y; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        vec.emplace_back(x, y);
        lv.push_back(max(x, y));
    }
    sort(lv.begin(), lv.end());
    lv.erase(unique(lv.begin(), lv.end()), lv.end());
    dbg(lv);
    int m = lv.size();
    vector<pair<int, int>> l(m + 1), r(m + 1);
    for (auto& t : vec)
    {
        int id = lower_bound(lv.begin(), lv.end(), max(t.first, t.second)) - lv.begin() + 1;
        if (l[id] == make_pair(0, 0) || l[id].first - l[id].second > t.first - t.second) l[id] = t;
        if (r[id] == make_pair(0, 0) || r[id].first - r[id].second < t.first - t.second) r[id] = t;
    };
    long long dp[2][2];
    long long w1, w2;
    auto dis = [](const pair<int, int>& a, const pair<int, int>& b) {
        return static_cast<long long>(abs(a.first - b.first))
               + static_cast<long long>(abs(a.second - b.second));
    };
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i <= m; i++)
    {
        w1 = dp[i & 1 ^ 1][0] + dis(l[i - 1], r[i]);
        w2 = dp[i & 1 ^ 1][1] + dis(r[i - 1], r[i]);
        dp[i & 1][0] = min(w1, w2) + dis(r[i], l[i]);
        w1 = dp[i & 1 ^ 1][0] + dis(l[i - 1], l[i]);
        w2 = dp[i & 1 ^ 1][1] + dis(r[i - 1], l[i]);
        dp[i & 1][1] = min(w1, w2) + dis(l[i], r[i]);
    }
    printf("%lld\n", min(dp[m & 1][0], dp[m & 1][1]));
    return 0;
}