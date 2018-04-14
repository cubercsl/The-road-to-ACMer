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

const int N = 505;
char s[N][N];
int d[N][N][2];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) scanf("%s", s[i]);
        clr(d, -1);
        int sx, sy, ex, ey;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (s[i][j] == 'P') sx = i, sy = j;
                if (s[i][j] == 'E') ex = i, ey = j;
            }
        queue<pair<PII, bool> > q;
        q.push({{sx, sy}, 0});
        d[sx][sy][0] = 0;
        while (!q.empty())
        {
            pair<PII, bool> tmp = q.front();
            q.pop();
            int x = tmp.X.X, y = tmp.X.Y;
            bool st = tmp.Y;
            if (x == ex && y == ey && st == 1) break;
            for (int i = 0; i < 4; i++)
            {
                int tx = x + dx[i], ty = y + dy[i];
                if (tx < 0 || ty < 0 || tx >= n || ty >= m || s[tx][ty] == '#') continue;
                if (st == 0 && s[tx][ty] == 'E') continue;
                int ss = st;
                if (s[tx][ty] == 'K') ss = 1;
                if (~d[tx][ty][ss]) continue;
                d[tx][ty][ss] = d[x][y][st] + 1;
                q.push({{tx, ty}, ss});
            }
        }
        if (~d[ex][ey][1])
            cout << d[ex][ey][1] << endl;
        else
            cout << "No solution" << endl;
    }
    return 0;
}