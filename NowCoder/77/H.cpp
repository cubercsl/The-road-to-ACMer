#include<bits/stdc++.h>
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
const int maxn = 1e5 + 5;
ll sumv[maxn << 2], addv[maxn << 2];

void pushup(int rt) { sumv[rt] = sumv[lson] + sumv[rson]; }

void pushdown(int rt, int m)
{
    if (addv[rt] == 0)
        return;
    addv[lson] += addv[rt];
    addv[rson] += addv[rt];
    sumv[lson] += addv[rt] * (m - (m >> 1));
    sumv[rson] += addv[rt] * (m >> 1);
    addv[rt] = 0;
}

void build(int l, int r, int rt)
{
    addv[rt] = 0;
    if (l == r)
    {
        scanf("%lld", &sumv[rt]);
        return;
    }
    int m = (l + r) >> 1;
    build(Lson);
    build(Rson);
    pushup(rt);
}

void update(int L, int R, ll add, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        addv[rt] += add;
        sumv[rt] += add * (r - l + 1);
        return;
    }
    pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, add, Lson);
    if (m < R) update(L, R, add, Rson);
    pushup(rt);
}

ll query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R) return sumv[rt];
    pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    ll ans = 0;
    if (L <= m) ans += query(L, R, Lson);
    if (m < R) ans += query(L, R, Rson);
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, q;
    scanf("%d%d", &n, &q);
    build(1, n, 1);
    while (q--)
    {
        char op;
        int l, r;
        ll add;
        scanf(" %c", &op);
        if (op == 'Q')
        {
            scanf("%d%d", &l, &r);
            printf("%lld\n", query(l, r, 1, n, 1));
        }
        else
        {
            scanf("%d%d%lld", &l, &r, &add);
            update(l, r, add, 1, n, 1);
        }
    }
    return 0;
}