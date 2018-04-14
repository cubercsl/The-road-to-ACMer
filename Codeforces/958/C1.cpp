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

const int N = 1 << 17;
int a[N], sum[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, p;
    cin >> n >> p;
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] %= p;
    for (int i = 1; i <= n; i++) sum[i] = (sum[i - 1] + a[i]) % p;
    int ans = 0;
    for (int i = 1; i < n; i++) ans = max(ans, sum[i] + (sum[n] - sum[i] + p) % p);
    cout << ans << endl;
    return 0;
}