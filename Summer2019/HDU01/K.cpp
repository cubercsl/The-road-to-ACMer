#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, kase = 0;
    long long k;
    while (~scanf("%d%lld", &n, &k))
    {
        printf("Case #%d: ", ++kase);
        if (k <= n)
            printf("%lld\n", k);
        else
        {
            k -= n;
            if (k % (n - 1))
                printf("%lld\n", k % (n - 1));
            else
                printf("%lld\n", n - ((k / (n - 1)) & 1));
        }
    }
}