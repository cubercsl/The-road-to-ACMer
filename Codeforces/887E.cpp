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

const int maxn = 1 << 18;
VI G[maxn];
int dfn;
int L[maxn], R[maxn], v[maxn];
int val[maxn << 2], tag[maxn << 2], col[maxn];
inline void init(int n)
{
    dfn = 0;
    for (int i = 1; i <= n; i++) G[i].clear();
}

void dfs(int u)
{
    L[u] = ++dfn;
    v[L[u]] = col[u];
    for (auto& v : G[u])
        dfs(v);
    R[u] = dfn;
}

#define lson rt << 1
#define rson rt << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson

inline void pushup(int rt)
{
    val[rt] = val[lson] + val[rson];
}

void build(int l, int r, int rt)
{
    tag[rt] = 0;
    if (l == r)
    {
        val[rt] = v[l];
        return;
    }
    int m = l + r >> 1;
    build(Lson);
    build(Rson);
    pushup(rt);
}

void pushdown(int rt, int m)
{
    if (!tag[rt]) return;
    tag[lson] ^= tag[rt];
    tag[rson] ^= tag[rt];
    val[lson] = (m - (m >> 1)) - val[lson];
    val[rson] = (m >> 1) - val[rson];
    tag[rt] = 0;
}

void update(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        tag[rt] ^= 1;
        val[rt] = (r - l + 1) - val[rt];
        return;
    }
    pushdown(rt, r - l + 1);
    int m = l + r >> 1;
    if (L <= m) update(L, R, Lson);
    if (m < R) update(L, R, Rson);
    pushup(rt);
}

int query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R) return val[rt];
    pushdown(rt, r - l + 1);
    int m = l + r >> 1, ret = 0;
    if (L <= m) ret += query(L, R, Lson);
    if (m < R) ret += query(L, R, Rson);
    return ret;
}

int main()
{
    int n, q;
    while (~scanf("%d", &n))
    {
        init(n);
        for (int i = 2; i <= n; i++)
        {
            static int fa;
            scanf("%d", &fa);
            G[fa].pb(i);
        }
        for (int i = 1; i <= n; i++)
            scanf("%d", &col[i]);
        dfs(1);
        build(1, n, 1);
        scanf("%d", &q);
        while (q--)
        {
            static char op[4];
            static int id;
            scanf("%s%d", op, &id);
            if (op[0] == 'g')
                printf("%d\n", query(L[id], R[id], 1, n, 1));
            else
                update(L[id], R[id], 1, n, 1);
        }
    }
    return 0;
}
