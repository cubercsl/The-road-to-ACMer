// Fire Net, HDU1045

/*Sample Input
4
.X..
....
XX..
....
2
XX
.X
3
.X.
X.X
.X.
3
...
.XX
.XX
4
....
....
....
....
0
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

int n, ans;
char maze[5][5];

bool ok(int r, int c)
{
    for (int i = r; i >= 0; i--)
    {
        if (maze[i][c] == '0') return false;
        if (maze[i][c] == 'X') break;
    }
    for (int j = c; j >= 0; j--)
    {
        if (maze[r][j] == '0') return false;
        if (maze[r][j] == 'X') break;
    }
    return true;
}

void dfs(int i, int num)
{
    if (i == n * n)
    {
        ans = max(ans, num);
        return;
    }
    int r = i / n;
    int c = i % n;
    if (maze[r][c] == '.' && ok(r, c))
    {
        maze[r][c] = '0';
        dfs(i + 1, num + 1);
        maze[r][c] = '.';
    }
    dfs(i + 1, num);
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    while (cin >> n, n)
    {
        ans = 0;
        for (int i = 0; i < n; i++)
            cin >> maze[i];
        dfs(0, 0);
        cout << ans << endl;
    }
    return 0;
}
