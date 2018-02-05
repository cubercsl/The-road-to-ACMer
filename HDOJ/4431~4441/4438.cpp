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
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int x, y;
        double p, q;
        scanf("%d%d%lf%lf", &x, &y, &p, &q);
        double s1 = ((x + y) * p * (1 - p) + (x + y) * p * p) * q + x * (1 - q);
        double s2 = y * q + ((x + y) * p * (1 - p) + (x + y) * p * p) * (1 - q);
        if (s1 > s2)
            printf("tiger %.4f\n", s1);
        else
            printf("wolf %.4f\n", s2);
    }
    return 0;
}
