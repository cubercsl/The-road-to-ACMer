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
// freopen("1.in", "r", stdin);
// freopen("1.out", "w", stdout);
#endif
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        int cnt = 0, p = 0, tmp = 0;
        char buf[155];
        for (int i = 0; i < n; i++)
        {
            scanf("%s", buf);
            int l = 0, r = m - 1;
            while (buf[l] != 'W' && l < m) l++;
            while (buf[r] != 'W' && ~r) r--;
            if (l != m && ~r)
                cnt += r - l, tmp = 0;
            else
            {
                tmp++;
                cnt++;
                continue;
            }
            if (i & 1)
            {
                cnt += abs(r - p) + 1;
                p = l;
            }
            else
            {
                cnt += abs(l - p) + 1;
                p = r;
            }
        }
        printf("%d\n", cnt - 1 - tmp);
    }
    return 0;
}
