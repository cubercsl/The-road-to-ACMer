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
    vector<string> v(n);
    for (auto& t : v) cin >> t;
    sort(v.begin(), v.end(), [](const string& a, const string& b) {
        return a.length() < b.length();
    });
    for (int i = 0; i + 1 < n; i++)
        if (v[i + 1].find(v[i]) == string::npos) return cout << "NO", 0;
    cout << "YES" << endl;
    for (auto& t : v) cout << t << endl;
    return 0;
}