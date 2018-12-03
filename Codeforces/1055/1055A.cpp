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

const int N = 1 << 10;
int a[N], b[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    if (a[1] == 0) return cout << "NO", 0;
    if (a[m] == 1) return cout << "YES", 0;
    if (b[m] == 1)
    {
        for (int i = m; i <= n; i++)
            if (a[i] == 1 && b[i] == 1) return cout << "YES", 0;
    }
    cout << "NO";
    return 0;
}