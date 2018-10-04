#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        double ans = 0;
        for (int i = 0; i < k; i++)
            ans += (n - i) * 1.0 / (m - i);
        printf("Case #%d: %.10f\n", ++kase, ans);
    }
}