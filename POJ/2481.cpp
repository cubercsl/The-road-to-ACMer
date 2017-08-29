// Cows, POJ2481

/*Sample Input
3
1 2
0 3
3 4
0
*/

#include <cstdio>
#include <cstring>
#include <vector>
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

const int maxn = 1e5 + 5;
int ans[maxn], bit[maxn];

struct node
{
    int S, E, id;
    bool operator < (const node &rhs) const
    {
        return E > rhs.E || (E == rhs.E && S < rhs.S);
    }
} a[maxn];

inline int lowbit (int x)
{
    return x & (-x);
}

inline void update (int x)
{
    for (int i = x; i < maxn; i += lowbit(i))
        bit[i]++;
}

inline int query (int x)
{
    int ans = 0;
    for (int i = x; i; i -= lowbit(i))
        ans += bit[i];
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (~scanf("%d", &n), n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &a[i].S, &a[i].E);
            a[i].id = i;
        }
        sort(a, a + n);
        clr(bit, 0);
        clr(ans, 0);
        update(a[0].S + 1);
        ans[a[0].id] = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i].E == a[i - 1].E && a[i].S == a[i - 1].S)
                ans[a[i].id] = ans[a[i - 1].id];
            else
                ans[a[i].id] = query(a[i].S + 1);
            update(a[i].S + 1);
        }
        for (int i = 0; i < n; i++)
        {
            if (i) putchar(' ');
            printf("%d", ans[i]);
        }
        puts("");
    }
    return 0;
}
