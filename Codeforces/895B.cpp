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

ll a[1 << 17];

int main()
{
#ifndef ONLINE_JUDGE
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
#endif
    int n, x, k;
    while (~scanf("%d%d%d", &n, &x, &k))
    {
        for (int i = 0; i < n; i++)
            scanf("%lld", a + i);
        sort(a, a + n);
        ll cnt = 0;
        
        printf("%lld\n", cnt);
    }
    return 0;
}
