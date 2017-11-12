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
    int n, S;
    while (cin >> n >> S)
    {
        vector<pair<ll, ll> > v1, v2;
        ll s, a, b;
        ll sum = 0, c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> s >> a >> b;
            if (a > b)
            {
                sum += s * a;
                (c1 += s) %= S;
                v1.pb(mp(a - b, s));
            }
            else
            {
                sum += s * b;
                (c2 += s) %= S;
                v2.pb(mp(b - a, s));
            }
        }
        if (c1 + c2 > S)
        {
            cout << sum << endl;
            continue;
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        ll t1 = 0, t2 = 0;
        for (auto t : v1)
        {
            if (c1 > t.Y)
                t1 += t.X * t.Y, c1 -= t.Y;
            else
            {
                t1 += c1 * t.X;
                break;
            }
        }
        for (auto t : v2)
        {
            if (c2 > t.Y)
                t2 += t.X * t.Y, c2 -= t.Y;
            else
            {
                t2 += c2 * t.X;
                break;
            }
        }
        sum -= min(t1, t2);
        cout << sum << endl;
    }
    return 0;
}
