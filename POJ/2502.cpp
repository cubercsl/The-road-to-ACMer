// Subway, POJ2502

/*Sample Input
0 0 10000 1000
0 200 5000 200 7000 200 -1 -1
2000 600 5000 600 10000 600 -1 -1
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
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

const int maxn = 205;
const double subway = 40 * 1000 / 60;
const double walk = 10 * 1000 / 60;

double get_dis(PII a, PII b)
{
    double dx = a.X - b.X, dy = a.Y - b.Y;
    return sqrt(dx * dx + dy * dy);
}

typedef pair<double, int> edge;
vector<edge> G[maxn];
PII P[maxn];
bool vis[maxn];
double dis[maxn];

void add_edge(int u, int v, double w)
{
    G[u].pb(mp(w, v));
    G[v].pb(mp(w, u));
}

void Dijk(int s, int n)
{
    clr(vis, 0);
    for (int i = 0; i < n; i++)
        dis[i] = INF;
    dis[s] = 0;
    priority_queue<edge, vector<edge>, greater<edge> >q;
    q.push(mp(dis[s], s));
    while (!q.empty())
    {
        edge t = q.top();
        int x = t.Y;
        q.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        for (int i = 0; i < G[x].size(); i++)
        {
            int y = G[x][i].Y;
            double w = G[x][i].X;
            if (!vis[y] && dis[y] > dis[x] + w)
            {
                dis[y] = dis[x] + w;
                q.push(mp(dis[y], y));
            }
        }
    }
}

int main()
{
    cin >> P[0].X >> P[0].Y >> P[1].X >> P[1].Y;
    int n = 2;
    while (cin >> P[n].X >> P[n].Y)
    {
        n++;
        while (cin >> P[n].X >> P[n].Y)
        {
            if (P[n].X == -1) break;
            add_edge(n, n - 1, get_dis(P[n], P[n - 1]) / subway);
            n++;
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            add_edge(i, j, get_dis(P[i], P[j]) / walk);
    Dijk(0, n);
    cout << (int)(dis[1] + 0.5) << endl;
    return 0;
}
