// Roadblocks, POJ3255

/*Sample Input
4 4
1 2 100
2 4 200
2 3 250
3 4 100
*/

#include <iostream>
#include <vector>
#include <queue>
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

const int maxn = 1e5 + 5;
typedef vector <PII> VII;
VII G[maxn];
int dis[maxn], dis2[maxn];

void init(int n)
{
    for (int i = 1; i <= n; i++)
        G[i].clear();
}

void add_edge(int u, int v, int w)
{
    G[u].pb(mp(w, v));
}

void dijk(int s, int n)
{
    clr(dis, 0x3f);
    clr(dis2, 0x3f);
    dis[s] = 0;
    priority_queue<PII, VII, greater<PII> >q;
    q.push(mp(dis[s], s));
    while (!q.empty())
    {
        PII tmp = q.top();
        q.pop();
        int x = tmp.Y;
        int w = tmp.X;
        if (dis2[x] < w)
            continue;
        for (int i = 0; i < (int)G[x].size(); i++)
        {
            int y = G[x][i].Y;
            int w2 = w + G[x][i].X;
            if (dis[y] > w2)
            {
                swap(dis[y], w2);
                q.push(mp(dis[y], y));
            }
            if (dis2[y] > w2 && dis[y] < w2)
            {
                dis2[y] = w2;
                q.push(mp(dis2[y], y));
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int n, r;
    cin >> n >> r;
    init(n);
    while (r--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add_edge(a, b, c);
        add_edge(b, a, c);
    }
    dijk(1, n);
    cout << dis2[n] << endl;
    return 0;
}
