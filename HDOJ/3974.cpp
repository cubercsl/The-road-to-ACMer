// Assign the task, HDU3974

/*Sample Input
1 
5 
4 3 
3 2 
1 3 
5 2 
5 
C 3 
T 2 1
C 3
T 3 2 
C 3
*/

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
const int maxn = 50005;
vector <int> G[maxn];
int deg[maxn];
int L[maxn], R[maxn];
int val[maxn << 2];
int dfs_clock;

void init(int n)
{
    dfs_clock = 0;
    clr(deg, 0);
    for (int i = 1; i <= n; i++)
        G[i].clear();
}

void add_edge(int u, int v)
{
    G[v].pb(u);
    deg[u]++;
}

void dfs(int u)
{
    L[u] = ++dfs_clock;
    for (int i = 0; i < G[u].size(); i++)
        dfs(G[u][i]);
    R[u] = dfs_clock;
}

void build(int l, int r, int rt)
{
    val[rt] = -1;
    if (l == r) return;
    int m = (l + r) >> 1;
    build(Lson);
    build(Rson);
}

void PushDown(int rt)
{
    if (val[rt] == -1) return;
    val[lson] = val[rson] = val[rt];
    val[rt] = -1;
}

void update(int L, int R, int setv, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        val[rt] = setv;
        return;
    }
    PushDown(rt);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, setv, Lson);
    if (m < R) update(L, R, setv, Rson);
}

int query(int p, int l, int r, int rt)
{
    if (l == r) return val[rt];
    PushDown(rt);
    int m = (l + r) >> 1;
    if (p <= m) return query(p, Lson);
    if (m < p) return query(p, Rson);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int t, kase = 0;
    scanf("%d", &t);
    while (t--)
    {
        int n, m, x, y;
        char c[5];
        scanf("%d", &n);
        init(n);
        for (int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            add_edge(u, v);
        }
        for (int i = 1; i <= n; i++)
            if (deg[i] == 0)
            {
                dfs(i);
                break;
            }
        int N = dfs_clock;
        build(1, N, 1);
        scanf("%d", &m);
        printf("Case #%d:\n", ++kase);
        while (m--)
        {
            scanf("%s", c);
            if (c[0] == 'T')
            {
                scanf("%d%d", &x, &y);
                update(L[x], R[x], y, 1, N, 1);
            }
            else
            {
                scanf("%d", &x);
                printf("%d\n", query(L[x], 1, N, 1));
            }
        }
    }
    return 0;
}
