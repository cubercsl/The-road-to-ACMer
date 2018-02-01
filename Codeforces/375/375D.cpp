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
const int maxn = 1 << 17;

int col[maxn], seg[maxn];
vector<int> G[maxn];
int L[maxn], R[maxn];
int dfs_clock;
inline void init(int n)
{
    for (int i = 0; i <= n; i++) G[i].clear();
    dfs_clock = 0;
}
inline void addedge(int u, int v)
{
    G[u].pb(v);
    G[v].pb(u);
}
void dfs(int u, int fa)
{
    L[u] = ++dfs_clock;
    seg[dfs_clock] = col[u];
    for (auto& v : G[u])
        if (v != fa)
            dfs(v, u);
    R[u] = dfs_clock;
}
struct node
{
    int l, r, k, id;
} q[maxn];
int tot[maxn];
int num[maxn];
inline void add(int x) { tot[++num[x]]++; }
inline void del(int x) { tot[num[x]--]--; }
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        clr(tot, 0);
        clr(num, 0);
        init(n);
        int unit = sqrt(n);
        static int u, v;
        for (int i = 1; i <= n; i++)
            scanf("%d", &col[i]);
        for (int i = 1; i < n; i++)
        {
            scanf("%d%d", &u, &v);
            addedge(u, v);
        }
        dfs(1, -1);
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &u, &v);
            q[i].l = L[u], q[i].r = R[u], q[i].k = v, q[i].id = i;
        }
        sort(q, q + m, [&unit](node a, node b) { return a.l / unit < b.l / unit || (a.l / unit == b.l / unit && a.r < b.r); });
        int ans[maxn];
        int L = 1, R = 0;
        for (int i = 0; i < m; i++)
        {
            int l = q[i].l, r = q[i].r;
            while (l < L) add(seg[--L]);
            while (l > L) del(seg[L++]);
            while (r < R) del(seg[R--]);
            while (r > R) add(seg[++R]);
            ans[q[i].id] = tot[q[i].k];
        }
        for (int i = 0; i < m; i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}
