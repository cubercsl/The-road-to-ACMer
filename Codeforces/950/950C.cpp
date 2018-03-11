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

const int N = 200005;
vector<int> v[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    string s;
    cin >> s;
    int n = s.length();
    queue<int> q0, q1;
    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            int tt;
            if (!q1.empty())
            {
                tt = q1.front();
                q1.pop();
            }
            else
                tt = tot++;
            v[tt].push_back(i + 1);
            q0.push(tt);
        }
        if (s[i] == '1')
        {
            if (q0.empty()) return cout << "-1" << endl, 0;
            int tt = q0.front();
            q0.pop();
            v[tt].push_back(i + 1);
            q1.push(tt);
        }
    }
    if (q1.size()) return cout << "-1" << endl, 0;
    cout << q0.size() << endl;
    while (!q0.empty())
    {
        int id = q0.front();
        q0.pop();
        cout << v[id].size();
        for (auto& t : v[id]) cout << " " << t;
        cout << endl;
    }
    return 0;
}