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

const int N = 1 << 17;
int d[N][2];
int s[N];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
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
        clr(d, -1);
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d", &s[i * m + j]);
        int sx, sy, fx, fy;
        scanf("%d%d%d%d", &sx, &sy, &fx, &fy);
        --sx, --sy, --fx, --fy;
        queue<PII> q;
        int ans = -1;
        d[sx * m + sy][0] = 0;
        q.push({sx * m + sy, 0});
        while (!q.empty())
        {
            PII tmp = q.front();
            q.pop();
            int x = tmp.X / m, y = tmp.X % m;
            int id = tmp.X, tm = tmp.Y;
            if (x == fx && y == fy)
            {
                ans = d[id][tm];
                break;
            }
            int st = s[id];
            if ((tm ^ st) == 0)
            {
                for (int i = 0; i < 2; i++)
                {
                    int tx = x + dx[i], ty = y + dy[i];
                    if (tx < 0 || ty < 0 || tx >= n || ty >= m) continue;
                    int tid = tx * m + ty;
                    if (~d[tid][tm ^ 1]) continue;
                    d[tid][tm ^ 1] = d[id][tm] + 1;
                    q.push({tid, tm ^ 1});
                }
            }
            else
            {
                for (int i = 2; i < 4; i++)
                {
                    int tx = x + dx[i], ty = y + dy[i];
                    if (tx < 0 || ty < 0 || tx >= n || ty >= m) continue;
                    int tid = tx * m + ty;
                    if (~d[tid][tm ^ 1]) continue;
                    d[tid][tm ^ 1] = d[id][tm] + 1;
                    q.push({tid, tm ^ 1});
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
