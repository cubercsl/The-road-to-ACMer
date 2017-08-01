// Arctic Network, POJ2349

/*Sample Input
1
2 4
0 100
0 300
0 600
150 750
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
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

const int maxn = 250000 + 5;
int par[maxn];
vector <double> ans;

void init(int n)
{
    for (int i = 0; i <= n; i++)
        par[i] = i;
}

int find(int x)
{
    if (par[x] != x)
        par[x] = find(par[x]);
    return par[x];
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    par[y] = x;
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

vector <pair<double, PII> > G;
void add_edge(int u, int v, double d)
{
    G.pb(mp(d, mp(u, v)));
}

void kruskal(int n)
{
    init(n);
    sort(G.begin(), G.end());
    int m = G.size();
    int num = 0;
    for (int i = 0; i < m; i++)
    {
        pair <double, PII> p = G[i];
        int x = p.Y.X;
        int y = p.Y.Y;
        double d = p.X;
        if (!same(x, y))
        {
            unite(x, y);
            num++;
            ans.pb(d);
        }
        if (num == n - 1) break;
    }
}

double dis(double x1, double y1, double x2, double y2)
{
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    fastin
    int t;
    cin >> t;
    while (t--)
    {
        pair <double, double> P[505];
        G.clear();
        ans.clear();
        int s, p;
        cin >> s >> p;
        for (int i = 0; i < p; i++)
            cin >> P[i].X >> P[i].Y;
        for (int i = 0; i < p; i++)
            for (int j = i + 1; j < p; j++)
            {
                double d = dis(P[i].X, P[i].Y, P[j].X, P[j].Y);
                add_edge(i, j, d);
                add_edge(j, i, d);
            }
        kruskal(p);
        printf("%.2f\n", ans[p - s - 1]);
    }
    return 0;
}
