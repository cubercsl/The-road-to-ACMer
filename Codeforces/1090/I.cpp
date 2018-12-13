#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 5;
unsigned int b[N];
int a[N];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        unsigned int x, y, z;
        int n;
        long long l, r;
        scanf("%d%lld%lld%u%u%u%u%u", &n, &l, &r, &x, &y, &z, &b[0], &b[1]);
        for (int i = 2; i < n; i++) b[i] = b[i - 2] * x + b[i - 1] * y + z;
        for (int i = 0; i < n; i++) a[i] = static_cast<int>(b[i] % (r - l + 1) + l);
        long long ans = LONG_LONG_MAX;
        // cerr << ans << endl;
        long long minv = a[0];
        for (int i = 1; i < n; i++)
        {
            if (minv < a[i])
                ans = min(ans, minv * a[i]);
            else
                minv = a[i];
        }
        long long maxv = a[n - 1];
        for (int i = n - 1; ~i; i--)
        {
            if (maxv > a[i])
                ans = min(ans, maxv * a[i]);
            else
                maxv = a[i];
        }
        if (ans == LONG_LONG_MAX)
            puts("IMPOSSIBLE");
        else
            printf("%lld\n", ans);
    }
}