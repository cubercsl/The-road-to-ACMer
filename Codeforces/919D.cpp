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

const int N = 300005;
vector<int> G[N];
int deg[N];
int dp[N][26];
int ch[N];
int dfs(int u, int c)
{
    if (~dp[u][c]) return dp[u][c];
    dp[u][c] = 0;
    for (auto& v : G[u])
        dp[u][c] = max(dp[u][c], dfs(v, c));
    dp[u][c] += ch[u] == c;
    return dp[u][c];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        static char c;
        cin >> c;
        ch[i] = c - 'a';
    }
    while (m--)
    {
        static int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].pb(v);
        deg[v]++;
        if (u == v) return cout << -1 << endl, 0;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (!deg[i]) q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto& v : G[u])
            if (--deg[v] == 0)
                q.push(v);
    }
    clr(dp, -1);
    for (int i = 0; i < n; i++)
        if (deg[i]) return cout << -1 << endl, 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 26; j++)
            ans = max(dfs(i, j), ans);
    cout << ans << endl;

    return 0;
}
