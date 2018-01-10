#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;
const int maxn = 505;
vector<PII> G[maxn];
bool vis[maxn];
int dis[maxn];
int inqueue[maxn];
void init(int n)
{
    for (int i = 0; i < n; i++) G[i].clear();
}
void add_edge(int u, int v, int w) { G[u].pb(mp(v, w)); }
bool BellmanFord(int s, int n)
{
    clr(vis, 0), clr(dis, 0x3f), clr(inqueue, 0);
    dis[s] = 0;
    vis[s] = true;
    ++inqueue[s];
    queue<int> q; // 待优化的节点入队
    q.push(s);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        vis[x] = false;
        for (int i = 0; i < G[x].size(); i++)
        {
            int y = G[x][i].X, w = G[x][i].Y;
            if (dis[y] > dis[x] + w)
            {
                dis[y] = dis[x] + w;
                if (!vis[y])
                {
                    q.push(y);
                    vis[y] = true;
                    if (++inqueue[y] >= n) return false;
                }
            }
        }
    }
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int f, n, m, w;
    cin >> f;
    while (f--)
    {
        cin >> n >> m >> w;
        init(n + 1);
        while (m--)
        {
            int u, v, d;
            cin >> u >> v >> d;
            add_edge(u, v, d);
            add_edge(v, u, d);
        }
        while (w--)
        {
            int u, v, d;
            cin >> u >> v >> d;
            add_edge(u, v, -d);
        }
        if (!BellmanFord(1, n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
