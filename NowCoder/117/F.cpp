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

typedef pair<ll, int> HeapNode;

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
        vector<ll> a(n);
        vector<bool> vis(n);
        vector<vector<PII> > G(n);
        while (m--)
        {
            static int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            --x, --y;
            a[x] += z, a[y] += z;
            G[x].push_back({y, z}), G[y].push_back({x, z});
        }
        priority_queue<HeapNode, vector<HeapNode>, greater<HeapNode> > q;
        for (int i = 0; i < n; i++) q.push({a[i], i});
        ll ans = 0;
        while (!q.empty())
        {
            HeapNode tmp = q.top();
            q.pop();
            int& u = tmp.Y;
            if (vis[u]) continue;
            vis[u] = 1;
            ans = max(ans, tmp.X);
            for (auto& e : G[u])
            {
                int &v = e.X, &w = e.Y;
                if (vis[v]) continue;
                a[v] -= w;
                q.push({a[v], v});
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
