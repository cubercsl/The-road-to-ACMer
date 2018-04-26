#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
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
const double eps = 1e-6;

ll gao(int a, int b, int c, int d) { return 86400 * a + 3600 * b + 60 * c + d; }

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
        int a, b, c, d;
        scanf("%dday%d:%d:%d", &a, &b, &c, &d);
        ll x1 = gao(a, b, c, d);
        scanf("%dday%d:%d:%d", &a, &b, &c, &d);
        ll x2 = gao(a, b, c, d);
        printf("%lld\n", x2 - x1);
    }
    return 0;
}