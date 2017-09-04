#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;

const int maxn = 20005;
vector <int> G[maxn];

void init(int n)
{
    for (int i = 0; i < n; i++)
        G[i].clear();
}

void addedge(int u, int v)
{
    G[u].pb(v);
}

int dp[maxn], num[maxn];
int n;

void dfs(int u, int par)
{
    dp[u] = 0, num[u] = 1;
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (v == par) continue;
        dfs(v, u);
        dp[u] = max(dp[u], num[v]);
        num[u] += num[v];
    }
    dp[u] = max(dp[u], n - num[u]);
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
        int u, v;
        scanf("%d", &n);
        init(n);
        for (int i = 1; i < n; i++)
        {
            scanf("%d%d", &u, &v);
            addedge(u, v);
            addedge(v, u);
        }
        dfs(1, 0);
        int id = 1, ans = dp[1];
        for (int i = 2; i <= n; i++)
        {
            if (ans > dp[i])
                id = i, ans = dp[i];
        }
        printf("%d %d\n", id, ans);
    }
    return 0;
}
