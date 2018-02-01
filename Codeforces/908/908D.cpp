#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int N = 1005;
ll dp[N][N];
ll Pow(ll a, ll n, ll mod)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= mod)
        if (n & 1) (t *= a) %= mod;
    return t;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int k, a, b;

    while (cin >> k >> a >> b)
    {
        clr(dp, 0);
        ll _a = Pow(a, mod - 2, mod);
        ll _b = Pow(b, mod - 2, mod);
        ll _ab = Pow(a + b, mod - 2, mod);
        for (int i = k; ~i; i--)
            for (int j = 0; j <= k; j++)
            {
                if (i >= j)
                    dp[i][j] = (a * _b % mod + i) % mod;
                else
                    dp[i][j] = (a * dp[i + 1][j] % mod + b * (dp[i][j - i] + i) % mod) % mod * _ab % mod;
            }
        cout << dp[1][k] << endl;
    }
    return 0;
}
