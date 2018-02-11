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

const int N = 1005;
char maze[N][N];
int n, m;

bool ok1(int x, int y)
{
    if (maze[x][y] == '#') return false;
    return ((x - 1 < 0 || maze[x - 1][y] == '#') && (y - 1 < 0 || maze[x][y - 1] == '#'));
}

bool ok2(int x, int y)
{
    if (maze[x][y] == '#') return false;
    return ((x + 1 == n || maze[x + 1][y] == '#') && (y + 1 == m || maze[x][y + 1] == '#'));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (~scanf("%d%d", &n, &m))
    {
        int in = 0, out = 0, cnt = 0;
        for (int i = 0; i < n; i++) scanf("%s", maze[i]);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cnt += maze[i][j] == '.', in += ok1(i, j), out += ok2(i, j);
        printf("%d\n", cnt > 1 ? max(in, out) : 0);
    }
    return 0;
}