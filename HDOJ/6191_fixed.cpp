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
struct Trie
{
    int sz[N << 5], ch[N << 5][2], tot;
    int rt[N];
    void init()
    {
        tot = 0;
        clr(rt, 0);
        rt[0] = newNode();
    }
    int newNode()
    {
        clr(ch[tot], 0);
        sz[tot] = 0;
        return tot++;
    }
    void insert(int val, int x, int y)
    {
        rt[x] = newNode();
        int u = rt[x], v = rt[y];
        for (int i = 30; ~i; i--)
        {
            int d = val >> i & 1;
            sz[u] = sz[v] + 1;
            ch[u][d] = newNode();
            ch[u][d ^ 1] = ch[v][d ^ 1];
            u = ch[u][d], v = ch[v][d];
        }
        sz[u] = sz[v] + 1;
    }
    int query(int val, int x, int y)
    {
        int u = rt[x], v = rt[y];
        int ans = 0;
        for (int i = 30; ~i; i--)
        {
            int d = val >> i & 1;
            int t = sz[ch[v][d ^ 1]] - sz[ch[u][d ^ 1]];
            if (t > 0) d ^= 1;
            ans |= d << i;
            u = ch[u][d], v = ch[v][d];
        }
        return ans;
    }
} trie;

int val[N];
vector<int> G[N];
int in[N], out[N], dfn;

void dfs(int u)
{
    trie.insert(val[u], dfn + 1, dfn);
    in[u] = ++dfn;
    for (auto& v : G[u]) dfs(v);
    out[u] = dfn;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, q;
    while (~scanf("%d%d", &n, &q))
    {
        trie.init(), dfn = 0;
        for (int i = 1; i <= n; i++)
        {
            G[i].clear();
            scanf("%d", val + i);
        }
        for (int i = 2, v; i <= n; i++)
        {
            scanf("%d", &v);
            G[v].push_back(i);
        }
        dfs(1);
        while (q--)
        {
            static int u, x;
            scanf("%d%d", &u, &x);
            printf("%d\n", x ^ trie.query(x, in[u] - 1, out[u]));
        }
    }
    return 0;
}