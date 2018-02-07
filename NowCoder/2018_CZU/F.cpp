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

bool check(int x, int a, int b, int c)
{
    a -= x, b -= x;
    if (a < 0 || b < 0) return false;
    int m = a + b;
    m = min(m, a + c);
    m = min(m, b + c);
    return m >= x / 2;
}

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
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int l = 0, r = (a + b + c) / 3;
        int ans = 0;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (check(mid, a, b, c))
                l = (ans = mid) + 1;
            else
                r = mid - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}