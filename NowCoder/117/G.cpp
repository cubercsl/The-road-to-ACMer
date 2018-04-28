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

void gao(const string& s)
{
    int state = -1;
    int cnt = 0;
    string ans;
    for (auto& t : s)
    {
        if (t >= 'A' && t <= 'Z')
        {
            if (state == 1 || state == -2)
            {
                cout << s << endl;
                return;
            }
            cnt++;
            if (state == 0) ans += '_';
            ans += t - 'A' + 'a';
            state = 1;
        }
        else if (state == -1)
        {
            ans += t;
            state = -2, cnt++;
        }
        else
        {
            ans += t;
            state = 0;
        }
    }
    if (state == 0 && cnt > 1)
        cout << ans << endl;
    else
        cout << s << endl;
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
        gao(s);
    }
    return 0;
}
