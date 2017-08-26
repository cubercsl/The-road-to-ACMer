#include <cstdio>
#include <vector>
#include <cstring>
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

const int maxn = 1005;
int a[maxn], b[maxn], c[maxn], d[maxn];
PII P[maxn];

int N; //u,v的数目,使用前面必须赋值
int g[maxn][maxn];//邻接矩阵
int linker[maxn], tmp[maxn];
bool used[maxn], _[maxn];
bool dfs(int u)
{
    for (int v = 0; v < N; v++)
        if (g[u][v] && !used[v])
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
    for (int u = 0; u < N; u++)
    {
        clr(used, 0);
        if (dfs(u))res++;
    }
    return res;
}

bool ok()
{
    int num = N;
    for (int i = 0; i < N; i++)
        if (tmp[i] != -1)
        {
            g[tmp[i]][i] = false;
            if (hungary() == N)
            {
                _[i] = true;
                num--;
            }
            g[tmp[i]][i] = true;
        }
    return num;
}

int main()
{
#ifndef ONLINE_JUDGE
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
#endif
    int kase = 0;
    while (~scanf("%d", &N), N)
    {
        for (int i = 0; i < N; i++)
            scanf("%d%d%d%d", a + i, b + i, c + i, d + i);
        for (int i = 0; i < N; i++)
            scanf("%d%d", &P[i].X, &P[i].Y);
        printf("Heap %d\n", ++kase);
        clr(g, 0);
        clr(_, 0);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (a[i] <= P[j].X && b[i] >= P[j].X && c[i] <= P[j].Y && d[i] >= P[j].Y)
                    g[j][i] = true;
        int res = hungary();
        if (res != N)
        {
            puts("none");
            continue;
        }
        for (int i = 0; i < N; i++)
            tmp[i] = linker[i];
        if (ok())
        {
            int fi = 0;
            for (int i = 0; i < N; i++)
            {
                if (_[i]) continue;
                if (fi++) putchar(' ');
                printf("(%c,%d)", 'A' + i, tmp[i] + 1);
            }
            puts("");
        }
        else
            puts("none");
        puts("");
    }
    return 0;
}
