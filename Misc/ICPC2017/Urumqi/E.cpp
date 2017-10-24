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

ll a[] = { 0, 1, 8, 49, 288, 1681, 9800, 57121, 332928, 1940449,
    11309768, 65918161, 384199200, 2239277041,
    13051463048, 76069501249, 443365544448,
    2584123765441, 15061377048200, 87784138523761,
    511643454094368, 2982076586042449,
    17380816062160328, 101302819786919521 };

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        ll n, ans = -1;
        scanf("%lld", &n);
        for (int i = 0; i < 24; i++)
            if (a[i] >= n)
            {
                ans = a[i];
                break;
            }
        printf("Case #%d: %lld\n", ++kase, ans);
    }

    return 0;
}
