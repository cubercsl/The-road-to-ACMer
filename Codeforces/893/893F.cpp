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
struct Node
{
    Node *lson, *rson;
    int minv;
    Node() : lson(nullptr), rson(nullptr), minv(INF) {}
} t[N << 6];

Node* rt[N << 6];
int tot;

void update(int p, int v, int l, int r, Node*& o)
{
    o = &t[++tot];
    o->minv = min(o->minv, v);
    if (l == r) return;
    int m = l + r >> 1;
    if (p <= m)
        update(p, v, l, m, o->lson);
    else
        update(p, v, m + 1, r, o->rson);
}

int query(int L, int R, int l, int r, Node* o)
{
    if (o == nullptr) return INF;
    if (L <= l && r <= R) return o->minv;
    int m = l + r >> 1;
    int ret = INF;
    if (L <= m) ret = min(ret, query(L, R, l, m, o->lson));
    if (m < R) ret = min(ret, query(L, R, m + 1, r, o->rson));
    return ret;
}

Node* merge(Node* u, Node* v)
{
    if (u == nullptr) return v;
    if (v == nullptr) return u;
    Node* o = &t[++tot];
    o->lson = merge(u->lson, v->lson);
    o->rson = merge(u->rson, v->rson);
    o->minv = min(u->minv, v->minv);
    return o;
}

int d[N], a[N];
vector<int> G[N];

void dfs(int u, int fa)
{
    d[u] = d[fa] + 1;
    update(d[u], a[u], 1, N, rt[u]);
    for (auto& v : G[u])
    {
        if (v == fa) continue;
        dfs(v, u);
        rt[u] = merge(rt[u], rt[v]);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, r;
    scanf("%d%d", &n, &r);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1, u, v; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        G[u].pb(v), G[v].pb(u);
    }
    dfs(r, 0);
    int q;
    scanf("%d", &q);
    while (q--)
    {
        static int p, q, x, k, last = 0;
        scanf("%d%d", &p, &q);
        x = (p + last) % n + 1, k = (q + last) % n;
        last = query(d[x], min(d[x] + k, N), 1, N, rt[x]);
        printf("%d\n", last);
    }
    return 0;
}