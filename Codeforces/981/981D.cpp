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

const int N = 64;
ll a[N], sum[N];
bool dp[N][N];

bool gao(ll x, int n, int k)
{
    clr(dp, 0);
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            if (dp[i][j])
                for (int p = i + 1; p <= n; p++)
                    if (((sum[p] - sum[i]) & x) == x) dp[p][j + 1] = 1;
    return dp[n][k];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    ll ans = 0;
    for (int i = 62; ~i; i--)
        if (gao(ans | (1LL << i), n, k)) ans |= (1LL << i);
    cout << ans << endl;
    return 0;
}