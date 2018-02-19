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
const int mod = 1e6;
const double eps = 1e-6;

#define key_value ch[ch[root][1]][0]
const int maxn = 1 << 17;

struct Splay
{
    int sz[maxn], ch[maxn][2], fa[maxn];
    int key[maxn];
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

    void init()
    {
        tot = 0, top = 0;
    }

    bool empty() const { return root == 0; }

    int newnode(int p = 0, int k = 0)
    {
        int x = top ? stk[top--] : ++tot;
        fa[x] = p;
        sz[x] = 1;
        ch[x][0] = ch[x][1] = 0;
        key[x] = k;
        return x;
    }

    void pushdown(int x)
    {
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

    int min(int x)
    {
        pushdown(x);
        while (ch[x][0])
        {
            x = ch[x][0];
            pushdown(x);
        }
        return x;
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

    void insert(int x)
    {
        if (root == 0)
        {
            root = newnode(0, x);
            return;
        }
        int rt = root, p = 0;
        while (rt)
        {
            p = rt;
            rt = ch[rt][key[rt] < x];
        }
        ch[p][key[p] < x] = newnode(p, x);
        pushup(p);
        splay(ch[p][key[p] < x]);
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

    int query(int x)
    {
        insert(x);
        int lower_bound = max(ch[root][0]), upper_bound = min(ch[root][1]);
        ll lower = key[lower_bound], upper = key[upper_bound];
        erase(root);
        if (lower_bound == 0)
        {
            erase(upper_bound);
            return (upper - x) % mod;
        }
        if (upper_bound == 0)
        {
            erase(lower_bound);
            return (x - lower) % mod;
        }
        if (upper - x < x - lower)
        {
            erase(upper_bound);
            return (upper - x) % mod;
        }
        else
        {
            erase(lower_bound);
            return (x - lower) % mod;
        }
    }

} gao;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (~scanf("%d", &n))
    {
        int ans = 0;
        gao.init();
        int last = -1;
        while (n--)
        {
            static int op, x;
            scanf("%d%d", &op, &x);
            if (gao.empty() || op == last)
                gao.insert(x), last = op;
            else
                (ans += gao.query(x)) %= mod;
        }
        printf("%d\n", ans);
    }
    return 0;
}