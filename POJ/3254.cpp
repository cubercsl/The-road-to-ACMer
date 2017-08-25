// Corn Fields, POJ3254

/*Sample Input
2 3
1 1 1
0 1 0
*/

#include <iostream>
#include <vector>
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
const int mod = 1e9;
const double eps = 1e-6;

const int maxn = 13;
int dp[maxn][1 << maxn];
bool maze[maxn][maxn];
vector <int> v;
int n, m;

bool ok(int x, int state)
{
    for (int i = 0; i < m; i++)
        if ((state & (1 << i)) && !maze[x][i])
            return false;
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 0; i < (1 << m); i++)
        if ((i & i << 1) == 0)
            v.pb(i);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> maze[i][j];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (!ok(i, v[j])) continue;
            if (i == 0)
            {
                dp[i][j] = 1;
                continue;
            }
            for (int k = 0; k < v.size(); k++)
                if ((v[j]&v[k]) == 0)
                    dp[i][j] += dp[i - 1][k];
        }
    }
    ll ans = 0;
    for (int i = 0; i < v.size(); i++)
        ans = (ans + dp[n - 1][i]) % mod;
    cout << ans << endl;
    return 0;
}
