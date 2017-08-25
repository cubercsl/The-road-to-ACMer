// 炮兵阵地, POJ1185

/*Sample Input
5 4
PHPP
PPHH
PPPP
PHPP
PHHP
*/

#include <iostream>
#include <vector>
#include <cstring>
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

const int maxn = 105;
int dp [maxn][maxn][maxn];
int maze[maxn];
vector<int> v, sum;

inline bool ok(int s)   //状态是否符合条件
{
    return !(s & (s << 1)) && !(s & (s << 2));
}

inline int getsum(int s)   //状态的人数
{
    int ret = 0;
    for (; s; s >>= 1)
        if (s & 1) ret++;
    return ret;
}

void init(int m)    //预处理符合条件的状态
{
    for (int i = 0; i < (1 << m); i++)
        if (ok(i))
        {
            v.pb(i);
            sum.pb(getsum(i));
        }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    char tmp;
    cin >> n >> m;
    init(m);
    clr(dp, 0xc0);
    for (int i = 0; i < n; i++)
        for (int j = 0 ; j < m ; j++)
        {
            cin >> tmp;
            if (tmp == 'H')
                maze[i] |= (1 << j);
        }
    for (int i = 0; i < v.size(); i++)
        if (!(v[i]&maze[0]))    //该状态符合条件
            dp[0][0][i] = sum[i];
    for (int r = 1; r < n; r++)
        for (int i = 0; i < v.size(); i++)
            if (!(v[i]&maze[r]))
                for (int j = 0; j < v.size(); j++)
                    if (!(v[i]&v[j]))
                        for (int k = 0; k < v.size(); k++)
                            if (!(v[i]&v[k]))
                                dp[r][j][i] = max(dp[r][j][i], dp[r - 1][k][j] + sum[i]);
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
        for (int j = 0; j < v.size(); j++)
            ans = max(ans, dp[n - 1][i][j]);
    cout << ans << endl;
    return 0;
}
