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
const int mod = 998244353;
const double eps = 1e-6;

ll Pow(ll a, ll n, ll mod)
{
    ll t = 1;
    for (; n; n >>= 1, a = (a * a % mod))
        if (n & 1) t = (t * a % mod);
    return t;
}
ll inv(ll a, ll m)
{
    return Pow(a, m - 2, m);
}
// 0 <= n <= 109, 0 <= m <= 104, 1 <= k <= 109+7
vector<int> v;
int dp[110];
ll Cal(int l, int r, int k, int dis)
{
    ll res = 1;
    for (int i = l; i <= r; i++)
    {
        int t = i;
        for (int j = 0; j < v.size(); j++)
        {
            int y = v[j];
            while (t % y == 0)
            {
                dp[j] += dis;
                t /= y;
            }
        }
        res = res * (ll)t % k;
    }
    return res;
}
ll Comb(int n, int m, int k)
{
    clr(dp, 0);
    v.clear();
    int tmp = k;
    for (int i = 2; i * i <= tmp; i++)
    {
        if (tmp % i == 0)
        {
            int num = 0;
            while (tmp % i == 0)
            {
                tmp /= i;
                num++;
            }
            v.pb(i);
        }
    }
    if (tmp != 1) v.pb(tmp);
    ll ans = Cal(n - m + 1, n, k, 1);
    for (int j = 0; j < v.size(); j++)
    {
        ans = ans * Pow(v[j], dp[j], k) % k;
    }
    ans = ans * inv(Cal(2, m, k, -1), k) % k;
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen("1.in", "r", stdin);
   freopen("1.out", "w", stdout);
#endif
    ll n, m, ans;
    while (~scanf("%lld%lld", &n, &m))
    {
        if (n < m)
        {
            puts("0");
            continue;
        }
        if (n & 1)
        {
            if (m & 1)
            {
                n = (n + 1) / 2;
                m = (m + 1) / 2;
                ans = Pow(4, m - 1, mod) * (2 * n - 1) % mod * Comb(n + m - 1, 2 * m - 1, mod) % mod;
                ans = ans * inv(n + m - 1, mod) % mod;
                if ((m + n) & 1)
                    ans = (-ans + mod) % mod;
                printf("%lld\n", ans);
            }
            else
                puts("0");
        }
        else
        {
            if (m & 1)
                puts("0");
            else
            {
                n /= 2, m /= 2;
                ans = Pow(4, m, mod) * n % mod * Comb(n + m, 2 * m, mod) % mod;
                ans = ans * inv(n + m, mod) % mod;
                if ((m + n) & 1)
                    ans = (-ans + mod) % mod;
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}
