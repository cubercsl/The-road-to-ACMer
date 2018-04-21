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

const int N = 1 << 15;
vector<int> G[N];
int v[N], rt[N];
vector<int> y[N];
bool vis[N];
int dfn, tot;

inline void init()
{
    for (int i = 2; i < N; i++)
    {
        if (!vis[i])
            for (int j = i + i; j < N; j += i)
                vis[j] = 1;
        else
            for (int j = i; j < N; j += i)
                y[j].push_back(i);
    }
}
struct Node
{
    int l, r, cnt;
} t[N << 6];

void update(int& x, int p, int l, int r)
{
    t[++tot] = t[x], x = tot;
    if (l == r)
    {
        t[x].cnt++;
        return;
    }
    int mid = l + r >> 1;
    if (p <= mid)
        update(t[x].l, p, l, mid);
    else
        update(t[x].r, p, mid + 1, r);
}

int query(int x, int p, int l, int r)
{
    if (!x) return 0;
    if (l == r) return t[x].cnt;
    int mid = l + r >> 1;
    if (p <= mid)
        return query(t[x].l, p, l, mid);
    else
        return query(t[x].r, p, mid + 1, r);
}

int L[N], R[N];
void dfs(int u, int fa)
{
    L[u] = ++dfn;
    rt[dfn] = rt[dfn - 1];
    update(rt[dfn], v[u], 1, 10000);
    for (auto& v : G[u])
        if (v != fa) dfs(v, u);
    R[u] = dfn;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    init();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, p;
        scanf("%d%d", &n, &p);
        for (int i = 1; i <= n; i++) vector<int>().swap(G[i]);
        for (int i = 1; i < n; i++)
        {
            static int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v), G[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
        dfn = tot = 0;
        dfs(p, -1);
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ll tmp = 0;
            for (auto& c : y[v[i]])
                tmp += query(rt[R[i]], c, 1, 10000) - query(rt[L[i] - 1], c, 1, 10000);
            (ans += tmp * i) %= mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}