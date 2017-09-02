#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>
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

const int maxn = 505 << 1;
PII node[505];

vector <int> G[maxn];
int pre[maxn], lowlink[maxn], sccno[maxn], dfs_clock, scc_cnt;
stack<int> S;
void init(int n)
{
    for (int i = 0; i < n; i++)
        G[i].clear();
}
void add_edge(int u, int v)
{
    G[u].pb(v);
    G[v].pb(u);
}
void dfs(int u)
{
    pre[u] = lowlink[u] = ++dfs_clock;
    S.push(u);
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (!pre[v])
        {
            dfs(v);
            lowlink[u] = min(lowlink[u], lowlink[v]);
        }
        else if (!sccno[v])
            lowlink[u] = min(lowlink[u], pre[v]);
    }
    if (lowlink[u] == pre[u])
    {
        scc_cnt++;
        for (;;)
        {
            int x = S.top();
            S.pop();
            sccno[x] = scc_cnt;
            if (x == u) break;
        }
    }
}
void find_scc(int n)
{
    dfs_clock = 0, scc_cnt = 0;
    clr(sccno, 0);
    clr(pre, 0);
    for (int i = 0; i < n; i++)
        if (!pre[i]) dfs(i);
}

bool check(int m)
{
    for (int i = 0; i < m; i++)
        if (sccno[i] == sccno[i + m])
            return false;
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        init(m << 1);
        for (int i = 0; i < m; i++)
        {
            int s, t;
            scanf("%d%d", &s, &t);
            if (s > t) swap(s, t);
            node[i] = mp(s, t);
            for (int j = 0; j < i; j++)
            {
                if (node[j].X < s && node[j].Y > s && node[j].Y < t ||
                        node[j].X > s && node[j].X < t && node[j].Y > t)
                {
                    add_edge(i, m + j);
                    add_edge(j, m + i);
                }
            }
        }
        find_scc(m << 1);
        puts(check(m) ? "panda is telling the truth..." : "the evil panda is lying again");
    }
    return 0;
}
