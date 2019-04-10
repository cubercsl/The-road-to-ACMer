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

const int N = 1 << 9;
int a[N][N], b[N][N];
int r[N][2], c[N][2];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) scanf("%d", &b[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            r[i][0] ^= a[i][j], r[i][1] ^= b[i][j], c[j][0] ^= a[i][j], c[j][1] ^= b[i][j];
    for (int i = 0; i < n; i++)
        if (r[i][0] != r[i][1]) return puts("No"), 0;
    for (int j = 0; j < m; j++)
        if (c[j][0] != c[j][1]) return puts("No"), 0;
    puts("Yes");
    return 0;
}