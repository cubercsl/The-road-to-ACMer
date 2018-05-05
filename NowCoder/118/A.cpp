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

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (cin >> n)
    {
        vector<vector<int> > v(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) cin >> v[i][j];
        PII s, t;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (v[i][j] == -1)
                    s = {i, j};
                else if (v[i][j] == -2)
                    t = {i, j};
        vector<vector<int> > d(n, vector<int>(n, INF));
        vector<vector<int> > inq(n, vector<int>(n));
        queue<PII> q;
        d[s.X][s.Y] = 0;
        inq[s.X][s.Y] = 1;
        q.push(s);
        while (!q.empty())
        {
            PII u = q.front();
            q.pop();
            int x = u.X, y = u.Y;
            inq[x][y] = 0;
            for (int i = 0; i < 4; i++)
            {
                int tx = x + dx[i], ty = y + dy[i];
                if (tx < 0 || ty < 0 || tx >= n || ty >= n) continue;
                int w = v[tx][ty];
                if (w < 0) w = 0;
                if (d[x][y] + w < d[tx][ty])
                {
                    d[tx][ty] = d[x][y] + w;
                    if (!inq[tx][ty]) q.push({tx, ty}), inq[tx][ty] = 1;
                }
            }
        }
        cout << d[t.X][t.Y] << endl;
    }
    return 0;
}
