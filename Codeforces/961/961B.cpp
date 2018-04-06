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
int t[N], c[N], s1[N], s2[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) s1[i] = s1[i - 1] + t[i] * c[i], s2[i] = s2[i - 1] + t[i];
    int tmp, ans = 0;
    for (int i = 1; i + k - 1 <= n; i++)
    {
        tmp = s2[i + k - 1] - s2[i - 1] - (s1[i + k - 1] - s1[i - 1]) + s1[n];
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}