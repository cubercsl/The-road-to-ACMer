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
int f[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if (!f[i])
            for (int j = i * 2; j <= n; j += i) f[j] = i;
        f[i] = i - f[i] + 1;
    }
    int ans = n;
    for (int i = f[n]; i <= n; i++) ans = min(ans, f[i]);
    cout << ans << endl;
    return 0;
}
