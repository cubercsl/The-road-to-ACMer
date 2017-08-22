// Taxi Cab Scheme, POJ2060

/*Sample Input
2
2
08:00 10 11 9 16
08:07 9 16 10 11
2
08:00 10 11 9 16
08:06 9 16 10 11
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
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

const int maxn = 505;
bool G[maxn][maxn];
int n;
int linker[maxn];
bool used[maxn];
bool dfs(int u)
{
    for (int v = 0; v < n; v++)
        if (G[u][v] && !used[v])
        {
            used[v] = true;
            if (linker[v] == -1 || dfs(linker[v]))
            {
                linker[v] = u;
                return true;
            }
        }
    return false;
}
int hungary()
{
    int res = 0;
    clr(linker, -1);
    for (int u = 0; u < n; u++)
    {
        clr(used, 0);
        if (dfs(u))res++;
    }
    return res;
}

int beg[maxn];
int a[maxn], b[maxn], c[maxn], d[maxn];

inline bool judge(int i, int j)
{
    if (i == j) return false;
    int tmp = abs(a[i] - c[i]) + abs(b[i] - d[i]) + beg[i];
    tmp += abs(a[j] - c[i]) + abs(b[j] - d[i]);
    return tmp < beg[j];
}

int main()
{
#ifdef ONLINE_JUDGE
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    int _, h, m, x, y;
    for (scanf("%d", &_); _; _--)
    {
        scanf("%d", &n);
        clr(G, 0);
        for (int i = 0; i < n; i++)
        {
            scanf("%d:%d", &h, &m);
            beg[i] = 60 * h + m;
            scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                G[i][j] = judge(i, j);
        printf("%d\n", n - hungary());
    }
    return 0;
}
