#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 20;
typedef long long ll;
int a[N];
ll sum[N];
ll sum2[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + a[i];
        sum2[i] = sum2[i - 1] + 1LL * a[i] * a[i];
    }
    ll ans = 1e18;
    for (int i = 1; i + m - 1 <= n; i++)
    {
        ll Sum2 = sum2[i + m - 1] - sum2[i - 1];
        ll Sum = abs(sum[i + m - 1] - sum[i - 1]);
        // printf("%lld %lld\n", Sum2, Sum);
        ans = min(ans, Sum2 * m - Sum * Sum);
    }
    printf("%lld\n", ans);
}