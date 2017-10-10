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

const int maxn = 5e5 + 5;
int val[maxn << 2];
inline void pushup(int rt) { val[rt] = val[lson] + val[rson]; }
void build(int l, int r, int rt)
{
    if (l == r)
    {
        val[rt] = 0;
        return;
    }
    int m = (l + r) >> 1;
    build(Lson);
    build(Rson);
}
bool update(int p, int l, int r, int rt)
{
    if (l == r)
    {
        if (val[rt]) return false;
        return val[rt] = 1;
    }
    bool flag = 0;
    int m = (l + r) >> 1;
    if (p <= m) flag = update(p, Lson);
    if (m < p) flag = update(p, Rson);
    pushup(rt);
    return flag;
}
int query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R) return val[rt];
    int m = (l + r) >> 1, ret = 0;
    if (L <= m) ret += query(L, R, Lson);
    if (m < R) ret += query(L, R, Rson);
    return ret;
}
struct Node
{
    int l, r, k;
    bool operator<(const Node& rhs) const
    {
        return r < rhs.r || r == rhs.r && l > rhs.l;
    }
} q[maxn << 1];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        ll ans = 0;
        build(1, n, 1);
        for (int i = 0; i < m; i++) scanf("%d%d%d", &q[i].l, &q[i].r, &q[i].k);
        sort(q, q + m);
        for (int i = 0; i < m; i++)
        {
            int l = q[i].l, r = q[i].r, k = q[i].k;
            // printf("%d %d %d\n", l, r, k);
            int tmp = k - query(l, r, 1, n, 1);
            while (tmp > 0)
            {
                bool flag = update(r--, 1, n, 1);
                if (flag) tmp--, ans++;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
