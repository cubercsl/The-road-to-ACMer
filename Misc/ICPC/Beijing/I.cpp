#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
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
const int mod = 1e9 + 7;
const double eps = 1e-6;

#define lson rt << 1
#define rson rt << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson

const int maxn = 1 << 17;
int minv[maxn << 2], maxv[maxn << 2];

void pushup(int rt)
{
    maxv[rt] = max(maxv[lson], maxv[rson]);
    minv[rt] = min(minv[lson], minv[rson]);
}

void build(int l, int r, int rt)
{
    // printf("build:%d %d %d\n", l, r, rt);
    if (l == r)
    {
        int tmp;
        scanf("%d", &tmp);
        minv[rt] = maxv[rt] = tmp;
        return;
    }
    int m = (l + r) >> 1;
    build(Lson);
    build(Rson);
    pushup(rt);
}

void update(int p, int v, int l, int r, int rt)
{
    // printf("update:%d\n", v);
    if (l == r)
    {
        minv[rt] = maxv[rt] = v;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m)
        update(p, v, Lson);
    else
        update(p, v, Rson);
    pushup(rt);
}

int querymin(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
        return minv[rt];
    int m = (l + r) >> 1;
    int ret = INF;
    if (L <= m) ret = min(ret, querymin(L, R, Lson));
    if (m < R) ret = min(ret, querymin(L, R, Rson));
    return ret;
}

int querymax(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
        return maxv[rt];
    int m = (l + r) >> 1;
    int ret = -INF;
    if (L <= m) ret = max(ret, querymax(L, R, Lson));
    if (m < R) ret = max(ret, querymax(L, R, Rson));
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        build(1, 1 << n, 1);
        int q, c, x, y;
        scanf("%d", &q);
        while (q--)
        {
            scanf("%d%d%d", &c, &x, &y);
            x++, y++;
            if (c == 2)
                update(x, --y, 1, 1 << n, 1);
            else
            {
                ll MIN = querymin(x, y, 1, 1 << n, 1);
                ll MAX = querymax(x, y, 1, 1 << n, 1);
                // printf("%lld %lld\n", MIN * MAX, MIN * MIN);
                ll ans = min(MIN * MAX, MIN * MIN);
                ans = min(MAX * MAX, ans);
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}
