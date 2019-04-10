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
    int n, h;
    scanf("%d%d", &n, &h);
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = n; i; i--)
    {
        vector<int> b(a.begin(), a.begin() + i);
        if (b.size() & 1) b.push_back(0);
        sort(b.begin(), b.end());
        long long ans = 0;
        for (int j = 0; j < i; j += 2)
            ans += max(b[j], b[j + 1]);
        if (ans <= h)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}