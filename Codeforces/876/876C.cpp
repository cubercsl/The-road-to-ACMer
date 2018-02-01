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

inline int solve(int n)
{
    int ret = 0;
    do
        ret += n % 10;
    while (n /= 10);
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (cin >> n)
    {
        vector<int> ans;
        for (int i = max(0, n - 81); i < n; i++)
            if (solve(i) + i == n) ans.pb(i);
        cout << ans.size() << endl;
        for (auto& v : ans)
            cout << v << endl;
    }
    return 0;
}
