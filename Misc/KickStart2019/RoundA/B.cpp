#include <bits/stdc++.h>
using namespace std;

const int N = 300;
const int INF = 0x3f3f3f3f;

char s[N][N];
int d[N][N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

inline void upmax(int& x, int y) { x < y ? x = y : 0; }
inline void upmin(int& x, int y) { x > y ? x = y : 0; }

bool check(int n, int m, int mid)
{
    int maxx = -INF, maxy = -INF;
    int minx = INF, miny = INF;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (d[i][j] > mid || d[i][j] == -1)
            {
                int x = i + j;
                int y = i - j;
                upmax(maxx, x - mid);
                upmax(maxy, y - mid);
                upmin(minx, x + mid);
                upmin(miny, y + mid);
            }
    if(maxx > minx || maxy > miny) return false;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int x = i + j;
            int y = i - j;
            if (maxx <= x && x <= minx && maxy <= y && y <= miny) return true;
        }
    return false;
}

int main()
{
    int T, kase = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) scanf("%s", s[i]);
        queue<pair<int, int>> q;
        memset(d, -1, sizeof(d));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (s[i][j] == '1') q.push({i, j}), d[i][j] = 0;
        while (!q.empty())
        {
            auto t = q.front();
            q.pop();
            int x, y;
            tie(x, y) = t;
            for (int i = 0; i < 4; i++)
            {
                int tx = x + dx[i];
                int ty = y + dy[i];
                if (tx < 0 || ty < 0 || tx >= n || ty >= m || ~d[tx][ty]) continue;
                d[tx][ty] = d[x][y] + 1;
                q.push({tx, ty});
            }
        }
        int l = 0, r = n + m;
        int ans;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (check(n, m, mid))
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        printf("Case #%d: %d\n", ++kase, ans);
    }
}