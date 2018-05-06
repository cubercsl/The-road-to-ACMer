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
const int mod = 998244353;
const double eps = 1e-6;

const int N = 1 << 17;
int cnt2[N << 2], cnt3[N << 2], add2[N << 2], add3[N << 2];

void build() { clr(cnt2, 0), clr(cnt3, 0), clr(add2, 0), clr(add3, 0); }
#define lson rt << 1
#define rson rt << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson

inline void pushup(int rt)
{
    cnt2[rt] = min(cnt2[lson], cnt2[rson]);
    cnt3[rt] = min(cnt3[lson], cnt3[rson]);
}

inline void pushdown(int rt)
{
    if (add2[rt])
    {
        cnt2[lson] += add2[rt], cnt2[rson] += add2[rt];
        add2[lson] += add2[rt], add2[rson] += add2[rt];
        add2[rt] = 0;
    }
    if (add3[rt])
    {
        cnt3[lson] += add3[rt], cnt3[rson] += add3[rt];
        add3[lson] += add3[rt], add3[rson] += add3[rt];
        add3[rt] = 0;
    }
}

void update(int L, int R, int v, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        if (v == 2) cnt2[rt]++, add2[rt]++;
        if (v == 3) cnt3[rt]++, add3[rt]++;
        return;
    }
    pushdown(rt);
    int m = l + r >> 1;
    if (L <= m) update(L, R, v, Lson);
    if (m < R) update(L, R, v, Rson);
    pushup(rt);
}

ll Pow(ll a, ll n)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1) (t *= a) %= mod;
    return t;
}

ll query()
{
    int a = cnt2[1], b = cnt3[1];
    ll ans = (Pow(2, a) * Pow(3, b)) % mod;
    return ans;
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
        int n, m;
        scanf("%d%d", &n, &m);
        build();
        while (m--)
        {
            static int l, r, op;
            scanf("%d%d%d", &l, &r, &op);
            update(l, r, op, 1, n, 1);
        }
        printf("%lld\n", query());
    }
    return 0;
}