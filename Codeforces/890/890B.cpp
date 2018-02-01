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

const int maxn = 1 << 18;
int a[maxn];
bool tong[maxn];
bool vis[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n;
    while (~scanf("%d", &n))
    {
        clr(tong, 0);
        clr(vis, 0);
        int tot = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", a + i);
            if (!tong[a[i]]) tong[a[i]] = 1, tot++;
        }
        int cnt = 0, ans;
        for (int i = n - 1; ~i; i--)
        {
            if (!vis[a[i]]) vis[a[i]] = 1, cnt++;
            if (cnt == tot)
            {
                ans = a[i];
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}