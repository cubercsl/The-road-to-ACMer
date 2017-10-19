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

const int maxn = 1005;
struct BIT
{
    int n;
    ll val[maxn][maxn];
    void init(int n)
    {
        clr(val, 0);
        this->n = n;
    }
    inline int lowbit(int x) { return x & -x; }
    void add(int x, int y, int v)
    {
        for (int i = x; i <= n; i += lowbit(i))
            for (int j = y; j <= n; j += lowbit(j))
                val[i][j] = (val[i][j] + v + mod) % mod;
    }
    ll sum(int x, int y)
    {
        ll ret = 0;
        for (int i = x; i; i -= lowbit(i))
            for (int j = y; j; j -= lowbit(j))
                ret = (ret + val[i][j]) % mod;
        return ret;
    }
    ll query(int x1, int y1, int x2, int y2)
    {
        return (((sum(x2, y2) - sum(x1 - 1, y2) + mod) % mod - sum(x2, y1 - 1) + mod) % mod + sum(x1 - 1, y1 - 1)) % mod;
    }

} ans;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (cin >> n >> m)
    {
        char op[5];
        ans.init(n);
        while (m--)
        {
            scanf("%s", op);
            if (op[0] == 'A')
            {
                static int x, y, v;
                scanf("%d%d%d", &x, &y, &v);
                ++x, ++y;
                ans.add(x, y, v);
            }
            else
            {
                static int x1, y1, x2, y2;
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                ++x1, ++y1, ++x2, ++y2;
                printf("%lld\n", ans.query(x1, y1, x2, y2));
            }
        }
    }
    return 0;
}
