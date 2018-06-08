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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    while (cin >> n >> m)
    {
        int d = 0;
        vector<VI> vis(n, VI(n));
        int x = 0, y = 0;
        vis[x][y] = true;
        while (m--)
        {
            vis[x][y] = true;
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= n || ny >= n || nx < 0 || ny < 0 || vis[nx][ny]) (++d) %= 4;
            nx = x + dx[d], ny = y + dy[d];
            x = nx, y = ny;
        }
        cout << x + 1 << " " << y + 1 << endl;
    }
    return 0;
}
