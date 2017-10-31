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

const int maxn = 1000;
char maze[maxn][maxn];
int vis[maxn][maxn];
int tx[] = {-1, 0, 1, 0};
int ty[] = {0, -1, 0, 1};

int main()
{
    fastin int n, m, k;
    while (cin >> n >> m >> k)
    {
        clr(vis, -1);
        for (int i = 0; i < n; i++)
            cin >> maze[i];
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        queue<PII> q;
        q.push(mp(x1, y1));
        PII tar = mp(x2, y2);
        vis[x1][y1] = 0;
        bool flag = 1;
        while (!q.empty() && flag)
        {
            PII tmp = q.front();
            q.pop();
            int x = tmp.X, y = tmp.Y;
            for (int i = 0; i < 4 && flag; i++)
            {
                for (int j = 1; j <= k; j++)
                {
                    int nx = x + j * tx[i], ny = y + j * ty[i];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || ~vis[nx][ny]) continue;
                    if (maze[nx][ny] == '#') break;
                    vis[nx][ny] = vis[x][y] + 1;
                    PII Next = mp(nx, ny);
                    if (Next == tar)
                    {
                        flag = 0;
                        break;
                    }
                    q.push(Next);
                }
            }
        }
        cout << vis[x2][y2] << endl;
    }
    return 0;
}
