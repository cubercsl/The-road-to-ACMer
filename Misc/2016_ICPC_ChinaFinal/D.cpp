#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3e5 + 5;
ll b[maxn];
ll dp[2][maxn];
int n, k;
bool ok(int m)
{
    for (int i = 0; i < m; i++)
        dp[0][i] = b[i];
    int p = m;
    for (int i = 1; i < k; i++)
        for (int j = 0; j < m; j++)
        {
            while (p < n && b[p] < dp[i & 1 ^ 1][j] * 2) p++;
            if (p == n) return false;
            dp[i & 1][j] = b[p++];
        }
    return true;
}

int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++)
            scanf("%lld", b + i);
        sort(b, b + n);
        int l = 1, r = n / k;
        int ans = 0;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (ok(mid))
                l = mid + 1, ans = mid;
            else
                r = mid - 1;
        }
        printf("Case #%d: %d\n", ++kase, ans);
    }
    return 0;
}
