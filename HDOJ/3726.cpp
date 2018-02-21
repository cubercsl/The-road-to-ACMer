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

const int maxn = 1 << 15;
#define key_value ch[ch[root][1]][0]

struct Splay
{
    int sz[maxn], ch[maxn][2], key[maxn], fa[maxn];
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

    int newnode(int p = 0, int k = 0)
    {
        int x = top ? stk[top--] : ++tot;
        fa[x] = p;
        sz[x] = 1;
        ch[x][0] = ch[x][1] = 0;
        key[x] = k;
        return x;
    }

    inline void init() { tot = top = 0; }

    inline void pushup(int x) { sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1; }

    void rotate(int x, int d)
    {
        int y = fa[x];
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
        int t = sz[ch[r][0]] + 1;
        if (t == k) return r;
        return t > k ? kth(ch[r][0], k) : kth(ch[r][1], k - t);
    }

    void insert(int v)
    {
        if (root == 0)
        {
            root = newnode(0, v);
            return;
        }
        int p = root;
        while (ch[p][key[p] < v]) p = ch[p][key[p] < v];
        ch[p][key[p] < v] = newnode(p, v);
        pushup(p);
        splay(ch[p][key[p] < v]);
    }

    void erase(int x)
    {
        splay(x);
        stk[++top] = x;
        if (!ch[root][0] || !ch[root][1])
        {
            root = ch[root][0] + ch[root][1];
            fa[root] = 0;
            return;
        }
        int tmp = kth(ch[root][1], 1);
        splay(tmp, root);
        key_value = ch[root][0], root = ch[root][1], fa[ch[root][0]] = root, fa[root] = 0;
        pushup(root);
    }

    int query(int x, int k)
    {
        splay(x);
        if (k < 1 || k > sz[root]) return 0;
        return key[kth(root, sz[root] - k + 1)];
    }

    void change(int x, int v) { erase(x), insert(v); }

    int pa[maxn];
    int find(int x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }

    void dfs(int r)
    {
        if (!r) return;
        dfs(ch[r][0]), dfs(ch[r][1]);
        stk[++top] = r;
        insert(key[r]);
    }

    void merge(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y) return;
        pa[y] = x;
        splay(x), splay(y);
        if (sz[x] > sz[y]) swap(x, y);
        root = y;
        dfs(x);
    }

} gao;

const int maxc = 1 << 19;
struct Cmd
{
    char op;
    int x, p;
} cmd[maxc];

const int maxm = 1 << 16;
int w[maxn], from[maxm], to[maxm];
bool removed[maxm];
inline void add(const int& x) { gao.merge(from[x], to[x]); }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int kase = 0;
    int n, m;
    while (~scanf("%d%d", &n, &m) && n + m)
    {
        gao.init();
        for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
        for (int i = 1; i <= m; i++) scanf("%d%d", &from[i], &to[i]);
        clr(removed, 0);
        int tot = 0, query_cnt = 0;
        for (char op; ~scanf(" %c", &op) && op != 'E'; tot++)
        {
            static int x, p, v;
            scanf("%d", &x);
            if (op == 'D') removed[x] = true;
            if (op == 'Q') scanf("%d", &p), ++query_cnt;
            if (op == 'C')
            {
                scanf("%d", &v);
                p = w[x], w[x] = v;
            }
            cmd[tot] = {op, x, p};
        }

        if (!query_cnt)
        {
            printf("Case %d: 0.000000\n", ++kase);
            continue;
        }

        for (int i = 1; i <= n; i++) gao.newnode(0, w[i]), gao.pa[i] = i;
        for (int i = 1; i <= m; i++)
            if (!removed[i]) add(i);

        ll query_tot = 0;
        for (int i = tot - 1; ~i; i--)
        {
            if (cmd[i].op == 'D') add(cmd[i].x);
            if (cmd[i].op == 'Q') query_tot += gao.query(cmd[i].x, cmd[i].p);
            if (cmd[i].op == 'C') gao.change(cmd[i].x, cmd[i].p);
        }
        printf("Case %d: %.6lf\n", ++kase, query_tot * 1.0 / query_cnt);
    }
    return 0;
}