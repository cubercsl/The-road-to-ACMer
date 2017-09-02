#include <bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

map <char, int> m;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        int ans = 0;
        for (int i = 0; i < str.length() - 1; i++)
        {
            if (m[str[i]] >= m[str[i + 1]])
                ans += m[str[i]];
            else
                ans -= m[str[i]];
        }
        ans += m[str[str.length() - 1]];
        cout << ans << endl;
    }
    return 0;
}
