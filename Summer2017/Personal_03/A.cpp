#include <bits/stdc++.h>
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

const int maxn = 805;
int n, m;
char maze[maxn][maxn];
int vis[maxn][maxn];
int tx[] = { -1, 0, 1, 0};
int ty[] = {0, -1, 0, 1};


void bfs()
{
    clr(vis, -1);
    queue<PII> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (maze[i][j] == '0')
            {
                vis[i][j] = 0;
                q.push(mp(i, j));
            }
    while (!q.empty())
    {
        PII tmp = q.front();
        q.pop();
        int x = tmp.X;
        int y = tmp.Y;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + tx[i];
            int ny = y + ty[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] != -1) continue;
            vis[nx][ny] = vis[x][y] + 1;
            q.push(mp(nx, ny));
        }
    }
}

int main()
{
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> maze[i][j];
        bfs();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (j) cout << " ";
                cout << vis[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
