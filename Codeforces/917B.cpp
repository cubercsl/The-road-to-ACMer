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

const int N = 105;
vector<PII> G[N];

int dp[N][N][26];

int dfs(int u, int v, int now)
{
    if (~dp[u][v][now]) return dp[u][v][now];
    int& cur = dp[u][v][now];
    for (auto e : G[u])
    {
        int w = e.X, nxt = e.Y;
        if (nxt < now) continue;
        if (!dfs(v, w, nxt)) return cur = 1;
    }
    return cur = 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        static int u, v;
        static char c;
        cin >> u >> v >> c;
        G[u].pb(mp(v, c - 'a'));
    }
    clr(dp, -1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dfs(i, j, 0);
            // cout << dp[i][0] << " " << dp[j][0] << endl;
            if (dp[i][j][0])
                cout << "A";
            else
                cout << "B";
        }
        cout << endl;
    }
    return 0;
}
