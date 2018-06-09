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

const int maxn = 1 << 11;
char s1[maxn][maxn], s2[maxn][maxn];
bool lab[maxn][maxn];
int d[maxn][maxn];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    ll ans = 0;
    int n, m, k, bx, by;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) scanf("%s", s1[i] + 1);
    for (int i = 1; i < n; i++) scanf("%s", s2[i] + 1);
    for (int i = 1, x, y; i <= k; i++)
    {
        scanf("%d%d", &x, &y);
        lab[x][y] = true;
        bx = x, by = y;
    }
    clr(d, -1);
    priority_queue<pair<int, PII> > q;
    q.push({0, {bx, by}});
    while (!q.empty())
    {
        pair<int, PII> t = q.top();
        q.pop();
        int x = t.Y.X, y = t.Y.Y, w = -t.X;
        if (d[x][y] >= 0 && d[x][y] <= w) continue;
        if (d[x][y] >= 0 && lab[x][y]) continue;
        if (lab[x][y]) ans += w, w = 0;
        d[x][y] = w;
        if (x + 1 <= n && s2[x][y] == '0') q.push({-w - 1, {x + 1, y}});
        if (x - 1 > 0 && s2[x - 1][y] == '0') q.push({-w - 1, {x - 1, y}});
        if (y + 1 <= m && s1[x][y] == '0') q.push({-w - 1, {x, y + 1}});
        if (y - 1 > 0 && s1[x][y - 1] == '0') q.push({-w - 1, {x, y - 1}});
    }
    printf("%lld\n", ans);
    return 0;
}
