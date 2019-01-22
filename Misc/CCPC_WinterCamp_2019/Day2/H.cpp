#include <bits/stdc++.h>
using namespace std;
const int maxn = 150;
const double eps = 1e-6;
#define zero(x) ((fabs(x) < eps ? 1 : 0))
const double pi = acos(-1.0);
struct node
{
    double x, y, z, r;
} P[150];
node O;
int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%lf%lf%lf%lf", &P[i].x, &P[i].y, &P[i].z, &P[i].r);
        scanf("%lf%lf%lf%lf", &O.x, &O.y, &O.z, &O.r);
        double ans = 0;
        for (int i = 0; i < n; i++)
        {
            double d = (P[i].x - O.x) * (P[i].x - O.x)
                       + (P[i].y - O.y) * (P[i].y - O.y)
                       + (P[i].z - O.z) * (P[i].z - O.z);
            double dd = sqrt(d);
            if (d + eps > (P[i].r + O.r) * (P[i].r + O.r)) continue;
            if (O.r + eps > dd + P[i].r)
            {
                ans += pi * P[i].r * P[i].r * P[i].r * 4 / 3;
                continue;
            }
            double bb = (O.r * O.r - P[i].r * P[i].r - d) / (-2 * dd);
            double v1 = pi * (P[i].r * P[i].r * P[i].r * 2 / 3 - P[i].r * P[i].r * bb + bb * bb * bb / 3);
            double dx = dd - bb;
            double dy = -O.r + dx;
            double v2 = -pi * (O.r * O.r * dy - dy * dy * dy / 3 - dx * dx * dy + dx * dy * dy);
            //cout << "dd: " << dd << ""
            //cout << v2 << endl;
            //v2 = fabs(v2);
            ans += v1 + v2;
        }
        printf("Case #%d: %.10f\n", ++kase, ans);
    }
}