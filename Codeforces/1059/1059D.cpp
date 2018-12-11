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
typedef long double db;
const int N = 1 << 17;
const db eps = 1e-7;
struct Point
{
    db x, y;
} a[N];
db Run(db x, int n)
{
    db r = 0;
    for (int i = 0; i < n; i++)
    {
        db p = (x - a[i].x) * (x - a[i].x) + 1.0 * a[i].y * a[i].y;
        p = p / 2.0 / a[i].y;
        if (p < 0) p = -p;
        r = max(r, p);
    }
    return r;
}

int main()
{
    int n;
    scanf("%d", &n);
    int sgn = 0;
    for (int i = 0, x, y; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        if (i == 0 && y > 0) sgn = 1;
        if (i == 0 && y < 0) sgn = -1;
        if (sgn == 1 && y < 0) return puts("-1"), 0;
        if (sgn == -1 && y > 0) return puts("-1"), 0;
        if (y < 0) y = -y;
        a[i].x = x, a[i].y = y;
    }
    db l = -1e8, r = 1e8;
    for (int i = 0; i < 100; i++)
    {
        db x1 = l + (r - l) / 3;
        db x2 = r - (r - l) / 3;
        if (Run(x1, n) < Run(x2, n))
            r = x2;
        else
            l = x1;
    }
    printf("%.10Lf\n", Run(l, n));
    return 0;
}