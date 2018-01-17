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
char maze[N][N];
int cnt[N][N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (cin >> n >> m, n + m)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> maze[i][j];
        clr(cnt, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (maze[i][j] == 'x') continue;
                for (int ii = -1; ii <= 1; ii++)
                    for (int jj = -1; jj <= 1; jj++)
                    {
                        if (i + ii < 0 || i + ii >= n || j + jj < 0 || j + jj >= m) continue;
                        cnt[i][j] += (maze[i + ii][j + jj] == 'x');
                    }
            }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (maze[i][j] == 'x')
                    cout << 'x';
                else
                    cout << cnt[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
