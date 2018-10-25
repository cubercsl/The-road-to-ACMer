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
    int n, r;
    cin >> n >> r;
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i]) continue;
        for (int j = min(i + r - 1, n - 1); j >= max(0, i - r + 1); j--)
        {
            if (a[j])
            {
                ans++;
                for (int k = max(0, j - r + 1); k <= min(j + r - 1, n - 1); k++)
                    b[k] = 1;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (!b[i])
        {
            cout << -1 << endl;
            return 0;
        }
    cout << ans << endl;
    return 0;
}