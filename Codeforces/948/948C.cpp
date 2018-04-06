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
ll v[N], t[N], ans[N], cnt[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> t[i], t[i] += t[i - 1];
    for (int i = 1; i <= n; i++)
    {
        int x = upper_bound(t + 1, t + n + 1, v[i] + t[i - 1] - 1) - t;
        ans[x] += v[i] - (t[x - 1] - t[i - 1]);
        cnt[i]++;
        cnt[x]--;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] + (cnt[i] += cnt[i - 1]) * (t[i] - t[i - 1]) << " ";
    return 0;
}
