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

bool check(int mid, const string& s)
{
    int cur = 0, tmp = 0;
    for (auto c : s)
    {
        tmp += c == 'V' ? 1 : -1;
        if (tmp < 0) return false;
        if (tmp > cur) cur += mid, tmp = cur;
    }
    return true;
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
        string s;
        cin >> s;
        int l = 0, r = s.length(), ans = -1;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (check(mid, s))
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        cout << ans << endl;
    }
    return 0;
}