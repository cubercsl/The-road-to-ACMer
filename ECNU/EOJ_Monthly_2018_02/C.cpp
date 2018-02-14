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
    int n;
    while (cin >> n)
    {
        vector<PII> v(n);
        int id = 0;
        for (auto& t : v) cin >> t.X, t.Y = ++id;
        sort(v.begin(), v.end(), greater<PII>());
        vector<int> a, b;
        ll sa = 0, sb = 0;
        id = 0;
        for (auto& t : v)
        {
            if (sa < sb)
                a.pb(t.Y), sa += t.X;
            else
                b.pb(t.Y), sb += t.X;
        }
        if (sb < sa) swap(a, b);
        cout << "Yes" << endl;
        cout << a.size() << endl;
        for (auto& t : a) cout << t << " ";
    }
    return 0;
}