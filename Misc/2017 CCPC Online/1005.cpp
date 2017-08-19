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
const int mod = 1e9 + 7;
const double eps = 1e-6;
int dp[10];

void init()
{
    dp[1] = 4;
    dp[2] = 4;
    dp[3] = 6;
    dp[4] = 6;
    dp[5] = 7;
    dp[6] = 8;
    dp[7] = 8;
    dp[8] = 8;
}

int main()
{
    init();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        if (n < 9)
        {
            printf("%d\n", dp[n]);
            continue;
        }
        double s = n;
        ll t = (ll) sqrt(s / 2);
        double d1 = 2.0 * t * t;
        double d2 = 2.0 * t * t + t - 0.5;
        double d3 = 2.0 * t * t + 2 * t;
        double d4 = 2.0 * t * t + 3 * t + 0.5;
        double d5 = 2.0 * (t + 1) * (t + 1);
        if (s > d1 && s <= d2)
            printf("%lld\n", 4 * t + 1);
        else if (s > d2 && s <= d3)
            printf("%lld\n", 4 * t + 2);
        else if (s > d2 && s <= d4)
            printf("%lld\n", 4 * t + 3);
        else printf("%lld\n", 4 * t + 4);
    }
    return 0;
}
