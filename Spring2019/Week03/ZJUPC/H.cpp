#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define dbg(args...)                             \
    do                                           \
    {                                            \
        cout << "\033[32;1m" << #args << " -> "; \
        err(args);                               \
    } while (0)
#else
#define dbg(...)
#endif
void err()
{
    cout << "\033[39;0m" << endl;
}
template <template <typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args)
{
    for (auto x : a) cout << x << ' ';
    err(args...);
}
template <typename T, typename... Args>
void err(T a, Args... args)
{
    cout << a << ' ';
    err(args...);
}
/****************************************************************************************************/

const int maxn = 1 << 17;
struct BCC
{
    vector<int> G[maxn];
    int pre[maxn], lowlink[maxn], sccno[maxn], dfs_clock, scc_cnt;
    stack<int> S;
    inline void init(int n)
    {
        for (int i = 0; i < n; i++) G[i].clear();
    }
    inline void add_edge(int u, int v) { G[u].push_back(v); }
    void dfs(int u, int fa)
    {
        pre[u] = lowlink[u] = ++dfs_clock;
        S.push(u);
        int k = 0;
        for (auto& v : G[u])
        {
            if (v == fa && !k)
            {
                k++;
                continue;
            }
            if (!pre[v])
            {
                dfs(v, u);
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
        memset(sccno, 0, sizeof(int) * n);
        memset(pre, 0, sizeof(int) * n);
        for (int i = 0; i < n; i++)
            if (!pre[i]) dfs(i, -1);
    }
} bcc;

struct LCT
{
    int val[maxn], sum[maxn]; // 基于点权
    int rev[maxn], ch[maxn][2], fa[maxn];
    int stk[maxn];
    inline void init(int n)
    {
        for (int i = 1; i <= n; i++)
            fa[i] = ch[i][0] = ch[i][1] = rev[i] = 0;
    }
    inline bool isroot(int x) { return ch[fa[x]][0] != x && ch[fa[x]][1] != x; }
    inline bool get(int x) { return ch[fa[x]][1] == x; }
    void pushdown(int x)
    {
        if (!rev[x]) return;
        swap(ch[x][0], ch[x][1]);
        if (ch[x][0]) rev[ch[x][0]] ^= 1;
        if (ch[x][1]) rev[ch[x][1]] ^= 1;
        rev[x] ^= 1;
    }
    void pushup(int x) { sum[x] = val[x] + sum[ch[x][0]] + sum[ch[x][1]]; }
    void rotate(int x)
    {
        int y = fa[x], z = fa[fa[x]], d = get(x);
        if (!isroot(y)) ch[z][get(y)] = x;
        fa[x] = z;
        ch[y][d] = ch[x][d ^ 1], fa[ch[y][d]] = y;
        ch[x][d ^ 1] = y, fa[y] = x;
        pushup(y), pushup(x);
    }
    void splay(int x)
    {
        int top = 0;
        stk[++top] = x;
        for (int i = x; !isroot(i); i = fa[i]) stk[++top] = fa[i];
        for (int i = top; i; i--) pushdown(stk[i]);
        for (int f; !isroot(x); rotate(x))
            if (!isroot(f = fa[x])) rotate(get(x) == get(f) ? f : x);
    }
    void access(int x)
    {
        for (int y = 0; x; y = x, x = fa[x]) splay(x), ch[x][1] = y, pushup(x);
    }
    int find(int x)
    {
        access(x), splay(x);
        while (ch[x][0]) x = ch[x][0];
        return x;
    }
    void makeroot(int x) { access(x), splay(x), rev[x] ^= 1; }
    void link(int x, int y) { makeroot(x), fa[x] = y, splay(x); }
    void cut(int x, int y) { makeroot(x), access(y), splay(y), fa[x] = ch[y][0] = 0; }
    void update(int x, int v) { val[x] = v, access(x), splay(x); }
    int query(int x, int y)
    {
        makeroot(y), access(x), splay(x);
        return sum[x];
    }
} lct;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m, q;
        scanf("%d%d%d", &n, &m, &q);
        bcc.init(n);
        for (int i = 0, u, v; i < m; i++)
        {
            scanf("%d%d", &u, &v);
            --u, --v;
            bcc.add_edge(u, v);
            bcc.add_edge(v, u);
        }
        bcc.find_scc(n);
        int sz = bcc.scc_cnt;
        lct.init(sz);
        for (int u = 0; u < n; u++)
            for (auto& v : bcc.G[u])
            {
                int x = bcc.sccno[u];
                int y = bcc.sccno[v];
                if (x == y) continue;
                if (lct.find(x) == lct.find(y)) continue;
                lct.link(x, y);
            }
        for (int i = 0, u, v, w; i < q; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            --u, --v, --w;
            int x = bcc.sccno[u], y = bcc.sccno[v], z = bcc.sccno[w];
            int rx = lct.find(x), ry = lct.find(y), rz = lct.find(z);
            if (rx == ry && ry == rz)
            {
                lct.update(x, 1);
                puts(lct.query(y, z) ? "Yes" : "No");
                lct.update(x, 0);
            }
            else
                puts("No");
        }
    }
    return 0;
}
/*
4
6 7 4
1 2
2 3
3 1
4 5
5 6
6 4
1 4
4 1 3
1 4 2
1 2 3
1 3 3
2 1 2
1 2
1 1 1
2 1 2
4 5 4
1 2
1 2
2 3
2 3
3 4
1 2 3
1 3 4
1 2 2
1 4 4
8 7 3
1 2
1 2
2 4
1 3
5 6
5 7
7 8
1 2 4
1 2 3
1 3 7
*/
