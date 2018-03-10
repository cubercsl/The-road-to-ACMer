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

const int N = 1e6 + 5;
bool vis[N];

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
        clr(vis, 0);
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            static int t;
            scanf("%d", &t);
            vis[t] = true;
        }
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            static int t;
            scanf("%d", &t);
            if (vis[t]) ans = t;
        }
        assert(~ans);
        printf("%d\n", ans);
    }
    return 0;
}
