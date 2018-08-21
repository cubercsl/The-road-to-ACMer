#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 1 << 17;
struct Trie
{
    int ch[N << 5][2], sz[N << 5];
    int tot;
    int root[N];
    int newNode()
    {
        memset(ch[tot], 0, sizeof(ch[tot])), sz[tot] = 0;
        return tot++;
    }
    void init()
    {
        tot = 0;
        newNode();
    }
    void insert(int x, int p, int q)
    {
        root[p] = newNode();
        int u = root[p], v = root[q];
        for (int i = 30; ~i; i--)
        {
            int d = x >> i & 1;
            ch[u][d] = newNode();
            sz[u] = sz[v] + 1;
            ch[u][d ^ 1] = ch[v][d ^ 1];
            u = ch[u][d], v = ch[v][d];
        }
        sz[u] = sz[v] + 1;
    }
    int query(int x, int p, int q, int r, int s)
    {
        int ans = 0;
        int u = root[p], v = root[q], w = root[r], ww = root[s];
        for (int i = 30; ~i; i--)
        {
            int d = x >> i & 1;
            if (sz[ch[u][d ^ 1]] + sz[ch[v][d ^ 1]] - sz[ch[w][d ^ 1]] - sz[ch[ww][d ^ 1]]) d ^= 1;
            ans |= d << i;
            u = ch[u][d], v = ch[v][d], w = ch[w][d], ww = ch[ww][d];
        }
        return ans;
    }

} trie;

struct Tree
{
    vector<int> G[N], sp;
    int dfn[N], fa[N];
    int val[N];
    PII dp[21][N << 1];
    void init(int n)
    {
        for (int i = 0; i <= n; i++) vector<int>().swap(G[i]);
        for (int i = 1; i <= n; i++) scanf("%d", val + i);
        sp.clear();
    }
    void add_edge(int u, int v) { G[u].push_back(v), G[v].push_back(u); }
    void dfs(int u, int f)
    {
        fa[u] = f;
        dfn[u] = sp.size();
        trie.insert(val[u], u, f);
        sp.push_back(u);
        for (auto& v : G[u])
        {
            if (v != f)
            {
                dfs(v, u);
                sp.push_back(u);
            }
        }
    }
    void initrmq()
    {
        int n = sp.size();
        for (int i = 0; i < n; i++) dp[0][i] = {dfn[sp[i]], sp[i]};
        for (int i = 1; (1 << i) <= n; i++)
            for (int j = 0; j + (1 << i) - 1 < n; j++)
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);
    }
    int lca(int u, int v)
    {
        int l = dfn[u], r = dfn[v];
        if (l > r) swap(l, r);
        int k = 31 - __builtin_clz(r - l + 1);
        return min(dp[k][l], dp[k][r - (1 << k) + 1]).second;
    }
    int query(int u, int v, int x)
    {
        int w = lca(u, v);
        return trie.query(x, u, v, w, fa[w]);
    }
} gao;

int main()
{

    int n, q;
    while (~scanf("%d%d", &n, &q))
    {
        gao.init(n);
        trie.init();
        for (int i = 1, u, v; i < n; i++)
        {
            scanf("%d%d", &u, &v);
            gao.add_edge(u, v);
        }
        gao.dfs(1, 0);
        gao.initrmq();
        while (q--)
        {
            static int u, v, x;
            scanf("%d%d%d", &u, &v, &x);
            printf("%d\n", gao.query(u, v, x) ^ x);
        }
    }
    return 0;
}