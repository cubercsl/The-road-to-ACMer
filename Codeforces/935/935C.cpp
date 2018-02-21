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
const int mod = 1e9 + 7;
const double eps = 1e-8;

inline double dis(double x1, double y1, double x2, double y2) { return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2); }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    ll R, x1, y1, x2, y2;
    cin >> R >> x1 >> y1 >> x2 >> y2;
    if (dis(x1, y1, x2, y2) - R * R > eps)
        cout << x1 << " " << y1 << " " << R << endl;
    else
    {
        if (fabs(x1 - x2) < eps)
        {
            if (fabs(y1 + R - y2) > fabs(y1 - R - y2))
                printf("%.12lf %.12lf %.12lf\n", 1.0 * x1, 1.0 * (y1 + R + y2) / 2, 1.0 * fabs(y1 + R - y2) / 2);
            else
                printf("%.12lf %.12lf %.12lf\n", 1.0 * x1, 1.0 * (y1 - R + y2) / 2, 1.0 * fabs(y1 - R - y2) / 2);
        }
        else
        {
            double k = 1.0 * (y2 - y1) / (x2 - x1);
            double A = k * k + 1;
            double B = -2 * x1 - 2 * k * k * x2 + 2 * k * y2 - 2 * k * y1;
            double C = k * k * x2 * x2 - 2 * k * x2 * y2 + y2 * y2 + 2 * k * y1 * x2 - 2 * y1 * y2 + x1 * x1 + y1 * y1 - R * R;
            double D = B * B - 4 * A * C;
            double x3 = (-B + sqrt(D)) / (2 * A), y3 = k * (x3 - x2) + y2;
            double x4 = (-B - sqrt(D)) / (2 * A), y4 = k * (x4 - x2) + y2;
            if (dis(x3, y3, x2, y2) > dis(x4, y4, x2, y2))
                printf("%.12lf %.12lf %.12lf\n", (x3 + x2) / 2, (y3 + y2) / 2, sqrt(dis(x3, y3, x2, y2)) / 2);
            else
                printf("%.12lf %.12lf %.12lf\n", (x4 + x2) / 2, (y4 + y2) / 2, sqrt(dis(x4, y4, x2, y2)) / 2);
        }
    }
    return 0;
}