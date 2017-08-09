// Frogger, POJ2253

/*Sample Input
2
0 0
3 4

3
17 4
19 4
18 5

0
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
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

const int maxn = 205;
PII P[maxn];
typedef pair<double, PII> edge;
vector <edge> G;
int par[maxn];

void init(int n)
{
    for (int i = 0; i < n; i++)
        par[i] = i;
}

int find(int x)
{
    if (par[x] != x) par[x] = find(par[x]);
    return par[x];
}

void unite (int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return;
    par[y] = x;
}

bool same(int x, int y)
{
    return find(x) == find(y);
}


void add_edge(int u, int v, double d)
{
    G.pb(mp(d, mp(u, v)));
}

double dis(PII a, PII b)
{
    double dx = a.X - b.X, dy = a.Y - b.Y;
    return sqrt(dx * dx + dy * dy);
}

double solve(int n)
{
    init(n);
    sort(G.begin(), G.end());
    for (int i = 0; i < G.size(); i++)
    {
        edge p = G[i];
        int x = p.Y.X;
        int y = p.Y.Y;
        double d = p.X;
        unite(x, y);
        if (same(0, 1))
            return d;
    }
}

int main()
{
    int n, kase = 0;
    while (~scanf("%d", &n), n)
    {
        G.clear();
        for (int i = 0; i < n; i++)
            scanf("%d%d", &P[i].X, &P[i].Y);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                add_edge(i, j, dis(P[i], P[j]));
        printf("Scenario #%d\n", ++kase);
        printf("Frog Distance = %.3f\n\n", solve(n));
    }
    return 0;
}
