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
const double eps = 1e-6;

const int maxn = 1e5 + 5;
int dp[maxn];

int solve(int a[], int n)
{
    clr(dp, 0x3f);
    for (int i = 0; i < n; i++)
        *upper_bound(dp, dp + n, a[i]) = a[i];
    return lower_bound(dp, dp + n, INF) - dp;
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
        int n, k;
        int a[maxn], b[maxn];
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", a + i);
            b[n - 1 - i] = a[i];
        }
        if (solve(a, n) + k >= n || solve(b, n) + k >= n)
            puts("A is a magic array.");
        else
            puts("A is not a magic array.");
    }
    return 0;
}
