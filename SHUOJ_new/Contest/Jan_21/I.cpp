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

const int N = 1 << 17;
ll a[N], d[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, q;
    while (~scanf("%d%d", &n, &q))
    {
        clr(d, 0);
        for (int i = 1; i <= n; i++) scanf("%lld", a + i);
        while (q--)
        {
            static int l, r, v;
            scanf("%d%d%d", &l, &r, &v);
            d[l] += v, d[r + 1] -= v;
        }
        for (int i = 1; i <= n; i++) d[i] += d[i - 1];
        for (int i = 1; i <= n; i++) printf("%lld%c", a[i] + d[i], i == n ? '\n' : ' ');
    }
    return 0;
}
