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

int cnt[26];
int tt[26];

bool ok()
{
    for(int i = 0; i < 26; i++)
        if(cnt[i] < tt[i]) return false;
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    string s;
    while (cin >> s)
    {
        clr(cnt, 0);
        for (auto& t : s) cnt[t - 'a']++;
        int n;
        cin >> n;
        int ans = 0;
        while (n--)
        {
            cin >> s;
            clr(tt, 0);
            for (auto& t : s) tt[t - 'a']++;
            if (ok()) ans = max(ans, (int)s.length());
        }
        cout << ans << endl;
    }
    return 0;
}