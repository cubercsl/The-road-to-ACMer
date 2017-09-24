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
    double a[5][5];
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            cin >> a[i][j];
    string line;
    getline(cin, line);
    getline(cin, line);
    // cout << line << endl;
    stringstream ss1(line);
    vector<int> s;
    vector<int> t;
    int tmp;
    while (ss1 >> tmp) s.pb(tmp);
    getline(cin, line);
    stringstream ss2(line);
    while (ss2 >> tmp) t.pb(tmp);
    int i, j;
    cin >> i >> j;

    double ans = 1;
    for (int i = 0; i < s.size() - 1; i++)
        ans *= a[s[i]][s[i + 1]];
    printf("%.8f\n", ans);
    ans = 1;
    for (int i = 0; i < t.size() - 1; i++)
        ans *= a[t[i]][t[i + 1]];
    printf("%.8f\n", ans);
    printf("%.8f\n", 1 / (1 - a[i][i]));
    printf("%.8f\n", 1 / (1 - a[j][j]));
    return 0;
}
