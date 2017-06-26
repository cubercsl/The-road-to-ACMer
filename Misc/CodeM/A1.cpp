#include <bits/stdc++.h>
using namespace std;

const int maxn = 100002;
double t[maxn], c[maxn];
const double eps = 1e-6;
double T, C;
int n;
bool ok;

bool check(double mid)
{
    double ss = 0;
    for (int i = 0; i < n; i++)
    {
        ss += (t[i] - mid) / (mid - T) * c[i];
        if (ss > C)
            return false;
    }
    return true;
}


double binary(double L, double R)
{
    while (R - L > eps)
    {
        double mid = L + (R - L) / 2;
        if (check(mid))
        {
            L = mid;
            ok = 1;
        }
        else
            R = mid;
    }
    return R;
}

int main()
{
    while (cin >> n)
    {
        ok = 0;
        cin >> T >> C;
        double L = 10000, R = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> t[i] >> c[i];
            L = min(L, t[i]), R = max(R, t[i]);
        }
        if (L < T && R > T)
            cout << "Impossible" << endl;
        else if (T <= L)
        {
            if (check(L))
                printf("Possible\n%.4f\n", L);
            else
                printf("Impossible\n");
        }
        else
        {
            double ans = binary(R, T);
            if (ok)
                printf("Possible\n%.4f\n", ans);
            else
                printf("Impossible\n");
        }
    }
    return 0;
}
