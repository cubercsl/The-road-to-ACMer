#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
int d[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i)
            d[j]++;
    int T;
    scanf("%d", &T);
    while (T--)
    {
        static int a, b;
        scanf("%d%d", &a, &b);
        int g = __gcd(a, b);
        printf("%lld\n", 1LL * d[a] * d[b] - d[g] * (d[g] - 1) / 2);
    }
    return 0;
}