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

const int N = 55;
char maze[N][N];
int tx[] = {-1, 0, 1, 0};
int ty[] = {0, 1, 0, -1};

int n;
vector<int> G[N * N];
int linker[N * N];
bool used[N * N];

void addedge(int u, int v) { G[u].pb(v); }

bool dfs(int u)
{
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (!used[v])
        {
            used[v] = true;
            if (linker[v] == -1 || dfs(linker[v]))
            {
                linker[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hungary()
{
    int ans = 0;
    clr(linker, -1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if ((i + j) & 1 && maze[i][j] == '#')
            {
                clr(used, 0);
                if (dfs(i * n + j)) ans++;
            }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n * n; i++)
            G[i].clear();
        for (int i = 0; i < n; i++)
            scanf("%s", maze[i]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if ((i + j) & 1 && maze[i][j] == '#')
                    for (int t = 0; t < 4; t++)
                    {
                        int x = i + tx[t], y = j + ty[t];
                        if (x < 0 || y < 0 || x >= n || y >= n || maze[x][y] == '.') continue;
                        addedge(i * n + j, x * n + y);
                    }
        printf("Case %d: %d\n", ++kase, hungary());
    }
    return 0;
}