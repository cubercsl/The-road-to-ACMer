// Rikka with Subset, 2017 Multi-University Training Contest, HDU6092

/*Sample Input
2
2 3
1 1 1 1
3 3
1 3 3 1
*/

#include <bits/stdc++.h>
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

const int maxn = 55;
const int maxm = 1e4 + 5;
int n, m;
int a[maxn];
int b[maxm];
int dp[maxm];

void solve()
{
    int tot = 0;
    clr(dp, 0);
    dp[0] = 1;
    for (int i = 1; i <= m; i++)
    {
        if (tot == n) return;
        int tmp = b[i] - dp[i];
        for (int j = 0; j < tmp; j++)
        {
            a[tot++] = i;
            for (int k = m; k >= i; k--)
                dp[k] += dp[k - i];
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= m; i++)
            scanf("%d", &b[i]);
        solve();
        for (int i = 0; i < n; i++)
        {
            if (i) putchar(' ');
            printf("%d", a[i]);
        }
        putchar('\n');
    }
    return 0;
}
