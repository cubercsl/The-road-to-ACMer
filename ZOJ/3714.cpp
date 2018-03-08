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

const int N = 405;
int a[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
            scanf("%d", a  + i);
        for(int i = 1; i <= n; i++)
            a[n + i] = a[i];
        for(int i = 1; i <= 2 * n; i++)
            a[i] += a[i - 1];
        int ans = 0;
        for(int i = m; i <= 2 * n; i++)
            ans = max(ans, a[i] - a[i - m]);
        printf("%d\n", ans);
    }
    return 0;
}
