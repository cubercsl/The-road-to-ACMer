// What Are You Talking About, HDU1075

/*Sample Input
START
from fiwo
hello difh
mars riwosf
earth fnnvk
like fiiwj
END
START
difh, i'm fiwo riwosf.
i fiiwj fnnvk!
END
*/

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

map<string, string> m;
inline bool isa(char c)
{
    return c >= 'a' && c <= 'z';
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    fastin string s, t;
    cin >> s; // START;
    while (cin >> s, s != "END")
    {
        cin >> t;
        m[t] = s;
    }
    cin >> s;
    getline(cin, s);
    while (getline(cin, s), s != "END")
    {
        t = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (isa(s[i]))
                t += s[i];  
            else
            {
                if (m.find(t) != m.end())
                    cout << m[t];
                else
                    cout << t;
                t = "";
                cout << s[i];
            }
        }
        cout << endl;
    }
    return 0;
}
