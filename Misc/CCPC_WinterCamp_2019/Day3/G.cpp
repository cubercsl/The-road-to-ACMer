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

const int N = 1 << 17;
int p[N];
int a[N];
int b[N];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", p + i);
    a[p[1]] = 1;
    int now = 1;
    for (int i = 2; i <= n; i++)
    {
        if (p[i] == p[i - 1] + 1)
            a[p[i]] = now;
        else
            a[p[i]] = ++now;
    }
    memcpy(b, a, sizeof(b));
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == a[i - 1])
            b[i] = ++now;
    }
    for (int i = 1; i <= n; i++) printf("%d%c", b[i], " \n"[i == n]);
    return 0;
}