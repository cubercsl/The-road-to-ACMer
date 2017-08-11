// Cow Contest, POJ3660

/*Sample Input
5 5
4 3
4 2
3 2
1 2
2 5
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
bool G[maxn][maxn];

void floyd(int n)
{
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                G[i][j] |= G[i][k] & G[k][j];
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        clr(G, 0);
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            G[u][v] = 1;
        }
        floyd(n);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int tmp = 0;
            for (int j = 0; j < n; j++)
                if (G[i][j] | G[j][i])
                    tmp++;
            if (tmp == n - 1)cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
