#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1.0);

inline double dis(double x, double y)
{
    return sqrt(x * x + y * y);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        double R;
        scanf("%d%lf", &n, &R);
        double ans = 2 * pi * R;
        for (int i = 0; i < n; i++)
        {
            static double x, y, r;
            scanf("%lf%lf%lf", &x, &y, &r);
            double d = dis(x, y);
            if (d > R + r || d < R - r) continue;
            double ao = 2 * acos((R * R + d * d - r * r) / (2.0 * R * d));
            ans -= R * ao;
            double as = 2 * acos((r * r + d * d - R * R) / (2.0 * r * d));
            ans += r * as;
        }
        printf("%.10lf\n", ans);
    }
}
