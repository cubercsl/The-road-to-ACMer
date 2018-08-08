#include <bits/stdc++.h>
using namespace std;

const double g = 9.8;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        double a, b, x, y;
        scanf("%lf%lf%lf%lf", &a, &b, &x, &y);
        double t2 = (2 * (y + x * b / a)) / g;
        double t = b / a;
        double s = 2 * t / (1 + t * t);
        int k = 0;
        while (x < 0)
        {
            k++;
            x += 2 * k * g * t2 * s;
        }
        printf("%d\n", k);
    }
}