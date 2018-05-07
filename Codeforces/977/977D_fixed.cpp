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

typedef unsigned long long ull;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<ull> v(n);
    unordered_map<ull, int> _3, _2;
    for (auto& t : v) cin >> t;
    for (auto& t : v)
    {
        ull a = t, b = t;
        while (a % 2 == 0) _2[t]++, a /= 2;
        while (b % 3 == 0) _3[t]++, b /= 3;
    }
    sort(v.begin(), v.end(), [&](ull a, ull b) {
        return _3[a] > _3[b] || _3[a] == _3[b] && _2[a] < _2[b];
    });
    for (auto& t : v) cout << t << " ";
    return 0;
}