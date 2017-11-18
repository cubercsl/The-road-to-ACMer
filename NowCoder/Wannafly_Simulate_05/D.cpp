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

const int N = 1 << 18;
int a[N], b[N];
int n, x;
ll y;
bool ok(ll m)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (a[i] < b[i] - m)
            return false;
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d%d%lld", &n, &x, &y);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    sort(a, a + n);
    for (int i = 0; i < n && i < x && a[i] < y; i++)
        a[i] = y;
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        scanf("%d", b + i);
    sort(b, b + n);
    ll l = 0, r = 2e9;
    ll ans;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        if (ok(m))
            r = m - 1, ans = m;
        else
            l = m + 1;
    }
    printf("%lld\n", ans);
    return 0;
}