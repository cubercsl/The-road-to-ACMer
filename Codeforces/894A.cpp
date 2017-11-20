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
    string s;
    while (cin >> s)
    {
        int cnt = 0;
        int n = s.length();
        for (int i = 0; i < n; i++)
            if (s[i] == 'Q')
                for (int j = i + 1; j < n; j++)
                    if (s[j] == 'A')
                        for (int k = j + 1; k < n; k++)
                            if (s[k] == 'Q')
                                cnt++;
        cout << cnt << endl;
    }
    return 0;
}
