#include <bits/stdc++.h>
#define input(n) while(cin >> n)
#define input_2(a, b) while(cin >> a >> b)
#define Tcase int T; cin >> T; while(T--)
#define clr(x, y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x & -x)
#define Lson L, mid, node << 1
#define Rson mid + 1, R, node << 1 | 1
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 102;
char maze[maxn][maxn];
bool vis[maxn][maxn];
int n, m;

void dfs(int x, int y, int id)
{
    vis[x][y] = 0;
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
            if (x + i < 0 || y + j < 0 || x + i >= n || y + j >= m || vis[x + i][y + j] == 0)
                continue;
            else
                dfs(x + i, y + j, id);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (cin >> n >> m, n && m)
    {
        clr(vis, 0);
        for (int i = 0; i < n; i++)
            cin >> maze[i];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (maze[i][j] == '@')
                    vis[i][j] = 1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (vis[i][j])
                    dfs(i, j, cnt++);
        cout << cnt << endl;
    }
    return 0;
}
