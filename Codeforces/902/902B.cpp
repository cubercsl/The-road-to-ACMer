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

const int N = 1e5 + 7;
vector<int> G[N];
int col[N];
int ans;
void dfs(int u, int cur)
{
    if (cur != col[u]) ans++;
    for (auto v : G[u])
        dfs(v, col[u]);
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
        ans = 0;
        for (int i = 1; i <= n; i++)
            G[i].clear();
        for (int i = 2; i <= n; i++)
        {
            int r;
            scanf("%d", &r);
            G[r].pb(i);
        }
        for (int i = 1; i <= n; i++) scanf("%d", &col[i]);
        dfs(1, -1);
        printf("%d\n", ans);
    }
    return 0;
}
