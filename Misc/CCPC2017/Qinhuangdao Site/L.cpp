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

const int maxn = 1 << 17;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    char s[maxn];
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        scanf("%s", s + 1);
        if (m == 1 | m == n)
        {
            puts("0");
            continue;
        }
        int t1 = 0, t2 = 0;
        for (int i = m; i > 1; i--)
            if (s[i] == 'R') t1++;
        for (int i = m; i < n; i++)
            if (s[i] == 'L') t2++;
        printf("%d\n", min(t1, t2));
    }
    return 0;
}
