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
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        vector<int> a(n);
        vector<int> cnt(m);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]), --a[i], cnt[a[i]]++;
        for (int i = 0; i < m; i++) cnt[i] = cnt[i] / k;
        int ans = 0;
        for (int i = 0; i < n / 2; i++)
            if (cnt[a[i]] > 0) --cnt[a[i]], ++ans;
        printf("%d\n", ans);
    }
    return 0;
}