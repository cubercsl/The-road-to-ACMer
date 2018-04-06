#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        long long ans = 0;
        int a = n / 2 + 1, m = 1;
        for (int i = 0; i < n; i++)
        {
            ans += 1LL * a * m + 1LL * m * (m - 1) / 2;
            if (i < n / 2)
                a += n - 1, m += 2;
            else
                a += n + 1, m -= 2;
        }
        printf("%lld\n", ans);
    }
    return 0;
}