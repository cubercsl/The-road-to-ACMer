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
    fastin
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        int n = s.length();
        map<char, int> a, b;
        for (int i = 0; i < n; i += 2) a[s[i]]++;
        for (int i = 1; i < n; i += 2) b[s[i]]++;
        int aa = 0, bb = 0;
        for (auto& t : a) aa = max(t.second, aa);
        for (auto& t : b) bb = max(t.second, bb);
        int ans = n / 2 - aa + (n - n / 2) - bb;
        cout << ans << endl;
    }
    return 0;
}