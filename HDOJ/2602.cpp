// Bone Collector, HDU2602

/*Sample Input
1
5 10
1 2 3 4 5
5 4 3 2 1
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
int dp[maxn];
int v[maxn], w[maxn];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n, V;
        cin >> n >> V;
        clr(dp, 0);
        for (int i = 0; i < n; i++)
            cin >> w[i];
        for (int i = 0; i < n; i++)
            cin >> v[i];
        for (int i = 0; i < n; i++)
            for (int j = V; j >= v[i]; j--)
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        cout << dp[V] << endl;
    }
    return 0;
}
