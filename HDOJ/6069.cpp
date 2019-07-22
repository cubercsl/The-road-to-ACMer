// Counting Divisors, 2017 Multi-University Training Contest, HDU6069

/*Sample Input
3
1 5 1
1 10 2
1 100 3
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
const int mod = 998244353;
const double eps = 1e-6;
const int maxn = 1e6 + 5;

bool vis[maxn];
ll d[maxn];
ll t[maxn];
ll tot, prime[maxn];
ll k;

void init(ll n)
{
    clr(vis, 0);
    tot = 0;
    for (int i = 2; i < n; i++)
    {
        if (!vis[i])
            prime[tot++] = i;
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] > n)
                break;
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

ll solve(ll l, ll r)
{
    ll ans = 0;
    for (ll i = l; i <= r; i++)
        d[i - l] = 1;
    for (int i = 0; i < tot; i++)
    {
        ll tmp = prime[i];
        if (tmp < l)
            tmp = prime[i] * ((l + prime[i] - 1) / prime[i]);
        for (; tmp <= r; tmp += prime[i])
        {
            ll cnt = 0;
            while (t[tmp - l] % prime[i] == 0)
                t[tmp - l] /= prime[i], cnt++;
            if (cnt != 0)
                d[tmp - l] = (d[tmp - l] * (k * cnt % mod + 1) % mod) % mod;
        }
    }
    for (ll i = l; i <= r; i++)
        if (d[i - l] == 1)
            ans = (ans + k + 1) % mod;
        else if (t[i - l] != 1)
            ans = (ans + d[i - l] * (k + 1)) % mod;
        else
            ans = (ans + d[i - l]) % mod;
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
#endif
    init(1000005);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll l, r;
        scanf("%lld%lld%lld", &l, &r, &k);
        for (ll i = l; i <= r; i++)
            t[i - l] = i;
        ll ans = solve(l, r);
        if (l == 1)
            ans -= k;
        ans = (ans + mod) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}
