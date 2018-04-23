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
    string s;
    cin >> s;
    string t = s;
    int cnt[3] = {0};
    sort(t.begin(), t.end());
    if (t != s) return cout << "NO", 0;
    for (auto& c : s) cnt[c - 'a']++;
    if (!cnt[0] || !cnt[1]) return cout << "NO", 0;
    if (cnt[2] == cnt[0] || cnt[2] == cnt[1]) return cout << "YES", 0;
    cout << "NO";
    return 0;
}
