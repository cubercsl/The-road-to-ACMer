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

const int N = 1 << 7;
int fa[N];

double dp[N][N][N];

int d[N][N];
int v[N];

int main()
{
    int n;
    scanf("%d", &n);
    memset(d, 0x3f, sizeof(d));
    memset(dp, 0, sizeof(dp));
    for (int i = 2, x; i <= n; i++) scanf("%d", fa + i), d[fa[i]][i] = d[i][fa[i]] = 1;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    int p, q;
    scanf("%d%d", &p, &q);
    for (int i = 0, id, val; i < p; i++)
    {
        scanf("%d%d", &id, &val);
        v[id] = val;
    }
    for (int i = n; i; i--)
    {
    }
    return 0;
}