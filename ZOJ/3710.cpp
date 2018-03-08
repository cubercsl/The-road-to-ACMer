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

const int N = 100;
bool G[N][N];

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
        int n, m, k;
        clr(G, 0);
        scanf("%d%d%d", &n, &m, &k);
        while (m--)
        {
            static int u, v;
            scanf("%d%d", &u, &v);
            G[u][v] = G[v][u] = 1;
        }
        int cnt = 0;
        for (bool flag = 1; flag;)
        {
            flag = 0;
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++)
                {
                    int s = 0;
                    if (G[i][j] == 1) continue;
                    for (int l = 0; l < n; l++)
                        if (G[i][l] && G[j][l]) s++;
                    if (s >= k) cnt++, G[i][j] = G[j][i] = 1, flag = 1;
                }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
