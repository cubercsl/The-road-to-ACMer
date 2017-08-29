// Mobile phones, POJ1195

/*Sample Input
0 4
1 1 2 3
2 0 0 2 2 
1 1 1 2
1 1 2 -1
2 1 1 2 3 
3
*/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 1100;
int bit[maxn][maxn];
int n;

inline int lowbit (int x)
{
    return x & (-x);
}

inline void update(int x, int y, int val)
{
    for (int i = x; i <= n; i += lowbit(i))
        for (int j = y; j <= n; j += lowbit(j))
            bit[i][j] += val;
}

inline int query(int x, int y)
{
    int ans = 0;
    for (int i = x; i; i -= lowbit(i))
        for (int j = y; j; j -= lowbit(j))
            ans += bit[i][j];
    return ans;
}

inline int sum(int x1, int y1, int x2, int y2)
{
    return query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int c;
    while (~scanf("%d", &c))
    {
        if (c == 3)
            break;
        if (c == 0)
        {
            clr(bit, 0);
            scanf("%d", &n);
        }
        if (c == 1)
        {
            int x, y, a;
            scanf("%d%d%d", &x, &y, &a);
            update(x + 1, y + 1, a);
        }
        if (c == 2)
        {
            int l, b, r, t;
            scanf("%d%d%d%d", &l, &b, &r, &t);
            printf("%d\n", sum(l + 1, b + 1, r + 1, t + 1));
        }
    }
    return 0;
}
