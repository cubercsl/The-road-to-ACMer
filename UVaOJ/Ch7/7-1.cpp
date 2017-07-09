// Firetruck, ACM/ICPC World Finals 1991, UVa208

/*Sample Input
6
1 2
1 3
3 4
3 5
4 6
5 6
2 3
2 4
0 0
4
2 3
3 4
5 1
1 6
7 8
8 9
2 5
5 7
3 1
1 8
4 6
6 9
0 0
*/

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

const int maxn = 22;
int G[maxn][maxn];
bool vis[maxn];
int ans[maxn];
int n, k, cnt;
int par[maxn];

void init(int n)
{
    for (int i = 1; i <= n; i++)
        par[i] = i;
}

int find(int x)
{
    if (par[x] != x)
        par[x] = find(par[x]);
    return par[x];
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    par[x] = y;
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

void dfs(int now, int dep)
{
    ans[dep] = now;
    if (now == k)
    {
        cnt++;
        for (int i = 0; i <= dep; i++)
        {
            if (i)
                printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
        return;
    }
    vis[now] = 1;
    for (int i = 1; i <= n; i++)
        if (!vis[i] && G[now][i])
            dfs(i, dep + 1);
    vis[now] = 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int kase = 0;
    while (scanf("%d", &k) != EOF)
    {
        init(20);
        cnt = 0;
        clr(vis, 0);
        clr(G, 0);
        int a, b;
        while (~scanf("%d%d", &a, &b), a + b)
        {
            G[a][b] = G[b][a] = 1;
            n = max(n, max(a, b));
            unite(a, b);
        }
        printf("CASE %d:\n", ++kase);
        if (same(1, k))
            dfs(1, 0);
        printf("There are %d routes from the firestation to streetcorner %d.\n", cnt, k);
    }
    return 0;
}
