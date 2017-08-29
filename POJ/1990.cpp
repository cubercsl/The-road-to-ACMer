// MooFest, POJ1990

/*Sample Input
4
3 1
2 5
2 6
4 3
*/

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
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

const int maxn = 2e5 + 5;
typedef pair <ll, ll> PLL;

struct bit
{
    int n;
    ll val[maxn];
    void init()
    {
        this->n = maxn;
        clr(val, 0);
    }
    inline int lowbit (int x)
    {
        return x & (-x);
    }
    void update(int x, ll v)
    {
        for (int i = x; i <= n; i += lowbit(i))
            val[i] += v;
    }
    ll query(int x)
    {
        ll sum = 0;
        for (int i = x; i; i -= lowbit(i))
            sum += val[i];
        return sum;
    }
} sum, dir;

ll presum[maxn];
PLL a[maxn];

int main()
{
#ifndef ONLINE_JUDGE
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
#endif
    int n;
    while (~scanf("%d", &n))
    {
        sum.init();
        dir.init();
        for (int i = 0; i < n; i++)
            scanf("%lld%lld", &a[i].X, &a[i].Y);
        sort(a, a + n);
        ll presum = 0;
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ll tmp = sum.query(a[i].Y);
            ll num = dir.query(a[i].Y);
            ans += a[i].X * (a[i].Y * num - tmp);
            ans += a[i].X * (presum - tmp - (i  - num) * a[i].Y);
            presum += a[i].Y;
            sum.update(a[i].Y, a[i].Y);
            dir.update(a[i].Y, 1LL);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
