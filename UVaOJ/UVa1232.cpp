#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
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
const int maxn = 1e5 + 5;
int maxv[maxn << 2], minv[maxn << 2], setv[maxn << 2]; // Lazy Tag
int ans;

void build(int l, int r, int rt)
{
    setv[rt] = minv[rt] = maxv[rt] = 0;
    if (l == r)return;
    int m = (l + r) >> 1;
    build(Lson);
    build(Rson);
}

void pushup(int rt)
{
    maxv[rt] = max(maxv[lson], maxv[rson]);
    minv[rt] = min(minv[lson], minv[rson]);
}

void pushdown(int rt)
{
    if (setv[rt])
    {
        setv[lson] = setv[rson] = setv[rt];
        maxv[lson] = max(setv[lson], maxv[lson]);
        maxv[rson] = max(setv[rson], maxv[rson]);
        minv[lson] = min(setv[lson], minv[lson]);
        minv[rson] = min(setv[rson], minv[rson]);
        setv[rt] = 0;
    }
}

void update (int L, int R, int val, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        if (val >= maxv[rt])
        {
            ans += r - l + 1;
            setv[rt] = maxv[rt] = minv[rt] = val;
            return;
        }
        if (val <= minv[rt] || l == r) return;
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, val, Lson);
    if (m < R) update(L, R, val, Rson);
    pushup(rt);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)break;
        ans = 0;
        int l[maxn], r[maxn], h[maxn], m = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d%d", &l[i], &r[i], &h[i]);
            m = max(m, r[i]);
        }
        build(1, m, 1);
        for (int i = 0; i < n; i++)
            update(l[i], r[i] - 1, h[i], 1, m, 1);
        printf("%d\n", ans);
    }
    return 0;
}
