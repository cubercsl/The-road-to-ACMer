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

map<string, string> M;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    string s, t;
    for (int i = 0; i < 3; i++)
    {
        cin >> s >> t;
        M[t] = s;
    }
    int n;
    cin >> n;
    while (n--)
    {
        cin >> s;
        if (M.find(s) != M.end())
            cout << M[s] << endl;
        else
            cout << "Fake" << endl;
    }
    return 0;
}