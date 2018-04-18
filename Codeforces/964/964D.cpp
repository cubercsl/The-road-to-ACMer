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

const int N = 1 << 18;
vector<int> G[N];
int deg[N], d[N];
bool vis[N];
void dfs(int u, int fa, int dep)
{
    d[u] = dep;
    for (auto& v : G[u])
        if (v != fa) dfs(v, u, dep + 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    cin >> n;
    int rt = 0;
    for (int i = 1; i <= n; i++)
    {
        static int p;
        cin >> p;
        if (p)
            G[p].push_back(i), G[i].push_back(p), ++deg[i], ++deg[p];
        else
            rt = i;
    }
    dfs(rt, 0, 0);
    priority_queue<PII> q;
    for (int i = 1; i <= n; i++)
        if (deg[i] % 2 == 0) q.push({d[i], i});
    vector<int> ans;
    while (!q.empty())
    {
        PII tmp = q.top();
        q.pop();
        int u = tmp.Y;
        if (deg[u] & 1 || vis[u]) continue;
        vis[u] = 1;
        ans.push_back(u);
        for (auto& v : G[u])
            if (--deg[v] % 2 == 0) q.push({d[v], v});
    }
    if (ans.size() != n) return cout << "NO", 0;
    cout << "YES" << endl;
    for (auto& t : ans) cout << t << endl;
    return 0;
}