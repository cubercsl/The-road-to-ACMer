#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        long long a[6];
        for (int i = 0; i < 6; i++) scanf("%lld", a + i);
        long long sum = accumulate(a, a + 6, 0);
        long double x = 0;
        for (int i = 0; i < 6; i++)
        {
            if (a[i] == 0) continue;
            x = max(x, static_cast<long double>(a[i] * 1.0 / sum * (i + 1)));
        }
        printf("%.12f\n", x);
    }
}