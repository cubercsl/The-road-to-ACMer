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
    int T, n, tm, m, xx;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &xx);
        if (xx == 0)
        {
            puts("1 1");
            continue;
        }
        n = tm = -1;
        for (int i = 1; i * i <= xx; ++i)
        {
            if (xx % i) continue;
            int a = xx / i, b = i;
            if (a == b) continue;
            if ((a + b) & 1) continue;
            n = (a + b) >> 1;
            tm = (a - b) >> 1;
            m = (n + 1) / (tm + 1);
            if (m * (tm + 1) < (n + 1)) ++m;
            if (m * (tm - 1) + m - 1 >= n)
            {
                n = m = -1;
                continue;
            }
            break;
        }
        if (n == -1)
        {
            puts("-1");
            continue;
        }
        printf("%d %d\n", n, m);
    }
    return 0;
}