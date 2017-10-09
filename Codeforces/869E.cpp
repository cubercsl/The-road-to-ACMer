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

const int maxn = 2505;
struct BIT
{
    int n, m;
    ll val[maxn][maxn];
    void init(int n, int m) { this->n = n, this->m = m, clr(val, 0); }
    inline int lowbit(int x) { return x & (-x); }
    void update(int x, int y, ll v)
    {
        for (int i = x; i <= n; i += lowbit(i))
            for (int j = y; j <= m; j += lowbit(j))
                val[i][j] += v;
    }
    ll query(int x, int y)
    {
        ll ret = 0;
        for (int i = x; i; i -= lowbit(i))
            for (int j = y; j; j -= lowbit(j))
                ret += val[i][j];
        return ret;
    }
};

BIT ans;

inline int rd()
{
    return rand() << 15 | rand();
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    srand(time(0));
    int n, m, q;
    while (~scanf("%d%d%d", &n, &m, &q))
    {
        map<pair<PII, PII>, int> G;
        ans.init(n, m);
        while (q--)
        {
            static int op, a, b, c, d;
            scanf("%d%d%d%d%d", &op, &a, &b, &c, &d);
            if (op == 1)
            {
                int u = rd();
                G[mp(mp(a, b), mp(c, d))] = u;
                ans.update(a, b, u);
                ans.update(a, d + 1, -u);
                ans.update(c + 1, b, -u);
                ans.update(c + 1, d + 1, u);
            }
            else if (op == 2)
            {
                int u = G[mp(mp(a, b), mp(c, d))];
                ans.update(a, b, -u);
                ans.update(a, d + 1, u);
                ans.update(c + 1, b, u);
                ans.update(c + 1, d + 1, -u);
            }
            else
            {
                ll va = ans.query(a, b);
                ll vb = ans.query(c, d);
                puts(va == vb ? "Yes" : "No");
            }
        }
    }
    return 0;
}
