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

const int N = 505;
vector<int> G[N];
vector<int> Deg;
set<PII> s;

inline void add_edge(int u, int v)
{
    if (s.find({u, v}) != s.end()) return;
    G[u].pb(v);
    Deg[v]++;
}

bool toposort(int n, vector<int>& deg)
{
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (deg[i] <= 0) q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : G[u])
        {
            if (--deg[v] == 0)
                q.push(v);
        }
    }
    for (auto d : deg)
        if (d > 0) return false;
    return true;
}

bool solve(int n)
{
    for (int i = 0; i < n; i++)
    {
        vector<int> deg;
        deg = Deg;
        --deg[i];
        if (toposort(n, deg)) return true;
    }
    return false;
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
        for (int i = 0; i < n; i++) G[i].clear();
        Deg.resize(n);
        s.clear();
        while (m--)
        {
            static int u, v;
            scanf("%d%d", &u, &v);
            --u, --v;
            add_edge(u, v);
        }
        puts(solve(n) ? "YES" : "NO");
    }
    return 0;
}
