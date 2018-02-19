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
    int sz[maxn], ch[maxn][2], key[maxn], maxv[maxn], fa[maxn];
    int root, tot;
    int stk[maxn], top;

#ifndef ONLINE_JUDGE
    void Treavel(int x)
    {
        if (x)
        {
            Treavel(ch[x][0]);
            printf("结点:%2d: 左儿子 %2d 右儿子 %2d 父结点 %2d size= %2d\n", x, ch[x][0], ch[x][1], fa[x], sz[x]);
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
        tot = 1, top = 0;
        root = newnode(0, -1);
        ch[root][1] = newnode(root, -1);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        key_value = build(0, n - 1, ch[root][1]);
        pushup(ch[root][1]);
        pushup(root);
    }

    int newnode(int p = 0, int k = 0)
    {
        int x = top ? stk[top--] : ++tot;
        fa[x] = p;
        sz[x] = 1;
        ch[x][0] = ch[x][1] = 0;
        key[x] = k;
        maxv[x] = k;
        return x;
    }

    void pushdown(int x)
    {
    }

    void pushup(int x)
    {
        sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1;
        maxv[x] = max(key[x], max(maxv[ch[x][0]], maxv[ch[x][1]]));
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

    int select(int l, int r)
    {
        splay(kth(root, l), 0);
        splay(kth(ch[root][1], r - l + 2), root);
    }

    int query(int l, int r)
    {
        select(l, r);
        return maxv[key_value];
    }

    void change(int p, int v)
    {
        splay(kth(root, p + 1));
        key[root] = v;
    }

} gao;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        gao.init(n);
        while (m--)
        {
            static char op[5];
            static int a, b;
            scanf("%s%d%d", op, &a, &b);
            if (op[0] == 'Q')
                printf("%d\n", gao.query(a, b));
            else
                gao.change(a, b);
        }
    }
    return 0;
}