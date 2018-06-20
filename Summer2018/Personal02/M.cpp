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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    auto lcm = [](ll a, ll b) { return a * b / __gcd(a, b); };
    while (~scanf("%d%d", &n, &m))
    {
        ll ans = 0;
        vector<int> a(m);
        for (auto& t : a) scanf("%d", &t);
        for (int i = 0; i < (1 << m); i++)
        {
            ll d = 1;
            for (int j = 0; j < m; j++)
                if (i >> j & 1) d = lcm(d, a[j]);
            if (__builtin_parity(i)) d *= -1;
            ans += n / d;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
