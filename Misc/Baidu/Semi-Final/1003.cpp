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

ll Pow[maxn];
ll dp[maxn];

int main()
{
#ifndef ONLINE_JUDGE
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
#endif
    fastin
    dp[1] = 1, dp[2] = 6;
    Pow[0] = 1, Pow[1] = 2, Pow[2] = 4;
    for (int i = 3; i < maxn; i++)
    {
        dp[i] = (2 * dp[i - 1] % mod + 4 * dp[i - 2] % mod + Pow[i - 1]) % mod;
        Pow[i] = Pow[i - 1] * 2 % mod;
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << 2 << endl;
            continue;
        }
        ll ans = 0;
        for (int i = 2; i < n; i++)
            ans = (ans + Pow[i + 2] * dp[n - i] % mod) % mod;
        ans = (ans + 4 * dp[n]) % mod;
        cout << ans << endl;
    }
    return 0;
}
