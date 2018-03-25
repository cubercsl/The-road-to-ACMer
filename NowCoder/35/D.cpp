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
 
const int N = 2e5 + 5;
vector<PII> G[N];
int L[N], R[N], c[N], dfn;
ll cnt[N], dist[N], d[N];
 
inline void add(int pos, ll val, ll* T)
{
    for (int i = pos; i < N; i += i & -i)
        T[i] += val;
}
 
inline ll sum(int pos, ll* T)
{
    ll ret = 0;
    for (int i = pos; i; i -= i & -i)
        ret += T[i];
    return ret;
}
 
void dfs(int u)
{
    L[u] = ++dfn;
    c[L[u]] = u;
    for (auto e : G[u])
    {
        int v = e.X, w = e.Y;
        d[v] = d[u] + w;
        dfs(v);
    }
    R[u] = dfn;
}
 
const int M = 1e6 + 5;
 
struct query
{
    int x, k, id;
    query() {}
    query(int _x, int _k, int _id) : x(_x), k(_k), id(_id) {}
} Q[M];
 
typedef pair<ll, int> Node;
ll ans[M];
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        static int p, w;
        scanf("%d%d", &p, &w);
        G[p].pb(mp(i, w));
    }
    dfs(1);
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        static int x, k;
        scanf("%d%d", &x, &k);
        Q[i] = query(x, k, i);
    }
    priority_queue<Node> que;
    for (int i = 1; i <= n; i++) que.push(mp(d[i], i));
    sort(Q, Q + q, [](query a, query b) {
        return d[a.x] + a.k > d[b.x] + b.k;
    });
    for (int i = 0; i < q; i++)
    {
        int x = Q[i].x, k = Q[i].k, id = Q[i].id;
        if (!que.empty())
        {
            Node tmp = que.top();
            while (tmp.X >= d[x] + k)
            {
                int pos = tmp.Y;
                que.pop();
                add(L[pos], d[pos], dist);
                add(L[pos], 1, cnt);
                if (que.empty()) break;
                tmp = que.top();
            }
        }
        ans[id] = sum(R[x], dist) - sum(L[x], dist) -(sum(R[x], cnt) - sum(L[x], cnt)) * d[x];
    }
    for (int i = 0; i < q; i++)
        printf("%lld\n", ans[i]);
    return 0;
}