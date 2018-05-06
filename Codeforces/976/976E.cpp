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
struct Node
{
    ll h, d;
    int id;

} pp[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) cin >> pp[i].h >> pp[i].d, pp[i].id = i;
    sort(pp + 1, pp + n + 1, [](const Node& a, const Node& b) {
        return (a.h - a.d) > (b.h - b.d);
    });
    int p = 0;
    ll sum = 0;
    for (int i = 1; i <= b; i++)
    {
        if (pp[i].h <= pp[i].d) break;
        p = i, sum += pp[i].h;
    }
    for (int i = p + 1; i <= n; i++) sum += pp[i].d;
    ll ans = sum;
    for (int i = 1; i <= n; i++)
    {
        if (i <= p)
        {
            ll tmp = sum - pp[i].h;
            ans = max(ans, tmp + (pp[i].h << a));
        }
        else
        {
            if (b - p > 0)
            {
                ll tmp = sum - pp[i].d;
                ans = max(ans, tmp + (pp[i].h << a));
            }
            else if (p)
            {
                ll tmp = sum - pp[i].d - pp[p].h + pp[p].d;
                ans = max(ans, tmp + (pp[i].h << a));
            }
        }
    }
    cout << ans << endl;
    return 0;
}