// FFF at Valentine, 2017 Multi-University Training Contest, HDU6165

/*Sample Input
3
5 5
1 2
2 3
2 4
3 5
4 5

3 3
1 2
2 3
3 1

5 5
1 2
2 3
3 1
3 4
4 5
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

const int maxn  = 1005;
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

struct DAG
{
    vector<int> G[maxn];
    int deg[maxn];
    map<PII, bool> S;
    void init(int n)
    {
        S.clear();
        for (int i = 0; i < n; i++) G[i].clear();
        clr(deg, 0);
    }

    void add_edge(int u, int v)
    {
        if (S[mp(u, v)]) return;
        G[u].pb(v);
        S[mp(u, v)] = 1;
        deg[v]++;

    }

    bool Toposort(int n)
    {
        int tot = 0;
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (deg[i] == 0) q.push(i);
        if (q.size() > 1) return false;
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int i = 0; i < G[v].size(); i++)
            {
                int t = G[v][i];
                if (--deg[t] == 0) q.push(t);
            }
            if (q.size() > 1) return false;
        }
        return true;
    }
}ans;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m, u, v;
        scanf("%d%d", &n, &m);
        init(n);
        while (m--)
        {
            scanf("%d%d", &u, &v);
            add_edge(u - 1, v - 1);
        }
        find_scc(n);
        ans.init(scc_cnt);
        for(int u=0;u<n;u++)
        {
            for(auto & v : G[u])
                if(sccno[u]!=sccno[v])
                    ans.add_edge(sccno[u]-1,sccno[v]-1);
        }
        if(ans.Toposort(scc_cnt))
            printf("I love you my love and our love save us!\n");
        else
            printf("Light my fire!\n");
    }
    return 0;
}
