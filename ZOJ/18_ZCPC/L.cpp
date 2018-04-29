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

struct Node
{
    string s;
    int f;
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        vector<Node> a(n);
        for (auto& t : a) cin >> t.s >> t.f;
        sort(a.begin(), a.end(), [](const Node& a, const Node& b) {
            return a.f > b.f || a.f == b.f && a.s < b.s;
        });
        ll tot = 0;
        string ans;
        for (int i = 0; i < m; i++)
        {
            tot += 1LL * (m - i) * a[i].f;
            if (i) ans += ' ';
            ans += a[i].s;
        }
        cout << tot << " ";
        cout << ans << endl;
    }
    return 0;
}
