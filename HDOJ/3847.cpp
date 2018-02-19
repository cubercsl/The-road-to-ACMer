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
    int sz[maxn], ch[maxn][2], fa[maxn];
    int key[maxn], rev[maxn];
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
        root = newnode(0, -1);
        ch[root][1] = newnode(root, -1);
        for (int i = 0; i < n; i++) a[i] = i + 1;
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
        rev[x] = 0;
        return x;
    }

    void pushdown(int x)
    {
        if (rev[x])
        {
            swap(ch[x][0], ch[x][1]);
            if (ch[x][0]) rev[ch[x][0]] ^= 1;
            if (ch[x][1]) rev[ch[x][1]] ^= 1;
            rev[x] = 0;
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
        splay(kth(root, l), 0);
        splay(kth(ch[root][1], r - l + 2), root);
    }

    void filp(int l, int r)
    {
        select(l, r);
        rev[key_value] ^= 1;
    }

    void cut(int l, int r, int c)
    {
        select(l, r);
        int tmp = key_value;
        key_value = 0;
        pushup(ch[root][1]), pushup(root);
        select(c + 1, c);
        key_value = tmp, fa[key_value] = ch[root][1];
        pushup(ch[root][1]), pushup(root);
        splay(tmp);
    }

    int ans[maxn], pos;

    void dfs(int x)
    {
        if (x)
        {
            pushdown(x);
            dfs(ch[x][0]);
            if (~key[x]) ans[pos++] = key[x];
            dfs(ch[x][1]);
        }
    }

    void print()
    {
        pos = 0;
        dfs(root);
        for (int i = 0; i < pos; i++) printf("%d%c", ans[i], " \n"[i == pos - 1]);
    }
} gao;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    char op[10];
    int a, b, c;
    while (~scanf("%d%d", &n, &m) && ~n)
    {
        gao.init(n);
        while (m--)
        {
            scanf("%s", op);
            if (op[0] == 'C')
            {
                scanf("%d%d%d", &a, &b, &c);
                gao.cut(a, b, c);
            }
            else
            {
                scanf("%d%d", &a, &b);
                gao.filp(a, b);
            }
        }
        gao.print();
    }
    return 0;
}