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

const int N = 1 << 17;

int root[N][2];
int val[N << 7], lson[N << 7], rson[N << 7];
int sz, n;
void init(int n)
{
    ::n = n;
    sz = 1;
}
inline int newNode(int x = 0)
{
    val[sz] = val[x];
    lson[sz] = lson[x];
    rson[sz] = rson[x];
    return sz++;
}
void update(int p, int v, int l, int r, int o, int& x)
{
    x = newNode(o);
    val[x] += v;
    if (l == r) return;
    int m = l + r >> 1;
    if (p <= m)
        update(p, v, l, m, lson[o], lson[x]);
    else
        update(p, v, m + 1, r, rson[o], rson[x]);
}
void merge(int x, int y, int l, int r, int& rt)
{
    if (!x || !y)
    {
        rt = x + y;
        return;
    }
    rt = newNode();
    val[rt] = val[x] + val[y];
    int m = l + r >> 1;
    merge(lson[x], lson[y], l, m, lson[rt]);
    merge(rson[x], rson[y], m + 1, r, rson[rt]);
}
void Merge(int x, int y, int l, int r, int u, int& rt)
{
    if (!x || !y)
    {
        rt = x + y;
        return;
    }
    rt = newNode();
    if (l == r)
    {
        val[rt] = min(val[x], val[y]);
        if (val[x] > val[y])
            update(val[x], -1, 1, n, root[u][0], root[u][0]);
        else
            update(val[y], -1, 1, n, root[u][0], root[u][0]);
        return;
    }
    int m = l + r >> 1;
    Merge(lson[x], lson[y], l, m, u, lson[rt]);
    Merge(rson[x], rson[y], m + 1, r, u, rson[rt]);
}
int query(int L, int R, int l, int r, int o)
{
    if (L <= l && r <= R) return val[o];
    int m = l + r >> 1;
    int ret = 0;
    if (L <= m) ret += query(L, R, l, m, lson[o]);
    if (m < R) ret += query(L, R, m + 1, r, rson[o]);
    return ret;
}

int a[N], f[N], d[N];

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
        init(n);
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        for (int i = 2; i <= n; i++) scanf("%d", f + i);
        for (int i = 1; i <= n; i++) d[i] = d[f[i]] + 1;
        for (int i = 1; i <= n; i++) update(d[i], 1, 1, n, 0, root[i][0]), update(a[i], d[i], 1, n, 0, root[i][1]);
        for (int i = n; i; i--) merge(root[f[i]][0], root[i][0], 1, n, root[f[i]][0]), Merge(root[f[i]][1], root[i][1], 1, n, f[i], root[f[i]][1]);
        int ans = 0;
        while (m--)
        {
            static int x, y;
            scanf("%d%d", &x, &y);
            x ^= ans, y ^= ans;
            y += d[x];
            printf("%d\n", ans = query(1, min(y, n), 1, n, root[x][0]));
        }
    }
    return 0;
}