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

const int maxn = 1 << 17;

int main()
{
#ifndef ONLINE_JUDGE
// freopen("1.in", "r", stdin);
// freopen("1.out", "w", stdout);
#endif
    ll s, f, t;
    ll a[maxn];
    while (cin >> s >> f >> t)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        int tmp = a[0];
        a[0] = max(s, a[0]);
        for (int i = 1; i < n; i++)
            a[i] = max(a[i], a[i - 1] + t);
        // for(int i = 0; i < n; i++)
        // cout << a[i] << endl;
        int ans = -1;
        for (int i = 0; i < n - 1 && a[i + 1] < f; i++)
        {
            if (a[i] + t < a[i + 1])
            {
                ans = a[i] + t;
                break;
            }
            else
                ans = a[i + 1] - 1;
        }
        if (~ans)
            cout << ans << endl;
        else
            cout << tmp - 1 << endl;
    }
    return 0;
}