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

int dp[4011];

int main()
{
    int n, a[3];
    while (cin >> n >> a[0] >> a[1] >> a[2])
    {
        clr(dp, -0x3f);
        dp[0] = 0;
        for (int i = 0; i < 3; i++)
            for (int j = a[i]; j <= n; ++j)
                dp[j] = max(dp[j], dp[j - a[i]] + 1);
        cout << dp[n] << endl;
    }
    return 0;
}
