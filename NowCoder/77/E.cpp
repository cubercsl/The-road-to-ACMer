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
    int val[maxn][maxn];
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
                val[i][j] += v;
    }
    int sum(int x, int y)
    {
        int ret = 0;
        for (int i = x; i; i -= lowbit(i))
            for (int j = y; j; j -= lowbit(j))
                ret += val[i][j];
        return ret;
    }
    int query(int x1, int y1, int x2, int y2) { return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1); }

} ans;

bool a[maxn][maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (cin >> n >> m)
    {
        int op;
        ans.init(n);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                scanf("%d", &a[i][j]);
                if (a[i][j]) ans.add(i, j, 1);
            }
        while (m--)
        {
            scanf("%d", &op);
            if (op == 1)
            {
                static int x, y;
                scanf("%d%d", &x, &y);
                a[x][y] ^= 1;
                ans.add(x, y, a[x][y] ? 1 : -1);
            }
            else
            {
                static int x1, y1, x2, y2;
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                printf("%d\n", ans.query(x1, y1, x2, y2));
            }
        }
    }
    return 0;
}
