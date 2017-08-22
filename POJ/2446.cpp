// Chessboard, POJ2446

/*Sample Input
4 3 2
2 1
3 3
*/

#include <iostream>
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

int tx[] = { -1, 0, 1, 0};
int ty[] = {0, 1, 0, -1};

const int maxn = 35 * 35;
int n, m;
vector<int> G[maxn];
int linker[maxn];
bool used[maxn];
bool ish[maxn][maxn];

void addedge(int u, int v)
{
    G[u].pb(v);
}

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
        for (int j = 0; j < m; j++)
            if ((i + j) & 1 && !ish[i][j])
            {
                clr(used, 0);
                if (dfs(i * m + j)) ans++;
            }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int k, x, y;
    while (cin >> n >> m >> k)
    {
        clr(ish, 0);
        for (int i = 0; i < n * m; i++)
            G[i].clear();
        for (int i = 0; i < k; i++)
        {
            cin >> y >> x;
            ish[--x][--y] = true;
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if ((i + j) & 1 && !ish[i][j])
                    for (int t = 0; t < 4; t++)
                    {
                        int x = i + tx[t], y = j + ty[t];
                        if (x < 0 || y < 0 || x >= n || y >= m) continue;
                        if (ish[x][y]) continue;
                        addedge(i * m + j, x * m + y);
                    }
        if (2 * hungary() == n * m - k)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
