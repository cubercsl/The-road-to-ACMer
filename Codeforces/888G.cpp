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

const int maxn = 6000005;
struct Trie
{
    int ch[maxn][2];
    int val[maxn];
    int sz, rt;
    inline int newnode()
    {
        clr(ch[sz], 0), val[sz] = 0;
        return sz++;
    }
    void init() { sz = 0, rt = newnode(); }
    void insert(const int& x)
    {
        printf("insert: %d\n", x);
        int u = rt;
        for (int i = 31; ~i; i--)
        {
            int c = x >> i & 1;
            if (!ch[u][c]) ch[u][c] = newnode();
            u = ch[u][c];
            val[u]++;
        }
    }
    void del(const int& x)
    {
        int u = rt;
        for (int i = 31; ~i; i--)
        {
            int c = x >> i & 1;
            assert(ch[u][c]);
            u = ch[u][c];
            val[u]--;
        }
    }
    int query(const int& x)
    {
        int u = rt;
        int ret = 0;
        for (int i = 31; ~i; i--)
        {
            int c = x >> i & 1;
            if (ch[u][c] && val[ch[u][c]] > 0)
                u = ch[u][c], ret |= (c << i);
            else
                u = ch[u][c ^ 1], ret |= (c ^ 1 << i);
        }
        return ret;
    }
};

int a[1 << 18];

Trie trie;

typedef pair<int, PII> Edge;

int main()
{
#ifndef ONLINE_JUDGE
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
#endif
    int n;

    while (~scanf("%d", &n))
    {
        trie.init();
        for (int i = 0; i < n; i++)
        {
            scanf("%d", a + i);
            trie.insert(a[i]);
        }
        priority_queue<Edge, vector<Edge>, greater<Edge> > q;
        trie.del(a[0]);
        int tmp = trie.query(a[0]);
        q.push(mp(tmp ^ a[0], mp(a[0], tmp)));
        ll ret = 0;
        for (int i = 1; i < n; i++)
        {
            Edge e = q.top();
            q.pop();
            trie.del(e.Y.Y);
            ret += e.X;
            tmp = trie.query(e.Y.X);
            q.push(mp(tmp ^ e.Y.X, mp(e.Y.X, tmp)));
            tmp = trie.query(e.Y.Y);
            q.push(mp(tmp ^ e.Y.Y, mp(e.Y.Y, tmp)));
        }
        printf("%lld\n", ret);
    }
    return 0;
}
