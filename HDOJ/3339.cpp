// In Action, HDU3339

/*Sample Input
2
2 3
0 2 9
2 1 3
1 0 2
1
3
2 1
2 1 3
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

const int maxn = 105;
int G[maxn][maxn], P[maxn];
int dp[100005];

void init(int n)
{
    clr(G, 0x3f);
}

void floyd(int n)
{
    for (int k = 0; k <= n; k++)
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                G[i][j] = min(G[i][k] + G[k][j], G[i][j]);
}

void judge(int V, double limit)
{
    for (int i = 1; i <= V; i++)
        if (dp[i] > limit)
        {
            cout << i << endl;
            return;
        }
    cout << "impossible" << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int T, n, m;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        init(n);
        while (m--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            G[u][v] = G[v][u] = min(G[u][v], w);
        }
        floyd(n);
        int sum = 0, V = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> P[i];
            sum += P[i];
            if (G[0][i] != INF)
                V += G[0][i];
        }
        clr(dp, 0);
        for (int i = 1; i <= n; i++)
            if (G[0][i] != INF)
                for (int j = V; j >= G[0][i]; j--)
                    dp[j] = max(dp[j - G[0][i]] + P[i], dp[j]);
        judge(V, sum / 2.0);
    }
    return 0;
}
