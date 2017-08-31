// Query on A Tree, HDU6191

/*Sample Input
2 2
1 2
1
1 3
2 1
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

// Graph
const int maxn = 1e5 + 5;
vector <int> G[maxn];
int TL[maxn], TR[maxn], a[maxn], dfn;

void init(int n)
{
    for (int i = 1; i <= n; i++)
        G[i].clear();
    dfn = 0;
}

void dfs(int u)
{
    TL[u] = ++dfn;
    for (auto& v : G[u])
        dfs(v);
    TR[u] = dfn;
}

// Trie
int ch[maxn * 32][2];
int val[maxn * 32];
int num[maxn * 32];
int sz;
void initTrie()
{
    sz = 1;
    clr(ch[0], 0);
    clr(val, 0);
    clr(num, 0);
}

void insert(const int x)
{
    int u = 0;
    for (int i = 31; i >= 0; i--)
    {
        int c = (x >> i) & 1;
        if (!ch[u][c])
        {
            clr(ch[sz], 0);
            ch[u][c] = sz++;
            val[sz] = 0;
            num[sz] = 0;
        }
        u = ch[u][c];
        num[u]++;
    }
    val[u] = x;
}

int find(const int x)
{
    int u = 0;
    for (int i = 31; i >= 0; i--)
    {
        int c = (x >> i) & 1;
        if (ch[u][c ^ 1] && num[ch[u][c ^ 1]])
            c ^= 1;
        u = ch[u][c];
    }
    return val[u];
}

void del(const int x)
{
    int u = 0;
    for (int i = 31; i >= 0; i--)
    {
        int c = (x >> i) & 1;
        if (!ch[u][c])
            return;
        u = ch[u][c];
        num[u]--;
    }
}

// Mo
int q, ans[maxn];
double unit;

struct query
{
    int L, R, X, id;
    query() {}
    query(int l, int r, int x, int i): L(l), R(r), X(x), id(i) {}
} node[maxn];

bool cmp(query a, query b)
{
    if (a.L / unit != b.L / unit)
        return a.L / unit < b.L / unit;
    else
        return a.R < b.R;
}

void solve()
{
    initTrie();
    int tmp;
    int L = 1;
    int R = 0;
    for (int i = 0; i < q; i++)
    {
        while (node[i].L < L) insert(a[--L]);
        while (node[i].L > L) del(a[L++]);
        while (node[i].R < R) del(a[R--]);
        while (node[i].R > R) insert(a[++R]);
        tmp = find(node[i].X);
        ans[node[i].id] = tmp ^ node[i].X;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
#endif
    int n;
    while (~scanf("%d%d", &n, &q))
    {
        init(n);
        int t[maxn];
        for (int i = 1; i <= n; i++)
            scanf("%d", t + i);
        for (int i = 2; i <= n; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            G[tmp].pb(i);
        }
        dfs(1);
        for (int i = 1; i <= n; i++)
            a[TL[i]] = t[i];
        unit = sqrt(n);
        for (int i = 0; i < q; i++)
        {
            int u, x;
            scanf("%d%d", &u, &x);
            node[i] = query(TL[u], TR[u], x, i);
        }
        sort(node, node + q, cmp);
        solve();
        for (int i = 0; i < q; i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}
