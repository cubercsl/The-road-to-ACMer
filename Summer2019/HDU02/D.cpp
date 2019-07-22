#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m, p;
        scanf("%d%d%d", &n, &m, &p);
        int num = n * m - 1;
        long long ans = 0;
        while (num > 0)
        {
            int t = (num - 1) / p + 1;
            ans += t * (t - 1) / 2 * (p - 1);
            num -= t;
        }
        if (ans & 1 ^ 1) puts("YES");
        else puts("NO");
    }
}