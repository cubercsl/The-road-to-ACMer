#include <bits/stdc++.h>
#define input(n) while(cin >> n)
#define input_2(a, b) while(cin >> a >> b)
#define Tcase int T; cin >> T; while(T--)
#define clr(x, y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x & -x)
#define Lson L, mid, node << 1
#define Rson mid + 1, R, node << 1 | 1
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 2010;
int c[maxn][maxn];
int d[maxn];
bool vis[maxn];
int m, n;

void dijk (int s)
{
    clr(d, 0x3f);
    clr(vis, 0);
    d[s] = 0;
    while (1)
    {
        int v = -1;
        for (int u = 1; u <= n; u++)
            if (!vis[u] && (v == -1 || d[u] < d[v]))
                v = u;
        if (v == -1)
            break;
        vis[v] = 1;
        for (int u = 1; u <= n; u++)
            d[u] = min(d[u], d[v] + c[v][u]);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (scanf("%d%d", &m, &n) != EOF)
    {
        clr(c, 0x3f);
        while (m--)
        {
            int a, b, cost;
            scanf("%d%d%d", &a, &b, &cost);
            c[a][b] = c[b][a] = min(cost, c[b][a]);
        }
        dijk(1);
        printf("%d\n", d[n]);
    }
    return 0;
}
