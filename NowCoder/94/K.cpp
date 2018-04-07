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

const int N = 40;

ll x, y;
int a[N], b[N];
map<ll, int> M;
ll ans;
void dfs(int s, int t, int aa, int bb, bool flag)
{
    if (s == t)
    {
        if (flag)
            ans += M[x * bb - y * aa];
        else
            M[y * aa - x * bb]++;
        return;
    }
    dfs(s + 1, t, aa + a[s], bb + b[s], flag);
    dfs(s + 1, t, aa, bb, flag);
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
        int n;
        M.clear();
        scanf("%d%lld%lld", &n, &x, &y);
        for (int i = 0; i < n; i++) scanf("%d%d", &a[i], &b[i]);
        ans = 0;
        dfs(0, n / 2, 0, 0, 0);
        dfs(n / 2, n, 0, 0, 1);
        printf("%lld\n", ans - 1);
    }
    return 0;
}
