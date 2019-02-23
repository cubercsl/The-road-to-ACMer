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

int a[100];

bool check(int n)
{
    for (int i = 1; i <= n - 1 >> 1; i++)
    {
        if (a[i * 2] < max(a[2 * i - 1], a[2 * i + 1]))
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) a[i] = i;
    do
    {
        if (check(n)) ans++;
    } while (next_permutation(a + 1, a + n + 1));
    cout << ans << endl;
    return 0;
}