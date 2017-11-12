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

const int maxn = 1 << 10;
int a[maxn];
VI G[maxn];
int d[maxn];

int bfs(int s, int n)
{
    clr(d, -1);
    queue<int> q;
    d[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : G[u])
        {
            if (~d[v]) continue;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
    int ret = 0;
    for(int i = 1; i <= n; i++)
        if(a[i]) ret = max(ret, d[i]);
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        clr(a, 0);
        for (int i = 0; i < m; i++)
        {
            static int x;
            scanf("%d",&x);
            a[x] = 1;
        }
        for(int i = 1; i <= n; i++) G[i].clear();
        for (int i = 1; i < n; i++)
        {
            static int u, v;
            scanf("%d%d", &u, &v);
            G[u].pb(v), G[v].pb(u);
        }
        int ans = 0; 
        for(int i = 1; i <= n; i++)
            if(a[i])
                ans = max(ans, bfs(i, n));
        printf("%d.00\n", ans / 2);
    }
    return 0;
}
