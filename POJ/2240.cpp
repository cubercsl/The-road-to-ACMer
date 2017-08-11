// Arbitrage, POJ2240

/*Sample Input
3
USDollar
BritishPound
FrenchFranc
3
USDollar 0.5 BritishPound
BritishPound 10.0 FrenchFranc
FrenchFranc 0.21 USDollar

3
USDollar
BritishPound
FrenchFranc
6
USDollar 0.5 BritishPound
USDollar 4.9 FrenchFranc
BritishPound 10.0 FrenchFranc
BritishPound 1.99 USDollar
FrenchFranc 0.09 BritishPound
FrenchFranc 0.19 USDollar

0
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
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

const int maxn = 30;
map <string, int> dic;
double G[maxn][maxn];

void init(int n)
{
    clr(G, 0);
    for (int i = 0; i < n; i++)
        G[i][i] = 1;
}

void add_egde(int u, int v, double c)
{
    G[u][v] = c;
}

void floyd(int n)
{
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                G[i][j] = max(G[i][j], G[i][k] * G[k][j]);
}

bool solve(int n)
{
    for (int i = 0; i < n; i++)
        if (G[i][i] > 1)
            return true;
    return false;
}

int main()
{
    fastin
    int n, m, kase = 0;
    string s, u, v;
    double c;
    while (cin >> n, n)
    {
        init(n);
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            dic[s] = i;
        }
        cin >> m;
        while (m--)
        {
            cin >> u >> c >> v;
            add_egde(dic[u], dic[v], c);
        }
        floyd(n);
        cout << "Case " << ++kase << ": ";
        if (solve(n))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
