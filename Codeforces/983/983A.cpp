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
    int n;
    scanf("%d", &n);
    while (n--)
    {
        ll p, q, b;
        scanf("%lld%lld%lld", &p, &q, &b);
        if (p == 0)
            puts("Finite");
        else
        {
            ll g = __gcd(p, q);
            p /= g, q /= g;
            while (__gcd(q, b) != 0)
            {
                g = __gcd(q, b);
                if (g == 1) break;
                while (q % g == 0) q /= g;
            }
            puts(q == 1 ? "Finite" : "Infinite");
        }
    }
    return 0;
}
