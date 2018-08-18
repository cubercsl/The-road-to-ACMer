#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l, k, a, b;
    scanf("%d%d%d%d", &l, &k, &a, &b);
    double t1 = l * 1.0 / a;
    double t2 = l * 1.0 / b;
    double ans = t2 - t1;
    if (b < a)
    {
        double t3 = k * 2.0 / (a - b);
        if (l - t3 * a >= k)
            ans = min(ans, t3 - t1);
    }
    printf("%.2f\n", ans);
}