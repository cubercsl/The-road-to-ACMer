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

const int maxn = 105;
int c[maxn][maxn];
int minc[maxn];
bool vis[maxn];
int n;

int prim()
{
    clr(minc, 0x3f);
    clr(vis, 0);
    minc[1] = 0;
    int ans = 0;
    while (1)
    {
        int v = -1;
        for (int u = 1; u <= n; u++)
            if (!vis[u] && (v == -1 || minc[u] < minc[v]))
                v = u;
        if (v == -1)
            break;
        vis[v] = 1;
        ans += minc[v];
        for (int u = 1; u <= n; u++)
            minc[u] = min(minc[u], c[v][u]);
    }
    return ans;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (scanf("%d", &n) != EOF)
    {
        int t = n * (n - 1) / 2;
        while (t--)
        {
            int u, v, cost;
            scanf("%d%d%d", &u, &v, &cost);
            c[v][u] = c[u][v] = cost;
        }
        printf("%d\n",prim());
    }
    return 0;
}
