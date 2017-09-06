#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
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
const double eps = 1e-6;

const int maxn = 105;
int n;
int d[maxn], td[maxn], tc[maxn];
bool vis[maxn];
int ans;

void dfs(int cur, int t)
{
    if (cur == n + 1)
    {
        ans = max(ans, t);
        return;
    }
    if (vis[cur])
        dfs(cur + 1, t + d[cur]);
    else
    {
        if (tc[cur] > cur)
        {
            vis[cur] = 1;
            dfs(cur + 1, t + d[cur]);
            vis[cur] = 0;
        }
        vis[cur] = 1;
        dfs(tc[cur], t + td[cur]);
        vis[cur] = 0;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        clr(vis, 0);
        cin >> n;
        ans = 0;
        for (int i = 1; i <= n; i++)
            cin >> d[i] >> td[i] >> tc[i];
        dfs(1, 0);
        cout << ans << endl;
    }
    return 0;
}
