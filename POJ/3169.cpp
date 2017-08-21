// Layout, POJ3169

/*Sample Input
4 2 1
1 3 10
2 4 20
2 3 3
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

const int maxn = 1005;
vector <PII> G[maxn];
bool vis[maxn];
int inqueue[maxn], dis[maxn];


void init(int n)
{
    for (int i = 1; i <= n; i++)
        G[i].clear();
}

void add_edge(int u, int v, int w)
{
    G[u].pb(mp(v, w));
}

bool bellman(int s, int n)
{
    clr(vis, 0);
    clr(dis, 0x3f);
    clr(inqueue, 0);
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        vis[x] = false;
        for (int i = 0; i < G[x].size(); i++)
        {
            int y = G[x][i].first;
            int w = G[x][i].second;
            if (dis[y] > dis[x] + w)
            {
                dis[y] = dis[x] + w;
                if (!vis[y])
                {
                    q.push(y);
                    vis[y] = true;
                    if (++inqueue[y] >= n) return 0;
                }
            }
        }
    }
    return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int n, l, d;
    while (cin >> n >> l >> d)
    {
        int u, v, w;
        init(n);
        while (l--)
        {
            cin >> u >> v >> w;
            add_edge(u, v, w);
        }
        while (d--)
        {
            cin >> u >> v >> w;
            add_edge(v, u, -w);
        }
        if (!bellman(1, n))
            cout << -1 << endl;
        else if (dis[n] == INF)
            cout << -2 << endl;
        else
            cout << dis[n] << endl;
    }
    return 0;
}
