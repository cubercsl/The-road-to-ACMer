// 昂贵的聘礼, POJ1062

/*Sample Input
1 4
10000 3 2
2 8000
3 5000
1000 2 1
4 200
3000 2 1
4 200
50 2 0
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
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
int n, m;
int price[maxn], rnk[maxn];
bool vis[maxn];
int G[maxn][maxn], dis[maxn];

int dijk()
{
    clr(dis, 0x3f);
    for (int i = 1; i <= n; i++)
        dis[i] = price[i];
    for (int i = 1; i <= n; i++)
    {
        int x, mindis = INF;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && dis[j] <= mindis)
                x = j, mindis = dis[j];
        }
        vis[x] = true;
        for (int j = 1; j <= n; j++)
            if (!vis[j])
                dis[j] = min(dis[j], dis[x] + G[x][j]);
    }
    // cout << dis[1] << endl;
    return dis[1];
}

int main()
{
    fastin
    cin >> m >> n;
    clr(G, 0x3f);
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> price[i] >> rnk[i] >> t;
        while (t--)
        {
            int id, cost;
            cin >> id >> cost;
            G[id][i] = cost;
        }
    }
    int ans = INF;
    for (int i = 1; i <= n; i++)
    {
        int minlev = rnk[i];
        for (int j = 1; j <= n; j++)
        {
            if (rnk[j] - minlev > m || minlev > rnk[j])
                vis[j] = true;
            else
                vis[j] = false;
        }
        int tmp = dijk();
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
