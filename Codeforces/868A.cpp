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
char a[2];
char t[105][2];

bool solve(int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (t[i][1] == a[0] && t[j][0] == a[1]) return true;
        }
    for (int i = 0; i < n; i++)
        if (t[i][0] == a[0] && t[i][1] == a[1]) return true;
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (cin >> a)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> t[i];
        puts(solve(n) ? "YES" : "NO");
    }
    return 0;
}
