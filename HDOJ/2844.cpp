// Coin, HDU2844

/*Sample Input
3 10
1 2 4 2 1 1
2 5
1 4 2 1
0 0
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

const int maxn = 1e5 + 5;
int dp[maxn];
int a[105], c[105];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (cin >> n >> m, n + m)
    {
        clr(dp, 0);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> c[i];
        for (int i = 0; i < n; i++)
        {
            int num = c[i];
            for (int k = 1; num > 0; k <<= 1)
            {
                int mul = min(k, num);
                for (int j = m; j >= a[i] * mul; j--)
                    dp[j] = max(dp[j], dp[j - a[i] * mul] + a[i] * mul);
                num -= mul;
            }
        }
        int ans = 0;
        for (int i = 1; i <= m; i++)
            ans += (dp[i] == i);
        cout << ans << endl;
    }
    return 0;
}
