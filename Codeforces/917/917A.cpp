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

int n;
char str[5005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%s", str + 1);
    n = strlen(str + 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int cc = 0, br = 0;
        for (int k = i; k <= n; ++k)
        {
            if (str[k] == '(')
                ++br;
            else if (str[k] == ')')
                --br;
            else
            {
                if (br == 0)
                    ++br;
                else
                    --br, ++cc;
            }
            if (br < 0)
            {
                if (cc == 0) break;
                br += 2, --cc;
            }
            if (br == 0)
                ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}
