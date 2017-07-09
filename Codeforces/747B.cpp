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

int main()
{
    int n;
    while (cin >> n)
    {
        string s;
        map<char, int> m;
        m['?'] = m['A'] = m['G'] = m['C'] = m['T'] = 0;
        cin >> s;
        if (n % 4 != 0)
        {
            cout << "===" << endl;
            continue;
        }
        for (int i = 0; i < s.length(); i++)
            m[s[i]]++;
        int lmt = n / 4;
        if (m['A'] > lmt || m['G'] > lmt || m['C'] > lmt || m['T'] > lmt)
        {
            cout << "===" << endl;
            continue;
        }
        m['A'] = lmt - m['A'];
        m['C'] = lmt - m['C'];
        m['G'] = lmt - m['G'];
        m['T'] = lmt - m['T'];
        for (int i = 0; i < s.length(); i++)
            if (s[i] != '?')
                cout << s[i];
            else
            {
                if (m['A']-- > 0)
                    cout << "A";
                else if (m['C']-- > 0)
                    cout << "C";
                else if (m['G']-- > 0)
                    cout << "G";
                else if (m['T']-- > 0)
                    cout << "T";
            }
        cout << endl;
    }
    return 0;
}
