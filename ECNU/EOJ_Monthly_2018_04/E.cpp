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
    int n, T;
    cin >> n >> T;
    vector<PII> v(n);
    for (auto& t : v) cin >> t.X >> t.Y;
    sort(v.begin(), v.end(), [](const PII& a, const PII& b) {
        return a.X * b.Y > a.Y * b.X;
    });
    vector<int> dp(T + 1);
    for (auto& t : v)
        for (int j = T; j >= t.Y; j--)
            dp[j] = max(dp[j], dp[j - t.Y] + t.X * (T - j));
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}