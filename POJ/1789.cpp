// Truck History, POJ1789

/*Sample Input
aaaaaaa
baaaaaa
abaaaaa
aabaaaa
*/

#include <iostream>
#include <vector>
#include <algorithm>
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

const int maxn = 2005;
string s[maxn];
bool vis[maxn];
int lowc[maxn];
int dis[maxn][maxn];
int n;

int calc(int x, int y)
{
    int cnt = 0;
    for (int i = 0; i < s[x].length(); i++)
        if (s[x][i] != s[y][i])
            cnt++;
    return cnt;
}

int prim()
{
    int ans = 0;
    clr(vis, 0);
    vis[0] = 1;
    for (int i = 1; i < n; i++)
        lowc[i] = dis[0][i];
    for (int i = 1; i < n; i++)
    {
        int minc = INF;
        int p = -1;
        for (int j = 0; j < n; j++)
            if (!vis[j] && minc > lowc[j])

                minc = lowc[j], p = j;
        if (minc == INF)return -1;
        vis[p] = 1;
        ans += minc;
        for (int j = 0; j < n; j++)
            if (!vis[j] && lowc[j] > dis[p][j])
                lowc[j] = dis[p][j];
    }
    return ans;
}

int main()
{
    fastin
    while (cin >> n, n)
    {
        clr(dis, 0);
        for (int i = 0; i < n; i++)
            cin >> s[i];
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                dis[i][j] = dis[j][i] = calc(i, j);
        int ans = prim();
        cout << "The highest possible quality is 1/" << ans << "." << endl;
    }
    return 0;
}
