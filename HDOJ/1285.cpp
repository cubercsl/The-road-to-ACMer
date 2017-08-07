// 确定比赛名次, HDU1285

/*Sample Input
4 3
1 2
2 3
4 3
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

const int maxn = 505;
int ans[maxn];
bool G[maxn][maxn];
int deg[maxn];

void init()
{
    clr(G, 0);
    clr(deg, 0);
    clr(ans, 0);
}

void add_edge(int u, int v)
{
    if (G[u][v]) return;
    G[u][v] = 1;
    deg[v]++;
}

bool toposort(int n)
{
    int tot = 0;
    priority_queue <int, vector<int>, greater<int> > q;
    for (int i = 0; i < n; i++)
        if (deg[i] == 0) q.push(i);
    while (!q.empty())
    {
        int v = q.top();
        q.pop();
        ans[tot++] = v;
        for (int i = 0; i < n; i++)
        {
            if (G[v][i])
                if (--deg[i] == 0) q.push(i);
        }
    }
    if (tot < n) return false;
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (cin >> n >> m)
    {
        init();
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            add_edge(a, b);
        }
        toposort(n);
        for (int i = 0; i < n; i++)
        {
            if (i) cout << " ";
            cout << ans[i] + 1;
        }
        cout << endl;
    }
    return 0;
}
