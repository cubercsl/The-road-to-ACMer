#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int a[maxn], rt[maxn];
int sz;
int cnt;
int lson[maxn << 5], rson[maxn << 5], sum[maxn << 5];
#define Lson l, m, lson[x], lson[y]
#define Rson m + 1, r, rson[x], rson[y]

void update(int p, int l, int r, int& x, int y)
{
    lson[++cnt] = lson[y], rson[cnt] = rson[y], sum[cnt] = sum[y] + 1, x = cnt;
    if (l == r) return;
    int m = (l + r) >> 1;
    if (p <= m)
        update(p, Lson);
    else
        update(p, Rson);
}

int query(int L, int R, int l, int r, int x, int y)
{
    if (L <= l && r <= R) return sum[y] - sum[x];
    int m = l + r >> 1;
    int ret = 0;
    if (L <= m) ret += query(L, R, Lson);
    if (m < R) ret += query(L, R, Rson);
    return ret;
}


int solve(int L, int R, int p, int k, int sz)
{
    int ans = 0;
    int l = 0, r = sz;
    while (l <= r)
    {
        int mid = l + r >> 1;
        int LL = max(1, p - mid);
        int RR = min(sz, p + mid);
        int tmp = query(LL, RR, 1, sz, rt[L - 1], rt[R]);
        if (tmp >= k)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        int sz = *max_element(a + 1, a + 1 + n);
        cnt = 0;
        rt[0] = sum[0] = 0;
        for (int i = 1; i <= n; i++) update(a[i], 1, sz, rt[i], rt[i - 1]);
        int lastans = 0;
        while (m--)
        {
            static int l, r, p, k;
            scanf("%d%d%d%d", &l, &r, &p, &k);
            l ^= lastans;
            r ^= lastans;
            p ^= lastans;
            k ^= lastans;
            lastans = solve(l, r, p, k, sz);
            printf("%d\n", lastans);
        }
    }
}
