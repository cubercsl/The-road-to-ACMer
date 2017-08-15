// Going from u to v or from v to u? POJ2762

/*Sample Input
1
3 3
1 2
2 3
3 1
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>
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

template <class T>
inline bool scan(T &ret)
{
    char c;
    int sgn;
    if (c = getchar(), c == EOF) return 0; //EOF
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}

struct Tarjan
{
    vector <int> G[maxn];
    int pre[maxn], lowlink[maxn], sccno[maxn], dfs_clock, scc_cnt;
    stack<int> S;

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
};

struct Toposort
{
    vector <int> G[maxn];
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

    bool toposort(int n)
    {
        int cnt = 0;
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (deg[i] == 0)
            {
                cnt++;
                q.push(i);
            }
        if (cnt > 1) return false;
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            cnt = 0;
            for (int i = 0; i < G[v].size(); i++)
            {
                int t = G[v][i];
                if (--deg[t] == 0)
                {
                    cnt++;
                    q.push(t);
                }
            }
            if (cnt > 1) return false;
        }
        return true;
    }
};

int main()
{
    int t;
    scan(t);
    while (t--)
    {
        Tarjan T;
        int n, m;
        scan(n), scan(m);
        while (m--)
        {
            int u, v;
            scan(u), scan(v);
            T.add_edge(--u, --v);
        }
        T.find_scc(n);
        Toposort DAG;
        DAG.init(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < T.G[i].size(); j++)
            {
                int u = T.sccno[i];
                int v = T.sccno[T.G[i][j]];
                if (u != v)
                    DAG.add_edge(--u, --v);
            }
        }
        if (DAG.toposort(T.scc_cnt)) puts("Yes");
        else puts("No");
    }
    return 0;
}
