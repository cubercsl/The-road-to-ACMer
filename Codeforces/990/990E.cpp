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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin
    int n, m, k;
    cin >> n >> m >> k;
    n++;
    ll ans = 1e18;
    vector<int> a(n + 1), b(n + 1), c(k + 1);
    for (int i = 0, x; i < m; i++)
    {
        cin >> x;
        a[x + 1] = 1;
    }
    if (a[1])
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
        if (a[i])
            b[i] = b[i - 1];
        else
            b[i] = i;
    for (int i = 1; i <= k; i++) cin >> c[i];
    for (int i = 1; i <= k; i++)
    {
        int tmp = 1;
        ll cnt = 1;
        for (;;)
        {
            if (tmp + i >= n)
            {
                ans = min(ans, cnt * c[i]);
                break;
            }
            if (b[tmp + i] == tmp) break;
            tmp = b[tmp + i];
            cnt++;
        }
    }
    if (ans == 1e18)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}