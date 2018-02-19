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

#define key_value ch[ch[root][1]][0]
const int maxn = 1 << 18;

struct Splay
{
    int a[maxn];
    PII b[maxn];
    int sz[maxn], ch[maxn][2], key[maxn], flip[maxn], fa[maxn];
    int root, tot;
    int stk[maxn], top;
    int id[maxn];

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
        for (int i = 0; i < n; i++) scanf("%d", &b[i].X), b[i].Y = i;
        sort(b, b + n);
        for (int i = 0; i < n; i++) a[b[i].Y] = i;
        root = build(0, n - 1, 0);
    }

    int newnode(int p = 0, int k = 0)
    {
        int x = top ? stk[top--] : ++tot;
        fa[x] = p;
        sz[x] = 1;
        ch[x][0] = ch[x][1] = 0;
        key[x] = k;
        flip[x] = 0;
        id[k] = x;
        return x;
    }

    void update(int x)
    {
        if (!x) return;
        swap(ch[x][0], ch[x][1]);
        flip[x] ^= 1;
    }

    void pushdown(int x)
    {
        if (flip[x])
        {
            update(ch[x][0]), update(ch[x][1]);
            flip[x] ^= 1;
        }
    }

    void pushup(int x)
    {
        sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1;
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
        pushup(y), pushup(x);
    }

    void splay(int x, int goal = 0)
    {
        pushdown(x);
        while (fa[x] != goal)
        {
            if (fa[fa[x]] == goal)
            {
                pushdown(fa[x]), pushdown(x);
                rotate(x, ch[fa[x]][0] == x);
            }
            else
            {
                int y = fa[x];
                pushdown(fa[y]), pushdown(y), pushdown(x);
                int d = ch[fa[y]][0] == y;
                ch[y][d] == x ? rotate(x, d ^ 1) : rotate(y, d);
                rotate(x, d);
            }
        }
        pushup(x);
        if (goal == 0) root = x;
    }

    int max(int x)
    {
        pushdown(x);
        while (ch[x][1])
        {
            x = ch[x][1];
            pushdown(x);
        }
        return x;
    }

    void erase(int x)
    {
        splay(x);
        stk[++top] = root;
        if (!ch[root][0] && !ch[root][1])
        {
            root = 0;
            return;
        }
        if (!ch[root][0])
        {
            root = ch[root][1];
            fa[root] = 0;
            pushup(root);
            return;
        }
        if (!ch[root][1])
        {
            root = ch[root][0];
            fa[root] = 0;
            pushup(root);
            return;
        }
        int tmp = max(ch[root][0]);
        splay(tmp, root);
        fa[ch[root][1]] = tmp;
        ch[tmp][1] = ch[root][1];
        root = tmp;
        fa[root] = 0;
        pushup(root);
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

    int change(int x)
    {
        splay(id[x]);
        int ret = sz[ch[root][0]] + 1;
        update(ch[root][0]);
        erase(root);
        return ret + x;
    }

} gao;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (~scanf("%d", &n) && n)
    {
        gao.init(n);
        for (int i = 0; i < n; i++) printf("%d%c", gao.change(i), " \n"[i == n - 1]);
    }
    return 0;
}