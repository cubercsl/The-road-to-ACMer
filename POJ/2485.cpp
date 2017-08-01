// Highways, POJ2485

/*Sample Input
1

3
0 990 692
990 0 179
692 179 0
*/

#include <iostream>
#include <cstring>
#include <vector>
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

int n;
const int maxn = 505;
int v[maxn][maxn];
bool vis[maxn];
int c[maxn];

int prim()
{
    int ans = 0;
    clr(vis, 0);
    vis[0] = 1;
    for (int i = 1; i < n; i++)
        c[i] = v[0][i];
    for (int i = 1; i < n; i++)
    {
        int minc = INF;
        int p = -1;
        for (int j = 0; j < n; j++)
            if (!vis[j] && minc > c[j])
                minc = c[j], p = j;
        if (minc == INF) return -1;
        vis[p] = 1;
        ans = max(ans, minc);
        for (int j = 0; j < n; j++)
            if (!vis[j] && c[j] > v[p][j])
                c[j] = v[p][j];
    }
    return ans;
}

int main()
{
    fastin
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> v[i][j];
        cout << prim() << endl;
    }
    return 0;
}
