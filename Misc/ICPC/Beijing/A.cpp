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
int a[105];
bool vis[105];
int pre[105];
int n, m;

bool solve(int i, int j, int& sum)
{
    sum = a[i] + a[j];
    // printf("sum =  %d\n", sum);
    if (vis[i] || vis[j]) return false;
    int k = j - i + 1;
    if ((n - i + 1) - (pre[n] - pre[i - 1]) < m) return false;
    // printf("k = %d\n", k);
    return k - m <= pre[j] - pre[i - 1];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    while (~scanf("%d%d", &n, &m))
    {
        clr(vis, 0);
        clr(pre, 0);
        for (int i = 1; i <= n; i++)
            scanf("%d", a + i);
        int tot, tmp;
        scanf("%d", &tot);
        for (int i = 0; i < tot; i++)
        {
            scanf("%d", &tmp);
            vis[tmp + 1] = 1;
        }
        for (int i = 1; i <= n; i++)
            pre[i] = pre[i - 1] + vis[i];
        // for (int i = 1; i <= n; i++) printf("%d\n", pre[i]);
        PII ans;
        ans = mp(-1, -1);
        int sum, ans_sum = INF;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                if (solve(i, j, sum) && sum < ans_sum) ans = mp(i - 1, j - 1), ans_sum = sum;
        printf("%d %d\n", ans.X, ans.Y);
    }
    return 0;
}
