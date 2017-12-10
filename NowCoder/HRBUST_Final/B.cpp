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

const int N = 1e6 + 5;
int a[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T, kase = 0;
    cin >> T;
    while (T--)
    {
        int k;
        ll ans = 0, now = 0;
        string s;
        cin >> k;
        cin >> s;
        int n = s.length();
        for (int i = 0; i < n; i++) a[i] = s[i] - '0';
        for (int i = 0; i < k; i++) now = now << 1 | a[i];
        ans = now;
        for (int i = k; i < n; i++) now &= ~(1LL << (k - 1)), now = now << 1 | a[i], ans = max(ans, now);
        cout << "Case #" << ++kase << ": " << ans << endl;
    }
    return 0;
}
