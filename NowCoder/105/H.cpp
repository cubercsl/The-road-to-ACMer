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
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int N = 1 << 17;
ll a[N << 2], t[N << 2];
#define lson rt << 1
#define rson rt << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson

void pushup(int rt)
{
    a[rt] = (a[lson] | a[rson]);
}

void pushdown(int rt)
{
    if (!t[rt]) return;
    t[lson] |= t[rt], t[rson] |= t[rt];
    a[lson] |= t[rt], a[rson] |= t[rt];
    t[rt] = 0;
}

void update(int L, int R, int v, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        a[rt] |= (1LL << v);
        t[rt] |= (1LL << v);
        return;
    }
    pushdown(rt);
    int m = l + r >> 1;
    if (L <= m) update(L, R, v, Lson);
    if (m < R) update(L, R, v, Rson);
    pushup(rt);
}

ll query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R) return a[rt];
    pushdown(rt);
    int m = l + r >> 1;
    ll ans = 0;
    if (L <= m) ans |= query(L, R, Lson);
    if (m < R) ans |= query(L, R, Rson);
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        clr(a, 0), clr(t, 0);
        while (m--)
        {
            static int op, l, r, c;
            scanf("%d%d%d", &op, &l, &r);
            if (op == 1)
            {
                scanf("%d", &c);
                update(l, r, c, 1, n, 1);
            }
            else
                printf("%d\n", __builtin_popcountll(query(l, r, 1, n, 1)));
        }
    }
    return 0;
}