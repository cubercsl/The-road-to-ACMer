#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;

#define lson rt << 1
#define rson rt << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson

const int maxn = 1e5 + 5;
int a[maxn], b[maxn];
int dp[maxn << 2];

void pushup(int rt)
{
    dp[rt] = max(dp[lson], dp[rson]);
}

void build(int l, int r, int rt)
{
    dp[rt] = 0;
    if (l == r)
        return;
    int m = (l + r) >> 1;
    build(Lson);
    build(Rson);
}

void update(int p, int v, int l, int r, int rt)
{
    if (l == r)
    {
        dp[rt] = max(v, dp[rt]);
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m)
        update(p, v, Lson);
    else
        update(p, v, Rson);
    pushup(rt);
}

int query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
        return dp[rt];
    int m = (l + r) >> 1, ans = 0;
    if (L <= m)
        ans = max(query(L, R, Lson), ans);
    if (m < R)
        ans = max(query(L, R, Rson), ans);
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, d;
    while (~scanf("%d%d", &n, &d))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", a + i);
            b[i] = a[i];
        }
        sort(b, b + n);
        int tot = unique(b, b + n) - b;
        build(1, tot, 1);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int l = lower_bound(b, b + tot, a[i] - d) - b + 1;
            int r = upper_bound(b, b + tot, a[i] + d) - b;
            int id = lower_bound(b, b + tot, a[i]) - b + 1;
            //printf("debug:%d %d %d\n", l, r, id);
            int tmp = query(l, r, 1, tot, 1);
            ans = max(tmp + 1, ans);
            update(id, tmp + 1, 1, tot, 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}
