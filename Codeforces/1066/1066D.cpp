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
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    vector<int> a(n);
    for (auto& t : a) scanf("%d", &t);
    int l = 0, r = n, ans;
    while (l <= r)
    {
        int x = l + r >> 1;
        if ([&](int x) {
                int cnt = m - 1, now = 0;
                for (int i = x; i < n; i++)
                {
                    int& t = a[i];
                    if (now + t <= k)
                        now += t;
                    else
                        now = t, cnt--;
                }
                return cnt >= 0;
            }(x))
            ans = x, r = x - 1;
        else
            l = x + 1;
    }
    printf("%d\n", n - ans);
    return 0;
}