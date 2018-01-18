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
int G[N][N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (cin >> n >> m, n + m)
    {
        clr(G, 0x3f);
        for (int i = 0; i < n; i++) G[i][i] = 0;
        while (m--)
        {
            static int u, v, c;
            cin >> u >> v >> c;
            G[u][v] = G[v][u] = min(G[u][v], c);
        }
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j && G[i][j] != INF)
                    ans = max(ans, G[i][j]);
        cout << ans << endl;
    }
    return 0;
}
