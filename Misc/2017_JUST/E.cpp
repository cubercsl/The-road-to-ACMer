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

int diec[20][10];
map<ll, int> M;
ll ans = 0;
int x;

ll Pow(ll a, ll n)
{
    ll t = 1;
    for (; n; (a *= a) %= mod, n >>= 1)
        if (n & 1) (t *= a) %= mod;
    return t;
}

void dfs(int s, int e, bool flag, ll res)
{
    if (e == s)
    {
        if (flag)
            ++M[res];
        else
            ans += M[x * Pow(res, mod - 2) % mod];
    }
    else
    {
        for (int i = 0; i < 6; i++)
            dfs(s + 1, e, flag, res * diec[s][i] % mod);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ans = 0;
        M.clear();
        int n;
        scanf("%d%d", &n, &x);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                scanf("%d", &diec[i][j]);
            }
        }
        dfs(0, n / 2, 1, 1);
        dfs(n / 2, n, 0, 1);
        printf("%lld\n", ans);
    }
    return 0;
}