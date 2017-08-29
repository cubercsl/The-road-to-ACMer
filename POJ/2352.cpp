// Stars, POJ2352

/*Sample Input
5
1 1
5 1
7 1
3 3
5 5
*/

#include <cstdio>
#include <vector>
#include <cstring>
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

const int maxn = 32005;
int BIT[maxn];

inline int lowbit (int x)
{
    return x & (-x);
}

void add(int x)
{
    while (x < maxn)
    {
        BIT[x]++;
        x += lowbit(x);
    }
}

int query(int x)
{
    int ans = 0;
    while (x)
    {
        ans += BIT[x];
        x -= lowbit(x);
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int ans[15005];
    int n;
    while (~scanf("%d", &n))
    {
        clr(ans, 0);
        clr(BIT, 0);
        for (int i = 0; i < n; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            x++;//x maybe 0
            ans[query(x)]++;
            add(x);
        }
        for (int i = 0; i < n; i++)
            printf("%d\n", ans[i]);
    }

    return 0;
}
