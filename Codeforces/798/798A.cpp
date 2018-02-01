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
    string s;
    while (cin >> s)
    {
        int cnt = 0;
        int len = s.length();
        for (int i = 0; i < len / 2; i++)
            if (s[i] != s[len - i - 1])
                cnt++;
        if (cnt == 1)
            cout << "YES" << endl;
        else if (cnt == 0 && len % 2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
