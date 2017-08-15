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

const int maxn = 10005;
vector<int> G[maxn];
int deg[maxn];
int cost[maxn];
map<PII, bool> S;

void init(int n)
{
    S.clear();
    for (int i = 0; i < n; i++) G[i].clear();
    for (int i = 0; i < n; i++) cost[i] = 888;
    clr(deg, 0);
}

void add_edge(int u, int v)
{
    if (S[mp(u, v)]) return;
    G[u].pb(v);
    S[mp(u, v)] = 1;
    deg[v]++;
}

int toposort(int n)
{
    int tot = 0;
    int sum = 0;
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (deg[i] == 0) q.push(i);
    while (!q.empty())
    {
        int v = q.front();
        sum += cost[v];
        q.pop();
        tot++;
        for (int i = 0; i < G[v].size(); i++)
        {
            int t = G[v][i];
            if (--deg[t] == 0)
            {
                q.push(t);
                cost[t] = cost[v] + 1;
            }
        }
    }
    if (tot < n) return -1;
    return sum;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
/   freopen("1.out", "w", stdout);
#endif
    fastin
    int n, m;
    while (cin >> n >> m)
    {
        init(n);
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            add_edge(v, u);
        }
        cout << toposort(n) << endl;
    }
    return 0;
}
