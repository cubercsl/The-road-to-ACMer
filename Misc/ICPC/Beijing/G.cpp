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
    ll n, m;
    while (~scanf("%lld%lld", &n, &m))
    {
        ll d = __gcd(n - 1, m - 1);
        ll k = (m - 1) / d;
        ll p = (n - 1) / d;
        ll lcm = k * (n - 1);
        // printf("%lldx%lld\n", n, m);
        // printf("k = %lld\n", k);
        // printf("p = %lld\n", p);
        printf("%lld\n", lcm + 1 - (k - 1) * (p - 1));
        // puts("");
    }
    return 0;
}
