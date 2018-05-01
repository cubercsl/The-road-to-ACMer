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
    int n, a, b, s;
    cin >> n >> a >> b;
    cin >> s;
    vector<int> v(n - 1);
    for (auto& t : v) cin >> t;
    sort(v.begin(), v.end(), greater<int>());
    int ss = accumulate(v.begin(), v.end(), 0) + s;
    if ((1.0 * s * a / ss) >= b)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        ss -= v[i];
        if ((1.0 * s * a / ss) >= b)
            return cout << i + 1 << endl, 0;
    }

    return 0;
}
