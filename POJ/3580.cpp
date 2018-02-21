#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1 << 18;
#define key_value ch[ch[root][1]][0]

struct Splay
{
    int a[maxn];
    int sz[maxn], ch[maxn][2], fa[maxn];
    int key[maxn], flip[maxn], addv[maxn], minv[maxn];
    int root, tot;
    int stk[maxn], top;

#ifndef ONLINE_JUDGE
    void Treavel(int x)
    {
        if (x)
        {
            Treavel(ch[x][0]);
            printf("结点:%2d: 左儿子 %2d 右儿子 %2d 父结点 %2d size= %2d key= %2d\n", x, ch[x][0], ch[x][1], fa[x], sz[x], key[x]);
            Treavel(ch[x][1]);
        }
    }

    void debug()
    {
        printf("root:%d\n", root);
        Treavel(root);
    }
#endif

    void init(int n)
    {
        tot = 0, top = 0;
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        root = newnode(0, -1);
        ch[root][1] = newnode(root, -1);
        key_value = build(0, n - 1, ch[root][1]);
    }

    int newnode(int p = 0, int k = 0)
    {
        int x = top ? stk[top--] : ++tot;
        fa[x] = p;
        sz[x] = 1;
        ch[x][0] = ch[x][1] = 0;
        key[x] = k, minv[x] = k;
        flip[x] = 0, addv[x] = 0;
        return x;
    }

    inline void add(int x, int v) { key[x] += v, addv[x] += v, minv[x] += v; }

    void pushdown(int x)
    {
        if (flip[x])
        {
            swap(ch[x][0], ch[x][1]);
            if (ch[x][0]) flip[ch[x][0]] ^= 1;
            if (ch[x][1]) flip[ch[x][1]] ^= 1;
            flip[x] ^= 1;
        }
        if (addv[x])
        {
            if (ch[x][0]) add(ch[x][0], addv[x]);
            if (ch[x][1]) add(ch[x][1], addv[x]);
            addv[x] = 0;
        }
    }

    void pushup(int x)
    {
        sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1;
        minv[x] = key[x];
        if (ch[x][0]) minv[x] = min(minv[x], minv[ch[x][0]]);
        if (ch[x][1]) minv[x] = min(minv[x], minv[ch[x][1]]);
    }

    void rotate(int x, int d)
    {
        int y = fa[x];
        pushdown(y), pushdown(x);
        ch[y][d ^ 1] = ch[x][d];
        fa[ch[x][d]] = y;
        if (fa[y]) ch[fa[y]][ch[fa[y]][1] == y] = x;
        fa[x] = fa[y];
        ch[x][d] = y;
        fa[y] = x;
        pushup(y);
    }

    void splay(int x, int goal = 0)
    {
        pushdown(x);
        while (fa[x] != goal)
        {
            if (fa[fa[x]] == goal)
                rotate(x, ch[fa[x]][0] == x);
            else
            {
                int y = fa[x];
                int d = ch[fa[y]][0] == y;
                ch[y][d] == x ? rotate(x, d ^ 1) : rotate(y, d);
                rotate(x, d);
            }
        }
        pushup(x);
        if (goal == 0) root = x;
    }

    int kth(int r, int k)
    {
        pushdown(r);
        int t = sz[ch[r][0]] + 1;
        if (t == k) return r;
        return t > k ? kth(ch[r][0], k) : kth(ch[r][1], k - t);
    }

    int build(int l, int r, int p)
    {
        if (l > r) return 0;
        int mid = l + r >> 1;
        int x = newnode(p, a[mid]);
        ch[x][0] = build(l, mid - 1, x);
        ch[x][1] = build(mid + 1, r, x);
        pushup(x);
        return x;
    }

    void select(int l, int r)
    {
        splay(kth(root, l));
        splay(kth(ch[root][1], r - l + 2), root);
    }

    void add(int l, int r, int v)
    {
        select(l, r);
        add(key_value, v);
        pushup(ch[root][1]);
        pushup(root);
    }

    void reverse(int l, int r)
    {
        select(l, r);
        flip[key_value] ^= 1;
    }

    void revolve(int l, int r, int c)
    {
        c %= (r - l + 1);
        if (c == 0) return;
        select(r - c + 1, r);
        int tmp = key_value;
        key_value = 0;
        pushup(ch[root][1]), pushup(root);
        select(l, l - 1);
        key_value = tmp, fa[tmp] = ch[root][1];
        pushup(ch[root][1]), pushup(root);
    }

    void insert(int x, int p)
    {
        select(x + 1, x);
        key_value = newnode(ch[root][1], p);
        pushup(ch[root][1]), pushup(root);
    }

    void erase(int x)
    {
        select(x, x);
        key_value = 0;
        pushup(ch[root][1]), pushup(root);
    }

    int query(int l, int r)
    {
        select(l, r);
        return minv[key_value];
    }
} gao;

int main()
{
    int n, m;
    char op[10];
    scanf("%d", &n);
    gao.init(n);
    scanf("%d", &m);
    while (m--)
    {
        scanf("%s", op);
        static int a, b, c;
        if (!strcmp(op, "ADD"))
        {
            scanf("%d%d%d", &a, &b, &c);
            gao.add(a, b, c);
        }
        if (!strcmp(op, "REVERSE"))
        {
            scanf("%d%d", &a, &b);
            gao.reverse(a, b);
        }
        if (!strcmp(op, "REVOLVE"))
        {
            scanf("%d%d%d", &a, &b, &c);
            gao.revolve(a, b, c);
        }
        if (!strcmp(op, "INSERT"))
        {
            scanf("%d%d", &a, &b);
            gao.insert(a, b);
        }
        if (!strcmp(op, "DELETE"))
        {
            scanf("%d", &a);
            gao.erase(a);
        }
        if (!strcmp(op, "MIN"))
        {
            scanf("%d%d", &a, &b);
            printf("%d\n", gao.query(a, b));
        }
    }
    return 0;
}