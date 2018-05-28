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
    fastin int n, m;
    cin >> n;
    map<int, int> M;
    while (n--)
    {
        static int a, x;
        cin >> a >> x;
        M[a] = x;
    }
    cin >> m;
    while (m--)
    {
        static int b, y;
        cin >> b >> y;
        M[b] = max(M[b], y);
    }
    ll ans = 0;
    for (auto& t : M) ans += t.Y;
    cout << ans << endl;
    return 0;
}