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

const double PI = acos(-1.0);

const double r = 6371009;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--)
    {
        double l1, d1, l2, d2;
        scanf("%lf%lf%lf%lf", &l1, &d1, &l2, &d2);
        l1 *= PI / 180.0;
        l2 *= PI / 180.0;
        d1 *= PI / 180.0;
        d2 *= PI / 180.0;
        double d = r * sqrt(2 - 2 * (cos(l1) * cos(l2) * cos(d1 - d2) + sin(l1) * sin(l2)));
        printf("%.0lf\n", 2 * asin(d / (2 * r)) * r - d);
    }
    return 0;
}
