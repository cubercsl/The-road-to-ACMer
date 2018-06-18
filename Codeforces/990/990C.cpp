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

bool judge(const string& s)
{
    int cnt = 0;
    for (auto& t : s)
    {
        if (t == '(')
            cnt++;
        else
            cnt--;
        if (cnt < 0) return false;
    }
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin int n;
    cin >> n;
    string s;
    map<int, int> M;
    while (n--)
    {
        cin >> s;
        int cnt = 0;
        for (auto& t : s)
            if (t == '(')
                cnt++;
            else
                cnt--;
        string t;
        if (cnt > 0)
        {
            for (int i = 0; i < cnt; i++) t.push_back(')');
            s = s + t;
        }
        else
        {
            for (int i = 0; i < -cnt; i++) t.push_back('(');
            s = t + s;
        }
        if (judge(s)) M[cnt]++;
    }
    ll ans = 0;
    for (auto& t : M)
        if (t.X >= 0) ans += 1LL * t.Y * M[-t.X];
    cout << ans << endl;
    return 0;
}