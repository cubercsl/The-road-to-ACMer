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

int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

const int N = 105;
int r, c;
char maze[N][N];
vector<PII> gold;
vector<PII> rally;
int d[55][N][N];

void bfs(const PII& s, int id)
{
    d[id][s.X][s.Y] = 0;
    queue<PII> q;
    q.push(s);
    while (!q.empty())
    {
        PII tmp = q.front();
        q.pop();
        int &x = tmp.X, &y = tmp.Y;
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx < 0 || ty < 0 || tx >= r || ty >= c || ~d[id][tx][ty] || maze[tx][ty] == '#') continue;
            d[id][tx][ty] = d[id][x][y] + 1;
            q.push({tx, ty});
        }
    }
}

vector<int> G[N];
int linker[N * N];
bool used[N * N];
inline void addedge(int u, int v) { G[u].pb(v); }
bool dfs(int u)
{
    for (auto& v : G[u])
    {
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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    while (~scanf("%d%d", &r, &c))
    {
        gold.clear();
        rally.clear();
        for (int i = 0; i < r; i++)
        {
            scanf("%s", maze[i]);
            for (int j = 0; j < c; j++)
            {
                if (maze[i][j] == '*')
                    gold.push_back({i, j});
                else if (isalpha(maze[i][j]))
                    rally.push_back({i, j});
            }
        }
        sort(rally.begin(), rally.end(), [](const PII& a, const PII& b) {
            return maze[a.X][a.Y] < maze[b.X][b.Y];
        });
        int n = rally.size(), m = gold.size();

        clr(d, -1);
        for (int i = 0; i < n; i++) bfs(rally[i], i), G[i].clear();

        bool flag = n == 1;
        for (int i = 1; i < n; i++)
        {
            int &x = rally[i].X, &y = rally[i].Y;
            if (~d[i - 1][x][y]) continue;
            flag = true;
            break;
        }

        if (flag)
        {
            puts("-1");
            continue;
        }

        for (int i = 0; i < n - 1; i++)
        {
            int &rx = rally[i + 1].X, &ry = rally[i + 1].Y;
            for (int j = 0; j < m; j++)
            {
                int &x = gold[j].X, &y = gold[j].Y;
                if (d[i][x][y] + d[i + 1][x][y] == d[i][rx][ry]) addedge(i, j);
            }
        }
        int ans = 0;
        clr(linker, -1);
        for (int u = 0; u < n; u++)
        {
            clr(used, 0);
            if (dfs(u)) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}