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

const int maxn = 1 << 17;
vector<int> G[maxn];
bool col[maxn];
void dfs(int u, int p, int flag)
{
    col[u] = flag;
    for (auto v : G[u])
    {
        if (v == p) continue;
        dfs(v, u, flag ^ 1);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (~scanf("%d", &n))
    {
        int u, v;
        for (int i = 1; i <= n; i++)
            G[i].clear();
        for (int i = 1; i < n; i++)
        {
            scanf("%d%d", &u, &v);
            G[u].pb(v), G[v].pb(u);
        }
        dfs(1, 0, 0);
        ll a = 0, b = 0;
        for (int i = 1; i <= n; i++)
        {
            if (col[i])
                b++;
            else
                a++;
        }
        ll ans = a * (a - 1) / 2 + b * (b - 1) / 2;
        printf("%lld\n", ans);
    }
    return 0;
}
