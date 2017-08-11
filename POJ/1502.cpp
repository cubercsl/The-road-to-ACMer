// MPI Maelstrom, POJ1502

/*Sample Input
5
50
30 5
100 20 50
10 x x 10
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
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

const int maxn = 102;
typedef vector<PII> VII;
VII G[maxn];
int dis[maxn];
bool vis[maxn];

void init(int n)
{
    for (int i = 0; i < n; i++)
        G[i].clear();
}

void add_edge(int u, int v, int w)
{
    G[u].pb(mp(w, v));
    G[v].pb(mp(w, u));
}

void Dijk(int s, int n)
{
    clr(dis, 0x3f);
    clr(vis, 0);
    dis[s] = 0;
    priority_queue<PII, VII, greater<PII> > q;
    q.push(mp(dis[s], s));
    while (!q.empty())
    {
        PII t = q.top();
        int x = t.Y;
        q.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        for (int i = 0; i < G[x].size(); i++)
        {
            int y = G[x][i].Y;
            int w = G[x][i].X;
            if (!vis[y] && dis[y] > dis[x] + w)
            {
                dis[y] = dis[x] + w;
                q.push(mp(dis[y], y));
            }
        }
    }
}

int getdis(char* s)
{
    int ret = 0, n = strlen(s);
    for (int i = 0; i < n; i++)
        ret = ret * 10 + s[i] - '0';
    return ret;
}

int main()
{
    int n;
    while (cin >> n)
    {
        char s[10];
        init(n);
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
            {
                cin >> s;
                if (s[0] == 'x')
                    continue;
                int d = getdis(s);
                add_edge(i, j, d);
            }
        Dijk(0, n);
        cout << *max_element(dis, dis + n) << endl;
    }
    return 0;
}
