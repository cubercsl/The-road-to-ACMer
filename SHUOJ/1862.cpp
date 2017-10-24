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

const int maxn = 1005;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    int a, b, c[maxn]; // d[i] = a[i + 1] - a[i]
    while (cin >> n)
    {
        cin >> a >> b;
        for (int i = 1; i <= n; i++)
            cin >> c[i];
        double sum = 0;
        for (int i = 1; i <= n; i++)
            sum += (n - i + 1) * c[i];
        sum *= 2;
        sum = (b - a - sum) / (n + 1);
        cout << fixed << setprecision(2) << sum + a << endl;
    }
    return 0;
}

/*
a[i] = (a[i + 1] + a[i - 1]) / 2 - c[i]
a[i + 1] - a[i] = a[i] - a[i - 1] + 2 * c[i]

*/
