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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, pos, l, r;
    while (cin >> n >> pos >> l >> r)
    {
        if (r - l + 1 == n)
        {
            cout << 0 << endl;
            continue;
        }
        int ans = 0;
        if (l != 1 && r != n)
        {
            if (pos < l)
                ans = r - pos;
            else if (pos > r)
                ans = pos - l;
            else
                ans = r - l + min(r - pos, pos - l);
            ans += 2;
        }
        else if (l == 1 && r != n)
        {
            if (pos > r)
                ans = pos - r;
            else
                ans = r - pos;
            ans++;
        }
        else if (l != 1 && r == n)
        {
            if (pos < l)
                ans = l - pos;
            else
                ans = pos - l;
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
