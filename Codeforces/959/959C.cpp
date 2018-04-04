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
    int n;
    cin >> n;
    if (n < 6)
        cout << -1 << endl;
    else
    {
        for (int i = 2; i <= n - 2; i++)
            cout << 1 << " " << i << endl;
        cout << 2 << " " << n - 1 << endl
             << 2 << " " << n << endl;
    }
    for (int i = 2; i <= n; i++)
        cout << i - 1 << " " << i << endl;
    return 0;
}