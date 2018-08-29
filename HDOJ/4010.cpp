#include <bits/stdc++.h>
using namespace std;

const int maxn = 1 << 19;
struct LCT
{
    int val[maxn], maxv[maxn], tag[maxn]; // 基于点权
    int rev[maxn], ch[maxn][2], fa[maxn];
    int stk[maxn];
    inline void init(int n)
    { // 初始化点权
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", val + i);
            ch[i][0] = ch[i][1] = 0;
            maxv[i] = 0, fa[i] = 0, rev[i] = 0;
        }
    }
    inline bool isroot(int x) { return ch[fa[x]][0] != x && ch[fa[x]][1] != x; }
    inline bool get(int x) { return ch[fa[x]][1] == x; }
    void pushdown(int x)
    {
        if (rev[x])
        {
            swap(ch[x][0], ch[x][1]);
            if (ch[x][0]) rev[ch[x][0]] ^= 1;
            if (ch[x][1]) rev[ch[x][1]] ^= 1;
            rev[x] ^= 1;
        }
        if (tag[x])
        {
            if (ch[x][0]) tag[ch[x][0]] += tag[x], val[ch[x][0]] += tag[x], maxv[ch[x][0]] += tag[x];
            if (ch[x][1]) tag[ch[x][1]] += tag[x], val[ch[x][1]] += tag[x], maxv[ch[x][1]] += tag[x];
            tag[x] = 0;
        }
    }
    void pushup(int x)
    {
        maxv[x] = max({val[x], maxv[ch[x][0]], maxv[ch[x][1]]});
    }
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
    void update(int x, int y, int v)
    {
        makeroot(y), access(x), splay(x);
        tag[x] += v, val[x] += v, maxv[x] += v;
    }
    int query(int x, int y)
    {
        makeroot(y), access(x), splay(x);
        return maxv[x];
    }
    void cut_fa(int x, int y)
    {
        makeroot(x), access(y), splay(y);
        ch[y][0] = fa[ch[y][0]] = 0;
        pushup(y);
    }
} lct;

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        vector<pair<int, int>> edges;
        for (int i = 1, u, v; i < n; i++)
        {
            scanf("%d%d", &u, &v);
            edges.emplace_back(u, v);
        }
        lct.init(n);
        for (auto& e : edges) lct.link(e.first, e.second);
        int q;
        scanf("%d", &q);
        while (q--)
        {
            static int op, x, y, w;
            scanf("%d", &op);
            if (op == 1)
            {
                scanf("%d%d", &x, &y);
                if (lct.find(x) == lct.find(y))
                    puts("-1");
                else
                    lct.link(x, y);
            }
            else if (op == 2)
            {
                scanf("%d%d", &x, &y);
                if (x == y || lct.find(x) != lct.find(y))
                    puts("-1");
                else
                    lct.cut_fa(x, y);
            }
            else if (op == 3)
            {
                scanf("%d%d%d", &w, &x, &y);
                if (lct.find(x) != lct.find(y))
                    puts("-1");
                else
                    lct.update(x, y, w);
            }
            else
            {
                scanf("%d%d", &x, &y);
                if (lct.find(x) != lct.find(y))
                    puts("-1");
                else
                    printf("%d\n", lct.query(x, y));
            }
        }
        puts("");
    }
}