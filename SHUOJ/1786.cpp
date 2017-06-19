#include <bits/stdc++.h>
using namespace std;
double mpow(double x, int y)
{
    double ans = 1.0;
    while (y--)
        ans *= x;
    return ans;
}

long double pre(int x, int y)
{
    long double ans = 1.0;
    long double d = 1.0;
    for (int i = 0; i < y; i++)
        ans *= (x - i), d *= (i + 1);
    return ans / d;
}

int main()
{
    const double eps = 1e-6;
    int n, x;
    while (cin >> n >> x)
    {
        int t = (n - 1) / 5 + 1;
        double ans = 0;
        for (int i = 0; i < t; i++)
            ans += mpow((99.0 - x) * 0.01, n - i - 1) * mpow(1.0 - (99.0 - x) * 0.01, i) * pre(n - 1, i);
        if (ans < eps)
            cout << "Happy Yaoge!" << endl;
        else
            printf("%6f\n", ans);
    }
    return 0;
}
