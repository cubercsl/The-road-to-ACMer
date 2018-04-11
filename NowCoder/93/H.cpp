#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 110;
int dp[N][N][2];
bool inq[N][N][2];
char s[N][N];

struct Node
{
    int x, y;
    bool car;
};

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, k;
        int sx, sy;
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++) scanf("%s", s[i]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (s[i][j] == 'S') sx = i, sy = j;
        queue<Node> q;
        memset(dp, 0x3f, sizeof(dp));
        memset(inq, 0, sizeof(inq));
        q.push({sx, sy, 0});
        inq[sx][sy][0] = 1;
        dp[sx][sy][0] = 0;
        int ans = INF;
        while (!q.empty())
        {
            Node tmp = q.front();
            q.pop();
            int &x = tmp.x, &y = tmp.y;
            bool& car = tmp.car;
            inq[x][y][car] = 0;
            if (s[x][y] == 'X') ans = min(ans, dp[x][y][car]);
            if (car == 0 && s[x][y] == 'C')
            {
                if (dp[x][y][1] > dp[x][y][0])
                {
                    dp[x][y][1] = dp[x][y][0];
                    if (!inq[x][y][1]) q.push({x, y, 1}), inq[x][y][1] = 1;
                }
            }
            for (int i = 0; i < 4; i++)
            {
                int tx = x + dx[i], ty = y + dy[i];
                if (tx < 0 || ty < 0 || tx >= n || ty >= n || s[tx][ty] == 'O') continue;
                int w = 2 - car;
                if (dp[tx][ty][car] > dp[x][y][car] + w)
                {
                    dp[tx][ty][car] = dp[x][y][car] + w;
                    if (!inq[tx][ty][car]) q.push({tx, ty, car}), inq[tx][ty][car] = 1;
                }
            }
        }
        puts(ans > k ? "NO" : "YES");
        if (ans <= k) printf("%d\n", ans);
    }

    return 0;
}