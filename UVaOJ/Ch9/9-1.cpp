// Longest Run on a Snowboard, UVa10285

/*Sample Input
2
Feldberg 10 5
56 14 51 58 88
26 94 24 39 41
24 16 8 51 51
76 72 77 43 10
38 50 59 84 81
5 23 37 71 77
96 10 93 53 82
94 15 96 69 9
74 0 62 38 96
37 54 55 82 38
Spiral 5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
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

const int maxn = 105;
int tx[] = {1, 0, -1, 0};
int ty[] = {0, 1, 0, -1};

int r, c;
int maze[maxn][maxn];
int dp[maxn][maxn];

int dfs(int x, int y)
{
    if (dp[x][y])
        return dp[x][y];
    for (int i = 0; i < 4; i++)
    {
        int nx = x + tx[i];
        int ny = y + ty[i];
        if (nx < 0 || ny < 0 || nx >= r || ny >= c)
            continue;
        if (maze[nx][ny] < maze[x][y])
            dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
    }
    return dp[x][y];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        clr(dp, 0);
        string str;
        cin >> str >> r >> c;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> maze[i][j];
        int ans = -INF;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                ans = max(ans, dfs(i, j));
        cout << str << ": " << ans + 1 << endl;
    }
    return 0;
}
