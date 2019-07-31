#include <bits/stdc++.h>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Lson l, m, lson
#define Rson m + 1, r, rson
typedef long long ll;
const int N = 1 << 18;
long long a[N], pre[N], b[N];
typedef long long ll;

int dp[N << 2];
void build(int l, int r, int rt)
{
    dp[rt] = 0;
    if (l == r) return;
    int m = l + r >> 1;
    build(Lson);
    build(Rson);
}
void update(int l, int r, int rt, int p, int x)
{
    if (l == r)
    {
        dp[rt] = max(dp[rt], x);
        return;
    }
    int m = l + r >> 1;
    if (p <= m)
        update(Lson, p, x);
    else
        update(Rson, p, x);
    dp[rt] = max(dp[lson], dp[rson]);
}

int query(int l, int r, int rt, int L, int R)
{
    if (L <= l && R >= r) return dp[rt];
    int m = l + r >> 1;
    int ret = -1e9;
    if (L <= m) ret = max(ret, query(Lson, L, R));
    if (m + 1 <= R) ret = max(ret, query(Rson, L, R));
    return ret;
}
int sz;
int n, k;

inline int getid(ll x) { return lower_bound(b, b + sz, x) - b + 1; }

bool ok(ll x)
{
    build(1, sz, 1);
    update(1, sz, 1, getid(0), 0);
    for (int i = 1; i <= n; i++)
    {
        int id = getid(pre[i] - x);
        int val = query(1, sz, 1, id, sz) + 1;
        id = getid(pre[i]);
        update(1, sz, 1, id, val);
        if (val >= k) return true;
    }
    return false;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &k);
        b[0] = 0;
        for (int i = 1; i <= n; i++) scanf("%lld", a + i);
        for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
        for (int i = 1; i <= n; i++) b[i] = pre[i];
        sort(b, b + 1 + n);
        sz = unique(b, b + 1 + n) - b;
        long long l = -2e14 - 1, r = 2e14 + 1;
        ll ans = -1e18;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            if (ok(mid))
            {
                cerr << mid << ' ' << "true" << endl;
                ans = mid;
                r = mid - 1;
            }
            else
            {
                cerr << mid << ' ' << "false" << endl;

                l = mid + 1;
            }
        }
        printf("%lld\n", ans);
    }
}