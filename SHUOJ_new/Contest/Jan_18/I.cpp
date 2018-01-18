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
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        int num, cnt = 0;
        set<PII> s;
        for (int i = 0; i < m; i++)
        {
            cin >> num;
            auto it = s.begin();
            for (it = s.begin(); it != s.end(); ++it)
                if (it->second == num) break;
            // for (auto v : s) cout << v.X <<" ";
            // cout << endl;
            if (it != s.end())
            {
                cnt++;
                s.erase(it);
                s.insert({i, num});
            }
            else
            {
                if (s.size() >= n)
                    s.erase(s.begin());
                s.insert({i, num});
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
