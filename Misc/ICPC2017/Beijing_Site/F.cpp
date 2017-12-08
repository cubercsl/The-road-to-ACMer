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

const int N = 105;
char s[N][N];
char str[N * N];
char t[N][N];
bool vis[N][N];
int tx[] = {0, 1, 0, -1};
int ty[] = {1, 0, -1, 0};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (~scanf("%d", &n))
    {
        clr(vis, 0);
        for (int i = 0; i < n; i++)
            scanf("%s", s[i]);
        int x = 0, y = 0;
        bool flag = 1, ff = 0;
        for (int i = 0; i < n * n; i++)
        {
            // printf("%d %d %d\n", x, y, flag);
            str[i] = s[x][y];
            if ((x == 0 || x == n - 1) && flag && y + 1 != n)
                y++, flag = 0, ff ^= 1;
            else if ((y == 0 || y == n - 1) && flag && x + 1 != n)
                x++, flag = 0, ff ^= 1;
            else if (ff)
                x++, y--, flag = 1;
            else
                x--, y++, flag = 1;
        }
        t[0][0] = str[0];
        vis[0][0] = 1;
        int dir = 0;
        x = 0, y = 0;
        for (int i = 1; i < n * n; i++)
        {
            int nx = x + tx[dir], ny = y + ty[dir];
            if (nx >= n || ny >= n || nx < 0 || ny < 0 || vis[nx][ny]) (++dir) %= 4;
            x += tx[dir], y += ty[dir];
            vis[x][y] = 1;
            t[x][y] = str[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                printf("%c", t[i][j]);
            printf("\n");
        }
    }
    return 0;
}
