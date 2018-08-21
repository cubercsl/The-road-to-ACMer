#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    long long n, q;
    scanf("%lld%lld", &n, &q);
    while (q--)
    {
        static long long x, y;
        scanf("%lld%lld", &x, &y);
        --x, --y;
        if ((x ^ y) & 1 ^ 1)
        {
            long long ans =  (x * n + y) / 2;
            printf("%lld\n", ans + 1);
        }
        else
        {
            long long ans = n * n / 2 + (x * n + y) / 2;
            printf("%lld\n", ans + 1 + (n & 1));
        }

    }
}