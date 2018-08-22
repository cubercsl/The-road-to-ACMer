#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1 << 17;
ll a[N][8];
ll b[N][8];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &a[i][0]);
            for (int j = 0; j < k; j++)
                scanf("%lld", &a[i][j + 2]);
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%lld", &b[i][1]);
            for (int j = 0; j < k; j++)
                scanf("%lld", &b[i][j + 2]);
        }
        ll ans = 0;
        for (int s = 0; s < (1 << (k + 2)); s++)
        {
            ll minv1 = 1e18, maxv1 = -1e18;
            ll minv2 = 1e18, maxv2 = -1e18;

            for (int i = 0; i < n; i++)
            {
                ll t = 0;
                for (int j = 0; j < (k + 2); j++)
                    if (s >> j & 1)
                        t += a[i][j];
                    else
                        t -= a[i][j];
                maxv1 = max(maxv1, t);
                minv1 = min(minv1, t);
            }
            for (int i = 0; i < m; i++)
            {
                ll t = 0;
                for (int j = 0; j < (k + 2); j++)
                    if (s >> j & 1)
                        t += b[i][j];
                    else
                        t -= b[i][j];
                maxv2 = max(maxv2, t);
                minv2 = min(minv2, t);
            }
            ans = max({ans, maxv1 - minv2, maxv2 - minv1});
        }
        printf("%lld\n", ans);
    }
}