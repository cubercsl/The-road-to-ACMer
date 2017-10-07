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

const int maxn = 2e5 + 5;
ll cnt[maxn];

ll Pow(ll a, ll n)
{
    ll t = 1;
    for (; n; n >>= 1, a = (a * a % mod))
        if (n & 1) t = (t * a % mod);
    return t;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (~scanf("%d", &n))
    {
        clr(cnt, 0);
        for (int i = 0; i < n; i++)
        {
            int p;
            scanf("%d", &p);
            cnt[p]++;
        }
        ll sum = 1;
        for (int i = 1; i < maxn; i++)
            if (cnt[i])
                sum = (sum * (1 + cnt[i])) % (mod * 2 - 2);
        ll ans = 1;
        for (int i = 1; i < maxn; i++)
            if (cnt[i])
                ans = (ans * Pow(i, cnt[i] * sum / 2)) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}
