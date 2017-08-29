// Japan, POJ3067

/*Sample Input
1
3 4 4
1 4
2 3
3 2
3 1
*/

#include <iostream>
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

const int maxn = 1005;
int n, m, k;

int BIT[maxn];

inline int lowbit (int x)
{
    return x & (-x);
}
void add(int x)
{
    while (x <= m)
    {
        BIT[x]++;
        x += lowbit(x);
    }
}

ll query(int x)
{
    ll ans = 0;
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
    int t, kase = 0;
    scanf("%d", &t);
    PII a[1000005];
    while (t--)
    {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 0; i < k; i++)
            scanf("%d%d", &a[i].X, &a[i].Y);
        sort(a, a + k);
        clr(BIT, 0);
        ll ans = 0;
        for (int i = k - 1; i >= 0; i--)
        {
            add(a[i].Y);
            ans += query(a[i].Y - 1);
        }
        printf("Test case %d: %lld\n", ++kase, ans);
    }

    return 0;
}
