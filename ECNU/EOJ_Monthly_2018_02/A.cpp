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

const int maxn = 3005;
ll dp[maxn];
int a[maxn];
vector<int> c = {100, 50, 20, 10, 5, 1};
int gao(ll tot)
{
    int ret = 0;
    for (auto t : c)
    {
        ret += tot / t;
        tot %= t;
    }
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int k;
    ll n, p;
    while (~scanf("%lld%d%lld", &n, &k, &p))
    {
        clr(dp, 0x3f);
        dp[0] = 0;
        int up = 1;
        for (int i = 1; i <= k; i++) up *= i / __gcd(up, i);
        for (int i = 1; i <= k; i++) dp[i] = a[i] = gao(p * i);
        for (int i = 1; i <= up * 2; i++)
            for (int j = max(i - k, 0); j < i; j++)
                dp[i] = min(dp[i], dp[j] + a[i - j]);
        if (n <= up)
        {
            printf("%lld\n", dp[n]);
            continue;
        }
        ll ans = dp[n % up + up] + (n / up - 1) * dp[up];
        printf("%lld\n", ans);
    }
    return 0;
}