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

const int maxn = 105;
int G[maxn][maxn];
int E[maxn][maxn];

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
        int n, m, s, e;
        scanf("%d%d%d%d", &n, &m, &s, &e);
        s--, e--;
        clr(G, 0x3f);
        clr(E, 0);
        while (m--)
        {
            int u, v, a, b;
            scanf("%d%d%d%d", &u, &v, &a, &b);
            u--, v--;
            G[u][v] = G[v][u] = a;
            E[u][v] = E[v][u] = b;
        }
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (G[i][j] > G[i][k] + G[k][j])
                        G[i][j] = G[i][k] + G[k][j], E[i][j] = E[i][k] + E[k][j];
                    else if (G[i][j] == G[i][k] + G[k][j])
                        E[i][j] = max(E[i][j], E[i][k] + E[k][j]);
        printf("%d %d\n", G[s][e], E[s][e]);
    }
    return 0;
}