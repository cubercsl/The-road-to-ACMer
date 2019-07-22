#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    double ans = 0;
    scanf("%d", &n);
    for (int i = 0, x; i < n; i++)
    {
        scanf("%d", &x);
        if (ans < 100)
            ans += x;
        else if (ans >= 100 && ans < 150)
            ans += 0.8 * x;
        else if (ans >= 150 && ans < 400)
            ans += 0.5 * x;
        else
            ans += x;
    }
    printf("%.2f\n", ans);
}