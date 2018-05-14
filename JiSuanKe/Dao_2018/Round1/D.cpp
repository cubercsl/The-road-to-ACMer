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
vector<int> G[N << 5];

int val[N << 5], lson[N << 5], rson[N << 5];
int sz;
int id[N];

void build(int l, int r, int& o)
{
    o = ++sz;
    if (l == r)
    {
        id[l] = o;
        cin >> val[o];
        return;
    }
    int m = l + r >> 1;
    build(l, m, lson[o]), G[o].push_back(lson[o]);
    build(m + 1, r, rson[o]), G[o].push_back(rson[o]);
}

void update(int p, int v, int l, int r, int& o, int k)
{
    o = ++sz;
    val[o] = val[k], lson[o] = lson[k], rson[o] = rson[k];
    if (l == r)
    {
        id[l] = o;
        val[o] = v;
        return;
    }
    int m = l + r >> 1;
    if (p <= m)
        update(p, v, l, m, lson[o], lson[k]);
    else
        update(p, v, m + 1, r, rson[o], rson[k]);
    G[o].push_back(lson[o]), G[o].push_back(rson[o]);
}

void query(int p, int L, int R, int l, int r, int o)
{
    if (L <= l && r <= R)
    {
        G[p].push_back(o);
        return;
    }
    int m = l + r >> 1;
    if (L <= m) query(p, L, R, l, m, lson[o]);
    if (m < R) query(p, L, R, m + 1, r, rson[o]);
}

int pre[N << 5], lowlink[N << 5], sccno[N << 5], dfs_clock, scc_cnt;
stack<int> S;
void dfs(int u)
{
    pre[u] = lowlink[u] = ++dfs_clock;
    S.push(u);
    for (auto& v : G[u])
    {
        if (!pre[v])
        {
            dfs(v);
            lowlink[u] = min(lowlink[u], lowlink[v]);
        }
        else if (!sccno[v])
            lowlink[u] = min(lowlink[u], pre[v]);
    }
    if (lowlink[u] == pre[u])
    {
        scc_cnt++;
        for (;;)
        {
            int x = S.top();
            S.pop();
            sccno[x] = scc_cnt;
            if (x == u) break;
        }
    }
}
void find_scc(int n)
{
    dfs_clock = 0, scc_cnt = 0;
    clr(sccno, 0), clr(pre, 0);
    for (int i = 1; i <= n; i++)
        if (!pre[i]) dfs(i);
}

ll f[N << 5];

void debug()
{
    for (int u = 1; u <= sz; u++) {
        for (auto& v : G[u])
            cerr << "(" << u << "," << v << ")";
        cerr << endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin int n, m, rt;
    cin >> n;
    build(1, n, rt);
    cin >> m;
    while (m--)
    {
        static int op;
        cin >> op;
        if (op == 1)
        {
            static int x, l, r;
            cin >> x >> l >> r;
            query(id[x], l, r, 1, n, rt);
        }
        else
        {
            static int x, y;
            cin >> x >> y;
            update(x, y, 1, n, rt, rt);
        }
    }
    // debug();
    find_scc(sz);
    for (int i = 1; i <= sz; i++) f[sccno[i]] += val[i];
    for (int u = 1; u <= sz; u++)
        for (auto& v : G[u])
            if (sccno[u] != sccno[v]) f[sccno[u]] = 1e18;
    ll ans = 1e18;
    for (int i = 1; i <= scc_cnt; i++)
        ans = min(ans, f[i]);
    cout << ans << endl;
    return 0;
}