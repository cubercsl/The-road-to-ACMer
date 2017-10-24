#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;

inline bool check(double x0, double y0, double x1, double y1, double x2, double y2, double A, double B)
{
    double k = (y2 - y1) / (x2 - x1);
    double b = y1 - k * x1;
    double t = (k * x0 + b - y0) / (B - k * A);

    if (t >= 0)
    {
        double x = x0 + A * t;
        if ((x1 <= x && x <= x2) || (x1 >= x && x >= x2))
            return true;
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T, kase = 0;
    double x1, y1, x2, y2, x3, y3, xd, yd;
    double x4, y4, x5, y5, x6, y6, xe, ye;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
        scanf("%lf%lf", &xd, &yd);
        scanf("%lf%lf%lf%lf%lf%lf", &x4, &y4, &x5, &y5, &x6, &y6);
        scanf("%lf%lf", &xe, &ye);

        double X = xd - xe, Y = yd - ye;
        bool flag = false;
        if (check(x1, y1, x4, y4, x5, y5, X, Y)) flag = true;
        if (check(x1, y1, x5, y5, x6, y6, X, Y)) flag = true;
        if (check(x1, y1, x4, y4, x6, y6, X, Y)) flag = true;
        if (check(x2, y2, x4, y4, x5, y5, X, Y)) flag = true;
        if (check(x2, y2, x5, y5, x6, y6, X, Y)) flag = true;
        if (check(x2, y2, x4, y4, x6, y6, X, Y)) flag = true;
        if (check(x3, y3, x4, y4, x5, y5, X, Y)) flag = true;
        if (check(x3, y3, x5, y5, x6, y6, X, Y)) flag = true;
        if (check(x3, y3, x4, y4, x6, y6, X, Y)) flag = true;

        if (check(x4, y4, x1, y1, x2, y2, -X, -Y)) flag = true;
        if (check(x4, y4, x2, y2, x3, y3, -X, -Y)) flag = true;
        if (check(x4, y4, x1, y1, x3, y3, -X, -Y)) flag = true;
        if (check(x5, y5, x1, y1, x2, y2, -X, -Y)) flag = true;
        if (check(x5, y5, x2, y2, x3, y3, -X, -Y)) flag = true;
        if (check(x5, y5, x1, y1, x3, y3, -X, -Y)) flag = true;
        if (check(x6, y6, x1, y1, x2, y2, -X, -Y)) flag = true;
        if (check(x6, y6, x2, y2, x3, y3, -X, -Y)) flag = true;
        if (check(x6, y6, x1, y1, x3, y3, -X, -Y)) flag = true;
        printf("Case #%d: ", ++kase);
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
