// Bag Problem, HDU3448

/*Sample Inpput
5 100
8
8 64 17 23 91 32 17 12
5 10
3
99 99 99
*/

#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

const int maxn = 45;
int n, m, V;
ll v[maxn];
ll ans;

void dfs(int i, int cnt, ll sum)
{
    if (cnt > n) return;
    if (sum > V) return;
    ans = max(ans, sum);
    if (i > m) return;
    dfs(i + 1, cnt + 1, sum + v[i]);
    dfs(i + 1, cnt, sum);
}

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (~scanf("%d%d", &n, &V))
    {
        scanf("%d", &m);
        for (int i = 1; i <= m; i++)
            scanf("%lld", v+i);
        sort(v + 1, v + m + 1, cmp);
        ans = 0;
        for (int i = 1; i <= n; i++)
            ans += v[i];
        if (ans <= V)
        {
            printf("%lld\n", ans);
            continue;
        }
        ans = 0;
        dfs(1, 0, 0);
        printf("%lld\n", ans);
    }
    return 0;
}
