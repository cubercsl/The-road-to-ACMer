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

    ll hh, mm, h, d, c, n;
    cin >> hh >> mm >> h >> d >> c >> n;
    if (hh < 20)
    {
        double cur = (h / n + (h % n != 0)) * 1.0 * c;
        double cut = (((20 * 60 - hh * 60 - mm) * d + h) / n + (((20 * 60 - hh * 60 - mm) * d + h) % n != 0)) * c * 0.8;
        printf("%.4f\n", min(cur, cut));
    }
    else
        printf("%.4f\n", (h / n + (h % n != 0)) * 0.8 * c);
    return 0;
}