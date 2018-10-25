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

typedef long double dbl;

const int N = 1 << 10;
const dbl eps = 1e-8;
dbl dp[N][N];
const dbl x = -log(1.1) + eps;
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) dp[i][j] = 1e18;
    for (int i = 0; i < n; i++) dp[i][i] = 0;
    int u, v;
    double c;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%lf", &u, &v, &c);
        --u, --v;
        dbl x = -log(c);
        dp[u][v] = min(dp[u][v], x);
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    for (int i = 0; i < n; i++)
    {
        if (dp[i][i] < x)
        {
            printf("in");
            break;
        }
    }
    puts("admissible");
    return 0;
}