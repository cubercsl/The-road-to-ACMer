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
int n, m;
bool vis[maxn][maxn];
bool flag;
int tx[] = {1, 0, -1, 0};
int ty[] = {0, 1, 0, -1};

void dfs(int x, int y)
{
    if (flag)
        return;
    if (x == n - 1 && y == m - 1)
    {
        flag = 1;
        return;
    }
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = t + tx[i];
        int ny = y + ty[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny])
            continue;
        dfs(nx, ny);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    intput_2(n, m)
    {
        clr(vis, 0);
        flag = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> vis[i][j];
        dfs(0, 0);
        if (flag)
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }
    return 0;
}
