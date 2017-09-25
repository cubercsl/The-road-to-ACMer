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

ll vis[105];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (~scanf("%d", &n))
    {
        if (n == 0)
        {
            puts("*");
            break;
        }
        clr(vis, 0);
        while (n--)
        {
            int x, y, w;
            scanf("%d%d%d", &x, &y, &w);
            vis[x] += w, vis[y] -= w;
        }
        for (int i = 1; i <= 100; i++)
            vis[i] = vis[i - 1] + vis[i];
        // for (int i = 1; i <= 100; i++)
            // printf("%d %d\n", i, vis[i]);
        printf("%lld\n", *max_element(vis + 1, vis + 101));
    }
    return 0;
}
