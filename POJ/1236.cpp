// Network of Schools, POJ1236

/*Sample Input
5
2 4 3 0
4 5 0
0
0
1 0
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
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

const int maxn = 105;

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

int in[maxn], out[maxn];
int main()
{
    int n;
    scan(n);
    for (int i = 0; i < n; i++)
    {
        int v;
        while (scan(v), v)
            add_edge(i, --v);
    }
    find_scc(n);
    if (scc_cnt == 1)
    {
        printf("1\n0\n");
        return 0;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < G[i].size(); j++)
        {
            int u = sccno[i];
            int v = sccno[G[i][j]];
            if (u != v)
                in[v]++, out[u]++;
        }
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= scc_cnt; i++)
    {
        if (in[i] == 0) ans1++;
        if (out[i] == 0) ans2++;
    }
    printf("%d\n%d\n", ans1, max(ans1, ans2));
    return 0;
}
