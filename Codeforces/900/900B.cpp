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
    int a, b, c;
    while (~scanf("%d%d%d", &a, &b, &c))
    {
        bool flag = 0;
        int cur = 0;
        for (cur++; cur < 5e6; cur++)
        {
            int d = a * 10 / b, e = d * b;
            // printf("%d\n", e);
            (a *= 10) -= e;
            if (d == c) {
                printf("%d\n", cur);
                flag = 1;
                break;
            }
        }
        if (!flag) puts("-1");
    }
    return 0;
}
