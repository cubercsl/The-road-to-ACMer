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
int a[N][N], b[N][N];
int n, m, h, w;
pair<int, int> dic[N * N];

bool check(int x)
{
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= x; i++) b[dic[i].first][dic[i].second] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            b[i][j] += b[i - 1][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            b[i][j] += b[i][j - 1];
    int mx = 0;
    for (int i = h; i <= n; i++)
        for (int j = w; j <= m; j++)
            mx = max(mx, b[i][j] - b[i][j - w] - b[i - h][j] + b[i - h][j - w]);
    return mx > h * w / 2;
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &h, &w);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) dic[a[i][j]] = {i, j};
    int l = 1, r = n * m, ans;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    printf("%d\n", ans);
    return 0;
}