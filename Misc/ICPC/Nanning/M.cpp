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

int s[55];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    double a;
    cin >> n >> a;
    string line;
    getline(cin, line);
    int tot = 0;
    while (getline(cin, line))
    {
        stringstream ss(line);
        // cout << line << endl;
        int num;
        while (ss >> num)
            s[tot] |= (1 << num);
        tot++;
    }
    int limit = ceil(tot * a);
    // cout << limit << endl;
    int ans = 0;
    for (int i = 1; i <= (1 << n); i++)
    {
        int num = 0;
        for (int j = 0; j < tot; j++)
            if ((i & s[j]) == i)
                num++;
        if (num >= limit) ans++;
    }
    cout << ans << endl;
    return 0;
}
