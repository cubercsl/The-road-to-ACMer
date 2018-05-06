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

const int N = 1 << 4 | 1;
int G[N][N];
int dp[1 << N][N];
int a[N], b[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n, m, k, l;
        scanf("%d%d%d%d", &n, &m, &k, &l);
        ++n;
        clr(G, 0x3f);
        for (int i = 0; i < n; i++) G[i][i] = 0;
        for (int i = 1; i < n; i++) scanf("%d", a + i);
        for (int i = 1; i < n; i++) scanf("%d", b + i);
        while (m--)
        {
            static int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u][v] = G[v][u] = min(G[u][v], w);
        }
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
        clr(dp, 0x3f);
        dp[1][0] = 0;
        int ans = 0;
        for (int i = 0; i < (1 << n); i++)
        {
            bool flag = false;
            for (int j = 0; j < n; j++)
                if (dp[i][j] <= l)
                {
                    if (dp[i][j] + G[j][0] <= l) flag = true;
                    for (int k = 1; k < n; k++) dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + G[j][k]);
                }
            if (flag)
            {
                priority_queue<PII> q;
                for (int j = 1; j < n; j++)
                    if (i >> j & 1) q.push({a[j], b[j]});
                if (q.empty()) continue;
                int tmp = 0;
                for (int j = 0; j < k; j++)
                {
                    PII cur = q.top();
                    q.pop();
                    tmp += cur.X;
                    q.push({max(cur.X - cur.Y, 0), cur.Y});
                }
                ans = max(ans, tmp);
            }
        }
        printf("Case #%d: %d\n", ++kase, ans);
    }
    return 0;
}