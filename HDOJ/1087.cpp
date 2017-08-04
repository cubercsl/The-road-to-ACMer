// Super Jumping! Jumping! Jumping!, HDU1087

/*Sample Input
3 1 3 2
4 1 2 3 4
4 3 3 2 1
0
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

const int maxn = 1005;
int a[maxn];
int dp[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int n;
    while (cin >> n, n)
    {
        clr(dp, 0);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int ans = dp[0] = a[0];
        for (int i = 1; i < n; i++)
        {
            dp[i] = a[i];
            for (int j = 0; j < i; j++)
                if (a[i] > a[j])
                    dp[i] = max(dp[i], dp[j] + a[i]);
            ans = max(dp[i], ans);
        }
        cout << ans << endl;
    }
    return 0;
}
