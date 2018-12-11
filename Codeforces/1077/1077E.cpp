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
const int N = 1 << 17;

int main()
{
    int n;
    scanf("%d", &n);
    map<int, int> cnt;
    for (int i = 0, x; i < n; i++)
    {
        scanf("%d", &x);
        cnt[x]++;
    }
    vector<int> d;
    for (auto& t : cnt) d.push_back(t.second);
    sort(d.begin(), d.end());
    int m = d.size();
    int ret = 0;
    dbg(d);
    for (int i = 1; i <= n; i++)
    {
        int ans = 0, pos = 0;
        if (pos >= m) continue;
        for (int j = i; j <= n && pos < m; j <<= 1)
        {
            pos = lower_bound(d.begin() + pos, d.end(), j) - d.begin();
            if (pos >= m) break;
            ans += j;
            pos++;
            dbg(ans);
        }
        ret = max(ret, ans);
    }
    printf("%d\n", ret);
    return 0;
}