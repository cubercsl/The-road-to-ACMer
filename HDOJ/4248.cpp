// Grids, HDU4828

/*Sample Input
2
1
3
*/

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

const int maxn = 1e6 + 5;
ll f[maxn] = {0, 1}, inv[maxn] = {0, 1};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    for (int i = 2; i < maxn - 1; i++)
        inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    for (int i = 2; i < maxn - 1; i++)
        f[i] = (((f[i - 1] * (4 * i - 2)) % mod) * inv[i + 1]) % mod;
    int t, n, kase = 0;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        printf("Case #%d:\n%lld\n", ++kase, f[n]);
    }
    return 0;
}
