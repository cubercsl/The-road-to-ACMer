#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second
#define PII pair<int, int>
const int maxn = 2e5 + 5;
int n, m, b[maxn], a[maxn];
ll t;
int judge(int d)
{
    ll tmp = t;
    int cnt = 0, mm = 0, tt = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] <= d)
        {
            if (b[i] > tmp) break;
            cnt++, mm++, tt += b[i], tmp -= b[i];
            if (mm == m)
                tmp -= tt, mm = 0, tt = 0;
        }
    }
    return cnt;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%lld", &n, &m, &t);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &b[i]);
            a[i] = b[i];
        }
        sort(a, a + n);
        int l = 1, r = n;
        int ans = 0, dd = 1;
        while (l <= r)
        {
            int mid = (r + l) / 2;
            int tc = judge(a[mid - 1]);
            if (tc >= mid)
            {
                if (tc >= ans)
                    ans = tc, dd = a[mid - 1];
                l = mid + 1;
            }
            else
            {
                if (tc >= ans)
                    ans = tc, dd = a[mid - 1];
                r = mid - 1;
            }
        }
        printf("%d %d\n", ans, dd);
    }
}