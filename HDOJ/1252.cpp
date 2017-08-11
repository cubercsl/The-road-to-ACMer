// Hike on a Graph, HDU1252

/*Sample Input
3 1 2 3
r b r
b b b
r b r
2 1 2 2
y g
g y
0
*/

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

const int maxn = 52;
int n, p1, p2, p3;
struct node
{
    int x, y, z;
    node(int _x, int _y, int _z)
    {
        x = _x, y = _y, z = _z;
    }
};

int vis[maxn][maxn][maxn];
char G[maxn][maxn];

int bfs()
{
    clr(vis, -1);
    queue <node> q;
    q.push(node(p1, p2, p3));
    vis[p1][p2][p3] = 0;
    while (!q.empty())
    {
        node tmp = q.front();
        int x = tmp.x;
        int y = tmp.y;
        int z = tmp.z;
        q.pop();
        if (x == y && y == z)
            return vis[x][y][z];
        for (int i = 0; i < n; i++)
        {
            if (vis[i][y][z] == -1 && G[x][i] == G[y][z])
            {
                vis[i][y][z] = vis[x][y][z] + 1;
                q.push(node(i, y, z));
            }
            if (vis[x][i][z] == -1 && G[y][i] == G[x][z])
            {
                vis[x][i][z] = vis[x][y][z] + 1;
                q.push(node(x, i, z));
            }
            if (vis[x][y][i] == -1 && G[z][i] == G[x][y])
            {
                vis[x][y][i] = vis[x][y][z] + 1;
                q.push(node(x, y, i));
            }
        }
    }
    return -1;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    while (cin >> n, n)
    {
        cin >> p1 >> p2 >> p3;
        p1--, p2--, p3--;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> G[i][j];
        int ans = bfs();
        if (ans == -1)
            cout << "impossible" << endl;
        else
            cout << ans << endl;

    }
    return 0;
}
