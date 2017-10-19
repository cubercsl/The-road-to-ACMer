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
    int n, a, b, c;
    while (cin >> n >> a >> b >> c)
    {
        n--;
        if (n == 0) cout << 0 << endl;
        else if (a <= b && a <= c)
            cout << n * a << endl;
        else if (b <= c && b <= a)
            cout << n * b << endl;
        else
            cout << min(a, b) + (n - 1) * c << endl;
    }
    return 0;
}
