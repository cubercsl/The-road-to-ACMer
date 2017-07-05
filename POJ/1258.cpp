// Agri-Net, POJ1258

/*Sample Input
4
0 4 9 21
4 0 8 17
9 8 0 16
21 17 16 0
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
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
bool vis[maxn];
int dp[maxn];
int c[maxn][maxn];
int prim(int n)
{
    int ans = 0;
    clr(dp, 0x3f);
    clr(vis, 0);
    vis[0] = 1;
    for (int i = 1; i < n; i++)
        dp[i] = c[0][i];
    for (int i = 1; i < n; i++)
    {
        int tmp = INF;
        int p = -1;
        for (int j = 0; j < n; j++)
            if (!vis[j] && tmp > dp[j])
                tmp = dp[j], p = j;
        if (tmp == INF) return -1;
        ans += tmp;
        vis[p] = 1;
        for (int j = 0; j < n; j++)
            if (!vis[j])
                dp[j] = min(dp[j], c[p][j]);
    }
    return ans;

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> c[i][j];
        cout << prim(n) << endl;
    }
    return 0;
}
