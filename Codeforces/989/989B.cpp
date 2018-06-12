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

bool check(const string& s, int p)
{
    int n = s.length();
    for (int i = 0; i + p < n; i++)
        if (s[i] != s[i + p]) return false;
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    string s;
    int n, p;
    cin >> n >> p;
    cin >> s;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        if (s[i] == '.') v[i] = 1;
    for (auto& t : s)
        if (t == '.') t = '0';
    if (!check(s, p)) return cout << s, 0;
    for (int i = 0; i + p < n; i++)
    {
        if (v[i])
            s[i] = '1';
        else if (v[i + p])
            s[i + p] = '1';
        else
            continue;
        return cout << s, 0;
    }
    cout << "NO";
    return 0;
}
