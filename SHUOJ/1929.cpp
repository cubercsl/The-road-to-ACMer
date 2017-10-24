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

inline void floyd(int n)
{
    for (int k = 0; k <= n; k++)
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                G[i][j] = max(G[i][k] + G[k][j], G[i][j]);
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
        int n, p, q, a, b, x;
        scanf("%d%d%d", &n, &p, &q);
        clr(G, 0xc0);
        for (int i = 1; i <= n; i++) G[0][i] = 0;
        while (p--)
        {
            scanf("%d%d", &a, &x);
            G[0][a] = max(G[0][a], x);
        }
        while (q--)
        {
            scanf("%d%d%d", &a, &b, &x);
            G[b][a] = max(G[b][a], x);
        }
        floyd(n);
        printf("%d\n", G[0][1]);
    }
    return 0;
}
