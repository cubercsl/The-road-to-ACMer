#include <bits/stdc++.h>
#define NE 2.718281828459
using namespace std;

int main()
{
    double L, v, u;
    while (cin >> L >> v >> u)
    {
        double tmp = pow(NE, u / v);
        double ans = (tmp - 1) * L / u;
        printf("%.2f\n", ans);
    }
    return 0;
}
