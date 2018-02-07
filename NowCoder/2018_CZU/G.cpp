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
const int mod = 998244353;
const double eps = 1e-6;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    ll a[3];
    int n;
    cin >> n;
    a[1] = 0, a[2] = 1;
    for (int i = 3; i <= n; i++)
        a[i % 3] = (a[(i - 1) % 3] + a[(i - 2) % 3]) * (i - 1) % mod;
    cout << a[n % 3] << endl;
    return 0;
}