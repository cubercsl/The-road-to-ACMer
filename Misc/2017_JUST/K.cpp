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

ll fact[25];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fact[0] = 1;
    for (int i = 1; i < 25; i++) fact[i] = fact[i - 1] * i;
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<char, int> M;
        ll ans = fact[n / 2];
        int cnt = 0;
        for (auto& t : s) M[t]++;
        for (auto& t : M)
        {
            if (t.Y & 1) cnt++;
            ans /= (fact[t.Y / 2]);
        }
        if (cnt > 1)
            cout << 0 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}