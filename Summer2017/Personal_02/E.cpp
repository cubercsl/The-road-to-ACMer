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

const int maxn = 15;
const int maxm = 1e4 + 5;
int n, m, s;
vector <PII> v[maxn];
int dp[maxn][maxm];

void init()
{
    for (int i = 0; i < maxn; i++)
        v[i].clear();
    clr(dp, -1);
    for (int i = 0; i < m; i++)
        dp[0][i] = 0;
}

void solve()
{
    for (int i = 1; i <= s; i++)
        for (int j = 0; j < v[i].size(); j++)
            for (int k = m; k >= v[i][j].X; k--)
                dp[i][k] = max(dp[i][k], max(dp[i][k - v[i][j].X], dp[i - 1][k - v[i][j].X]) + v[i][j].Y);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    while (cin >> n >> m >> s)
    {
        init();
        while (n--)
        {
            int a, b, c;
            cin >> a >> b >> c;
            v[a].pb(mp(b, c));
        }
        solve();
        if (dp[s][m] < 0)
            cout << "Impossible" << endl;
        else
            cout << dp[s][m] << endl;
    }
    return 0;
}
