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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto& t : s) cin >> t;
    vector<int> sum(m);
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++)
            sum[j] += s[i][j] - '0';
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = 0; j < m; j++)
            if (s[i][j] == '1' && sum[j] == 1) flag = false;
        if (flag) return cout << "YES" << endl, 0;
    }
    cout << "NO" << endl;
    return 0;
}
