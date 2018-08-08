#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
double a, b;
const int mod = 1e6;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        scanf("%lf%lf", &a, &b);
        double ans = 2 * b + PI * a;
        long long fuck = ans * 1000000;
        printf("%.6f\n", 1.0 * fuck / 1000000);
    }
}