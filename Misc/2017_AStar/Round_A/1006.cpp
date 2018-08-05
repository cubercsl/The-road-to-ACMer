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

const int maxn = 105;
int tx[] = { -1, 0, 1, 0};
int ty[] = {0, -1, 0, 1};
bool vis[maxn][maxn];
bool maze[maxn][maxn];
int n, m;

void dfs(int x, int y, int c)
{
    if (x < 0 || y < 0 || x > n + 1 || y > m + 1) return;
    if (maze[x][y] != c) return;
    if (vis[x][y]) return;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
        dfs(x + tx[i], y + ty[i], c);
}

int main()
{
#ifndef ONLINE_JUDGE
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
#endif
    fastin
    while (cin >> n >> m)
    {
        clr(maze, 0);
        char c;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                cin >> c;
                if (c == '1') maze[i][j] = 1;
            }
        /*for (int i = 0; i <= n + 1; i++)
        {
            for (int j = 0; j <= m + 1; j++)
                cout << maze[i][j];
            cout << endl;
        }*/

        clr(vis, 0);
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i <= n + 1; i++)
            for (int j = 0; j <= m + 1; j++)
                if (maze[i][j] == 0 && vis[i][j] == 0)
                {
                    dfs(i, j, 0);
                    cnt0++;
                }
        clr(vis, 0);
        for (int i = 0; i <= n + 1; i++)
            for (int j = 0; j <= m + 1; j++)
                if (maze[i][j] == 1 && vis[i][j] == 0)
                {
                    dfs(i, j, 1);
                    cnt1++;
                }
        if (cnt0 == 2 && cnt1 == 1)
            cout << 0 << endl;
        else if (cnt0 == 1 && cnt1 == 1)
            cout << 1 << endl;
        else cout << -1 << endl;
    }
    return 0;
}
