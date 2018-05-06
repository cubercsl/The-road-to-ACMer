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
    int h, m, s, kase = 0;
    while (~scanf("%d:%d:%d", &h, &m, &s))
    {
        int t;
        scanf("%d", &t);
        t *= 120;
        int sum = h * 3600 + m * 60 + s;
        int H = sum % (360 * 120), M = (sum * 12) % (360 * 120);
        int ans;
        for (ans = 0; ans == 0 || abs(abs(H - M) - t) > 10; ans++)
        {
            (++H) %= (360 * 120);
            (M += 12) %= (360 * 120);
        }
        sum += ans;
        sum %= 43200;
        int hh = sum / 3600;
        int mm = (sum % 3600) / 60;
        int ss = (sum % 3600) % 60;
        printf("Case #%d: %02d:%02d:%02d\n", ++kase, hh, mm, ss);
    }
    return 0;
}