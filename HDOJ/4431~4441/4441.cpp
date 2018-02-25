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

const int maxn = 1 << 17;
#define key_value ch[ch[root][1]][0]

struct Splay
{
    int sz[maxn], ch[maxn][2], fa[maxn];
    int key[maxn], pos[maxn], neg[maxn];
    ll sum[maxn];
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
        root = newnode(0, 0);
        ch[root][1] = newnode(root, 0);
        pushup(ch[root][1]), pushup(root);
    }

    int newnode(int p = 0, int k = 0)
    {
        int x = top ? stk[top--] : ++tot;
        fa[x] = p;
        sz[x] = 1;
        ch[x][0] = ch[x][1] = 0;
        key[x] = k, sum[x] = k;
        pos[x] = k > 0, neg[x] = k < 0;
        return x;
    }

    void pushdown(int x)
    {
    }

    void pushup(int x)
    {
        int lson = ch[x][0], rson = ch[x][1];
        sz[x] = sz[lson] + sz[rson] + 1;
        pos[x] = pos[lson] + pos[rson] + (key[x] > 0);
        neg[x] = neg[lson] + neg[rson] + (key[x] < 0);
        sum[x] = sum[lson] + sum[rson] + key[x];
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

    void select(int l, int r)
    {
        splay(kth(root, l));
        splay(kth(ch[root][1], r - l + 2), root);
    }

    int find(int r, int k)
    {
        if (neg[ch[r][0]] == k && key[r] < 0)
        {
            splay(r);
            return sz[ch[root][0]];
        }
        return neg[ch[r][0]] < k + 1 ? find(ch[r][1], k - neg[ch[r][0]] - (key[r] < 0)) : find(ch[r][0], k);
    }

    void erase(int x)
    {
        splay(x);
        int k = sz[ch[root][0]];
        select(k, k);
        key_value = 0;
        pushup(ch[root][1]), pushup(root);
    }

    int insert(int p, int v)
    {
        select(p, p - 1);
        key_value = newnode(ch[root][1], v);
        pushup(ch[root][1]), pushup(root);
        splay(key_value);
        return root;
    }

    ll query(int x, int y)
    {
        splay(x), splay(y, root);
        return sum[key_value];
    }

    inline int getpos()
    {
        int n = pos[ch[root][0]];
        return neg[root] > n ? find(root, n) : sz[root] - 1;
    }

} gao;

int id[maxn][2];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, kase = 0, x;
    char op[10];
    while (~scanf("%d", &n))
    {
        gao.init();
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 1; i <= n; i++) q.push(i);
        printf("Case #%d:\n", ++kase);
        while (n--)
        {
            // gao.debug();
            scanf("%s%d", op, &x);
            if (op[0] == 'i')
            {
                ++x;
                int c = q.top();
                q.pop();
                id[c][0] = gao.insert(x, c);
                int y = gao.getpos();
                id[c][1] = gao.insert(y, -c);
            }
            else if (op[0] == 'r')
            {
                q.push(x);
                gao.erase(id[x][0]);
                gao.erase(id[x][1]);
            }
            else
                printf("%lld\n", gao.query(id[x][0], id[x][1]));
        }
    }
    return 0;
}