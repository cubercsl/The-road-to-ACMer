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
    scanf("%d", &T);
    while (T--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        vector<pair<int, int>> lv;
        for (int i = 0, a, p; i < n; i++)
        {
            scanf("%d%d", &a, &p);
            lv.emplace_back(a, p);
        }
        vector<pair<int, int>> item;
        for (int i = 0, c, d; i < k; i++)
        {
            scanf("%d%d", &c, &d);
            item.emplace_back(c, d);
        }
        long long ans = 0;
        for (auto& it : item)
        {
            long long x = it.second;
            x = x * it.first;
            ans += x;
        }
        ans = (ans + 9) / 10;
        for (auto& t : lv)
        {
            long long tmp = (t.first + 9) / 10;
            long long tot = 0;
            for (auto& it : item)
            {
                long long x = (it.second - 1LL * it.second * t.second / 100);
                x = x * it.first;
                tot += x;
            }
            tot = (tot + 9) / 10;
            ans = min(ans, max(tmp, tot));
        }
        printf("%lld\n", ans);
    }
    return 0;
}