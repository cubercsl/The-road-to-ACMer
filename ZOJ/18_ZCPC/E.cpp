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
        int n;
        scanf("%d", &n);
        vector<int> f(n + 1);
        vector<vector<PII> > G(n + 1);
        for (int i = 1; i <= n; i++) scanf("%d", &f[i]);
        for (int i = 1, l, r; i <= n; i++)
        {
            scanf("%d%d", &l, &r);
            G[i].push_back({0, -l}); // a[i] >= l
            G[0].push_back({i, r});  // a[i] <= r
        }
        unordered_map<int, int> M;
        for (int i = 1; i <= n; i++)
        {
            if (M[f[i]]) G[M[f[i]]].push_back({i, 0});                      // a[j] >= a[i]
            if (f[i] > 0 && M[f[i] - 1]) G[i].push_back({M[f[i] - 1], -1}); // a[j] + 1 <= a[i]
            M[f[i]] = i;
        }
        vector<bool> inq(n + 1);
        vector<ll> dis(n + 1, 1e18);
        queue<int> q;
        dis[0] = 0, inq[0] = true;
        q.push(0);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            inq[u] = false;
            for (auto& e : G[u])
            {
                int &v = e.X, &w = e.Y;
                if (dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    if (!inq[v]) inq[v] = true, q.push(v);
                }
            }
        }
        for (int i = 1; i <= n; i++) printf("%lld%c", dis[i], " \n"[i == n]);
    }
    return 0;
}
