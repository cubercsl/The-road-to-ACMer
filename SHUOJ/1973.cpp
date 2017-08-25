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
ll v0[maxn << 2], v1[maxn << 2], v2[maxn << 2], addv[maxn << 2];

inline void add1(int rt)
{
    int tmp = v0[rt];
    v0[rt] = v1[rt];
    v1[rt] = v2[rt];
    v2[rt] = tmp;
}

inline void add2(int rt)
{
    int tmp = v0[rt];
    v0[rt] = v2[rt];
    v2[rt] = v1[rt];
    v1[rt] = tmp;
}

void pushup(int rt)
{
    v0[rt] = v0[lson] + v0[rson];
    v1[rt] = v1[lson] + v1[rson];
    v2[rt] = v2[lson] + v2[rson];
}

void build (int l, int r, int rt)
{
    v1[rt] = v2[rt] = 0;
    if (l == r)
    {
        v0[rt] = 1;
        return;
    }
    int m = (l + r) >> 1;
    build(Lson);
    build(Rson);
    pushup(rt);
}

void pushdown(int rt)
{
    if (addv[rt] == 0) return;
    addv[lson] += addv[rt];
    addv[rson] += addv[rt];
    if (addv[rt] % 3 == 1)
    {
        add1(lson);
        add1(rson);
    }
    if (addv[rt] % 3 == 2)
    {
        add2(lson);
        add2(rson);
    }
    addv[rt] = 0;
}

void update(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        addv[rt]++;
        add1(rt);
        return;
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, Lson);
    if (m < R) update(L, R, Rson);
    pushup(rt);
}

ll query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
        return v0[rt];
    pushdown(rt);
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
    fastin
    int n, q, c, l, r;
    cin >> n >> q;
    build(1, n, 1);
    while (q--)
    {
        cin >> c >> l >> r;
        if (c)
            cout << query(l, r, 1, n, 1) << endl;
        else
            update(l, r, 1, n, 1);
    }
    return 0;
}
