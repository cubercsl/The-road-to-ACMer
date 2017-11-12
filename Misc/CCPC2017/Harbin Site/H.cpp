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

const int maxn = 1 << 17;

vector<ll> factor(ll x)
{
    vector<ll> ret;
    for (ll i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            while (x % i == 0) x /= i;
            ret.pb(i);
        }
    }
    if (x != 1) ret.pb(x);
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    int a[maxn];
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", a + i);
            sum += a[i];
        }
        vector<ll> v = factor(sum);
        ll ans = 1e18;
        for (ll x : v)
        {
            int b[maxn];
            for (int i = 0; i < n; i++)
                b[i] = a[i] % x;
            sort(b, b + n);
            int L = 0, R = n;
            ll up = 0, down = 0;
            while (L < R)
            {
                while (up <= down && L < R) up += b[L++];
                while (down < up && L < R) down += x - b[--R];
            }
            assert(up == down);
            ans = min(ans, up);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
