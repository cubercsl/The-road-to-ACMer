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
    int T;
    auto Pow = [](ll a, ll n) {
        ll t = 1;
        for (; n; n >>= 1, (a *= a) %= mod)
            if (n & 1) (t *= a) %= mod;
        return t;
    };
    scanf("%d", &T);
    while (T--)
    {
        int n, x;
        scanf("%d%d", &n, &x);
        vector<vector<int> > a(n, vector<int>(6));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 6; j++) scanf("%d", &a[i][j]);
        ll ans = 0;
        unordered_map<int, int> M;
        function<void(int, int, int, bool)> dfs = [&](int l, int r, int cur, bool d) {
            if (l == r)
            {
                if (d == false)
                {
                    M[cur]++;
                    return;
                }
                else
                {
                    int tmp = 1LL * x * Pow(cur, mod - 2) % mod;
                    ans += M[tmp];
                    return;
                }
            }
            for (int i = 0; i < 6; i++)
            {
                int nxt = 1LL * cur * a[l][i] % mod;
                dfs(l + 1, r, nxt, d);
            }
        };
        dfs(0, n / 2, 1, 0);
        dfs(n / 2, n, 1, 1);
        printf("%lld\n", ans);
    }
    return 0;
}
