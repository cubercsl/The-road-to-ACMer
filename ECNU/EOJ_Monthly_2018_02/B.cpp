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

const int N = 1 << 20;
int dp[N];
int dfs(int state, const vector<int>& G, const int& n)
{
    if (~dp[state]) return dp[state];
    for (int i = 0; i < n; i++)
        if (state >> i & 1)
        {
            vector<int> T = G;
            T[i] = 0;
            for (auto& t : T) t &= ~(1 << i);
            int next_state = state;
            for (int i = 0; i < n; i++)
                if (T[i] == 0) next_state &= ~(1 << i);
            if (!dfs(next_state, T, n)) return dp[state] = 1;
        }
    return dp[state] = 0;
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
        clr(dp, -1);
        vector<int> G(n);
        for (int i = 1; i < n; i++)
        {
            static int u, v;
            scanf("%d%d", &u, &v);
            --u, --v;
            G[u] |= 1 << v, G[v] |= 1 << u;
        }
        puts(dfs((1 << n) - 1, G, n) ? "First" : "Second");
    }
    return 0;
}