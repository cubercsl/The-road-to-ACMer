#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1.0);
int main()
{
    int n;
    while (cin >> n)
    {
        double ans = 0.5 * sin(pi * 2 / n) * n + sin(pi / n) * (1 - cos(pi / n));
        printf("%.6f\n", ans);
    }
}