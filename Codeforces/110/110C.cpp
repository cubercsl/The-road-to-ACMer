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
    cin >> n;
    // 4 * a + 7 * b = n
    vector<PII> v;
    for (int b = 0; b * 7 <= n; b++)
    {
        if ((n - 7 * b) % 4 != 0) continue;
        int a = (n - 7 * b) / 4;
        v.push_back({a, b});
    }
    if (v.empty()) return cout << -1, 0;
    sort(v.begin(), v.end(), [](PII a, PII b) {
        return a.X + a.Y < b.X + b.Y || a.X + a.Y == b.X + b.Y && a.Y < b.Y;
    });
    int a = v[0].X, b = v[0].Y;
    for (int i = 0; i < a; i++) cout << 4;
    for (int i = 0; i < b; i++) cout << 7;
    return 0;
}
