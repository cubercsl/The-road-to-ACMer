// Task Sequences, POJ1777

/*Sample Input
3
0 1 1
1 0 1
0 0 0
*/

#include <cstdio>
#include <cstring>
#include <vector>
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

const int maxn = 1005;
bool G[maxn][maxn];
bool vis[maxn];
int path[maxn];
char s[2500];
int n;

bool dfs(int u, int dep)
{
    path[dep] = u + 1;
    if (dep == n - 1)
        return true;
    vis[u] = true;
    for (int i = 0; i < n; i++)
        if (G[u][i] && !vis[i])
        {
            if (dfs(i, dep + 1))
                return true;
            vis[i] = false;
        }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (~scanf("%d", &n))
    {
        getchar();
        for (int i = 0; i < n; i++)
        {
            gets(s);
            for (int j = 0; j < n; j++)
                G[i][j] = s[j << 1] - '0';
        }
        for (int i = 0; i < n; i++)
        {
            clr(vis, 0);
            if (dfs(i, 0))
                break;
        }
        printf("1\n%d\n", n);
        for (int i = 0; i < n; i++)
            printf("%d%c", path[i], i == n - 1 ? '\n' : ' ');
    }
    return 0;
}
