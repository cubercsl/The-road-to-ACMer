//moira
#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp make_pair
#define pb push_back
#define X first
#define Y second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;
int main()
{

    int T;
    ll n, a;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld%lld", &n, &a);
        if (n > 2 || n == 0)
        {
            printf("-1 -1\n");
        }
        else if (n == 1)
        {
            printf("%lld %lld\n", 1, 1LL * (a + 1));
        }
        else if (a & 1)
        {
            ll r = a / 2, s = a / 2 + 1;
            printf("%lld %lld\n", 2 * r * s, r * r + s * s);
        }
        else
        {
            ll r = a / 2, s = 1;
            printf("%lld %lld\n", r * r - s * s, r * r + s * s);
        }
    }
    return 0;
}