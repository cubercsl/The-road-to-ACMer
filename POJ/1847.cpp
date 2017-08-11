// Tram, POJ1847

/*Sample Input
3 2 1
2 2 3
2 3 1
2 1 2
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
int G[maxn][maxn];

void floyd(int n)
{
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
}

int main()
{
    int n, a, b;
    while (cin >> n >> a >> b)
    {
        a--, b--;
        clr(G, 0x3f);
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            bool flag = 0;
            while (k--)
            {
                int j;
                cin >> j;
                j--;
                if (flag) G[i][j] = 1;
                else G[i][j] = 0;
                flag = 1;
            }
        }
        floyd(n);
        if (G[a][b] < INF)
            cout << G[a][b] << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
