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

const int maxn = 1 << 20;
struct LCT
{
    int val[maxn], sum[maxn];
    int rev[maxn], ch[maxn][2], fa[maxn];
    int stk[maxn];
    inline void init(int n)
    {
        for (int i = 1; i <= n; i++) scanf("%d", val + i);
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
    void pushup(int x)
    {
        sum[x] = val[x] + sum[ch[x][0]] + sum[ch[x][1]];
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
        int y = 0;
        for (; x; y = x, x = fa[x]) splay(x), ch[x][1] = y, pushup(x);
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
} gao;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    scanf("%d", &n);
    gao.init(n);
    scanf("%d", &m);
    while (m--)
    {
        static int x, y;
        static char op[15];
        scanf("%s%d%d", op, &x, &y);
        if (op[0] == 'e')
        {
            if (gao.find(x) != gao.find(y))
                puts("impossible");
            else
                printf("%d\n", gao.query(x, y));
        }
        if (op[0] == 'b')
        {
            if (gao.find(x) != gao.find(y))
                puts("yes"), gao.link(x, y);
            else
                puts("no");
        }
        if (op[0] == 'p') gao.update(x, y);
    }
    return 0;
}