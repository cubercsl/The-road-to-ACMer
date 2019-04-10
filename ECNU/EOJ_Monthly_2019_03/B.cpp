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
    vector<long long> a(n);
    for (auto& t : a) scanf("%lld", &t);
    int l = 0, r = n - 1;
    int ans = 0;
    while (l < r)
    {
        if (a[l] == a[r])
        {
            l++, r--;
        }
        else if (a[l] < a[r])
        {
            a[l + 1] += a[l];
            l++, ans++;
        }
        else if (a[l] > a[r])
        {
            a[r - 1] += a[r];
            r--, ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}