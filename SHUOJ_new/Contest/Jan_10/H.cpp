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

bool ok(PII a, PII b, int r)
{
    return (a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y) < r * r;
}

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
        int n, q;
        cin >> n >> q;
        int x, y, r;
        multiset<PII> s;
        while (n--)
        {
            cin >> x >> y;
            s.insert(mp(x, y));
        }
        int cnt = 0;
        while (q--)
        {
            cin >> x >> y >> r;
            auto st = s.lower_bound(mp(x - r , 0));
            auto en = s.lower_bound(mp(x + r , 0));
            for (auto it = st; it != en; ++it)
                if (ok(*it, mp(x, y), r)) s.erase(it), cnt++;
        }
        cout << cnt << endl;
        cout << endl;
    }
    return 0;
}
