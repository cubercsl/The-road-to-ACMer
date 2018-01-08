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

double gao(int n)
{
    if (n >= 90) return 4;
    if (n >= 85) return 3.7;
    if (n >= 82) return 3.3;
    if (n >= 78) return 3.0;
    if (n >= 75) return 2.7;
    if (n >= 72) return 2.3;
    if (n >= 68) return 2.0;
    if (n >= 66) return 1.7;
    if (n >= 64) return 1.5;
    if (n >= 60) return 1.0;
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (cin >> n)
    {
        double sum = 0, tot = 0;
        while (n--)
        {
            string s;
            double w;
            double t;
            cin >> s >> w >> t;
            sum += w * gao(t);
            tot += w;
        }
        printf("%.4f\n", sum / tot);
    }
    return 0;
}
