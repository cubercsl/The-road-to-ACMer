// Page Hopping, ACM/ICPC World Final 2000, UVa821

/*Sample Input
1 2   2 4   1 3   3 1   4 3   0 0
1 2   1 4   4 2   2 7   7 1   0 0
0 0
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

const int maxn = 105;
int G[maxn][maxn];
set<int> s;
int n;

void init()
{
    s.clear();
    clr(G, 0x3f);
    for (int i = 0; i < maxn; i++)
        G[i][i] = 0;
}

void add_edge(int u, int v)
{
    s.insert(u - 1);
    s.insert(v - 1);
    G[u - 1][v - 1] = 1;
}

void floyd()
{
    for (int k = 0; k < maxn; k++)
        for (int i = 0; i < maxn; i++)
            for (int j = 0; j < maxn; j++)
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
}

double solve()
{
    floyd();
    int sum = 0, n = s.size();
    for (auto i = s.begin(); i != s.end(); i++)
        for (auto j = s.begin(); j != s.end(); j++)
            sum += G[*i][*j];
    return sum * 1.0 / (n * (n - 1));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int u, v;
    int kase = 0;
    while (cin >> u >> v, u + v)
    {
        init();
        add_edge(u, v);
        while (cin >> u >> v, u + v)
            add_edge(u, v);
        double ans = solve();
        printf("Case %d: average length between pages = %.3f clicks\n", ++kase, ans);
    }
    return 0;
}
