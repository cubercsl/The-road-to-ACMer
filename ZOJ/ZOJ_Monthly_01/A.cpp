#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    long long n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld", &n);
        --n;
        long long ans = 0;
        while (n)
        {
            if ((n | 1) == n) ++ans;
            n >>= 1;
        }
        ans = 1LL << ans;
        printf("%lld\n", ans);
    }
}