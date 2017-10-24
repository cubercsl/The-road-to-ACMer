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

const int maxn = 1e6 + 5;
int a[maxn];
int dp[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, tot = 0;
    while (~scanf("%d", &n))
    {
        if (n < 0) continue;
        a[tot++] = n;
    }
    clr(dp, 0x3f);
    for (int i = 0; i < tot; i++)
    {
        int t = a[i] < 10000 ? 1 : 5;
        if (a[i] >= 10000) a[i] -= 10000;
        // printf("%d\n", t);
        for (int j = 0; j < t; j++)
            *upper_bound(dp, dp + tot * 5, a[i]) = a[i];
    }
    printf("%d\n", (int)(lower_bound(dp, dp + tot * 5, INF) - dp));
    return 0;
}
