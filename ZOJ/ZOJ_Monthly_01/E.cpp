#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m, rnk, sum[25][25][3];
int b[25], len, a[25], len2;

ll dfs(int pos, int pos2, bool cmp, bool lim, bool lead)
{
    if (pos == 0)
        return (cmp || pos2 > 20) && (!lead);
    if (!lim && !lead && sum[pos][pos2][cmp] != -1)
        return sum[pos][pos2][cmp];
    ll tmp = 0, up = lim ? a[pos] : 9;
    for (int i = 0; i <= up; ++i)
    {
        bool nxcmp = !(lead && i == 0) && i < b[pos2];
        nxcmp |= cmp;
        if (!cmp && i > b[pos2])
            continue;
        tmp += dfs(pos - 1, pos2 - ((lead && i == 0) ? 0 : 1), nxcmp, lim && i == a[pos], lead && i == 0);
    }
    if (!lim && !lead)
        sum[pos][pos2][cmp] = tmp;
    return tmp;
}

ll check(ll n)
{
    len = 0;
    while (n)
        a[++len] = n % 10, n /= 10;
    ll re = dfs(len, len2, false, true, true);
    return re;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(sum, -1, sizeof(sum));
        scanf("%lld%lld", &m, &rnk);
        len2 = 20;
        ll l = max(rnk, m), r = 7e17, ans = 0;
        while (m)
            b[++len2] = m % 10, m /= 10;
        while (l <= r)
        {
            ll mid = (l + r) >> 1, tmp = check(mid);
            if (tmp == rnk - 1)
            {
                ans = mid;
                r = mid - 1;
            }
            else if (tmp < rnk - 1)
                l = mid + 1;
            else
                r = mid - 1;
        }
        printf("%lld\n", ans);
    }
}