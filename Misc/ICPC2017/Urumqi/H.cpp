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

const int maxn = 1e4 + 5;
int dp[maxn];
vector<PII> G[maxn];

void init(int n)
{
    for (int i = 0; i < n; i++)
        G[i].clear();
}

int dfs(int u)
{
    if (dp[u] != -1) return dp[u];
    int tmp = 0;
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i].X;
        int w = G[u][i].Y;
        tmp = max(tmp, w + dfs(v));
    }
    return dp[u] = tmp;
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
        int n, m;
        scanf("%d%d", &n, &m);
        init(n);
        while (m--)
        {
            int s, t, l;
            scanf("%d%d%d", &s, &t, &l);
            s--, t--;
            G[s].pb(mp(t, l));
        }
        clr(dp, -1);
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, dfs(i));
        printf("%d\n", ans);
    }
    return 0;
}
