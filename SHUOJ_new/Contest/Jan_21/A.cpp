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

string s;
ll pre_a[N], pre_b[N];
char a, b, c;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (cin >> n)
    {
        cin >> a >> b >> c;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            pre_a[i + 1] = pre_a[i] + (s[i] == a);
            pre_b[i + 1] = pre_b[i] + (s[i] == c);
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == b)
                ans += pre_a[i] * (pre_b[n] - pre_b[i + 1]);
        cout << ans << endl;
    }
    return 0;
}
