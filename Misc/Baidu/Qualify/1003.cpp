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

const int maxn = 1e5 + 5;
const int maxm = 1005;

ll a[maxn], b[maxn], k[maxm], p[maxm];
ll dp[maxm][15];
int n, m;

void init()
{
    clr(dp, 0x3f);
    for (int i = 0; i <= 10; i++)
    {
        dp[0][i] = 0;
        for (int j = 0; j < m; j++)
        {
            ll d = p[j] - i;
            if (d > 0)
            {
                for (int p = 1; p < d; p++)
                    dp[p][i] = min(dp[p][i], k[j]);
                for (int p = d; p < maxm; p++)
                    dp[p][i] = min(dp[p][i], dp[p - d][i] + k[j]);
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    while (cin >> n >> m)
    {
        ll mb = 0, mp = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];
            mb = max(mb, b[i]);
        }
        for (int i = 0; i < m; i++)
        {
            cin >> k[i] >> p[i];
            mp = max(mp, p[i]);
        }
        if (mb >= mp)
        {
            cout << -1 << endl;
            continue;
        }
        init();
        ll ans = 0;
        for (int i = 0; i < n; i++)
            ans += dp[a[i]][b[i]];
        cout << ans << endl;
    }
    return 0;
}
