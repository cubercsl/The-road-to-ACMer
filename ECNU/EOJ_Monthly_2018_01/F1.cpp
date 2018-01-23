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

const int N = 1 << 10;
bool dp[N][N];
vector<PII> G[N];
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
        static int u, v, c;
        cin >> u >> v >> c;
        G[u].pb(mp(v, c));
        G[v].pb(mp(u, c));
    }

    clr(dp, 0);
    int s, t;
    cin >> s >> t;
    queue<PII> q;
    q.push({s, 0});
    dp[s][0] = 1;
    while (!q.empty())
    {
        PII tmp = q.front();
        q.pop();
        int u = tmp.X;
        int now = tmp.Y;
        for (auto& e : G[u])
        {
            int v = e.X;
            int w = e.Y;
            int nxt = (now | w);
            if (dp[v][nxt]) continue;
            dp[v][nxt] = 1;
            q.push({v, nxt});
        }
    }
    bool flag = 0;
    for (int i = 0; i < (1 << 10); i++)
    {
        if (dp[t][i])
        {
            cout << i << endl;
            flag = 1;
            break;
        }
    }
    if (!flag) cout << -1 << endl;
    return 0;
}
