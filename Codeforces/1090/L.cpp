#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, a, b, k;
    scanf("%d%d%d%d%d", &t, &n, &a, &b, &k);
    int l = 0, r = t, ans = 0;
    while (l <= r)
    {
        int m = l + r >> 1;
        long long sum = 1LL * (n + 1) / 2 * min(a, m) + 1LL * n / 2 * min(b, m);
        if (sum >= 1LL * k * m)
            l = (ans = m) + 1;
        else
            r = m - 1;
    }
    printf("%d\n", ans);
}