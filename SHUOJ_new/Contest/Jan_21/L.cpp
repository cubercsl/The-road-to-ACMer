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
VI G[N];
int dp[N];
void dfs(int u, int fa, const int& n, int& rt, int& size)
{
    int tmp = 0;
    for (auto v : G[u])
    {
        if (v == fa) continue;
        dfs(v, u, n, rt, size);
        dp[u] += dp[v] + 1;
        tmp = max(tmp, dp[v] + 1);
    }
    tmp = max(tmp, n - dp[u] - 1);
    if (tmp < size || tmp == size && u < rt)
        rt = u, size = tmp;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++) G[i].clear();
        for (int i = 1; i < n; i++)
        {
            static int u, v;
            cin >> u >> v;
            G[u].pb(v);
            G[v].pb(u);
        }
        clr(dp, 0);
        int rt, size = INF;
        dfs(1, -1, n, rt, size);
        cout << rt << " " << size << endl;
    }
    return 0;
}
