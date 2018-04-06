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
bool vis[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
int n, m;
void dfs(int x, int y, const char& c)
{
    if (x < 0 || y < 0 || x >= n || y >= m) return;
    if (vis[x][y] || s[x][y] == '.') return;
    if (s[x][y] != c)
    {
        cout << "No";
        exit(0);
    }
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) dfs(x + dx[i], y + dy[i], c);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> s[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] != '.' && !vis[i][j])
                dfs(i, j, s[i][j]);
    cout << "Yes" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '.')
                cout << "D";
            else
                cout << s[i][j];
        }
        cout << endl;
    }
    return 0;
}
