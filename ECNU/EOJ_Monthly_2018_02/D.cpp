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

const int N = 1 << 17;
vector<int> G[N];
int vis[N];
int d[N];
int dfs(int s)
{
    stack<int> q;
    q.push(s);
    vis[s] = 1;
    int id = s, mm = 1;
    while (!q.empty())
    {
        int u = q.top();
        q.pop();
        if (vis[u] > mm) id = u, mm = vis[u];
        for (auto& v : G[u])
            if (!vis[v]) q.push(v), vis[v] = vis[u] + 1;
    }
    q.push(id);
    d[id] = 0;
    int ret = 0;
    while (!q.empty())
    {
        int u = q.top();
        q.pop();
        ret = max(ret, d[u]);
        for (auto& v : G[u])
            if (d[v] < 0) q.push(v), d[v] = d[u] + 1;
    }
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++)
    {
        static int u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        G[u].push_back(v), G[v].push_back(u);
    }
    int cnt = 0;
    clr(d, -1);
    int d = 0;
    for (int i = 0; i < n; i++)
        if (!vis[i]) d += dfs(i), cnt++;
    if (cnt == 1)
        printf("%d %d\n", 0, 2 * k);
    else
        printf("%d %d\n", cnt, k * 2 - d);
    return 0;
}