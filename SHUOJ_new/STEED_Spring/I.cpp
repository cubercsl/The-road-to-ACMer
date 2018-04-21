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

const int N = 1 << 17;
int bit[N];

void update(int x, int v)
{
    x++;
    for (int i = x; i < N; i += i & -i) bit[i] = min(bit[i], v);
}

int query(int x)
{
    x++;
    int t = INF;
    for (int i = x; i; i -= i & -i) t = min(t, bit[i]);
    return t;
}

int a[N], b[N];
int L[N], R[N];
int dp[N][2];

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
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d%d", &a[i], &b[i]);
        clr(bit, 0x3f);
        for (int i = n - 1; ~i; i--)
        {
            int r = lower_bound(a, a + n, a[i] + b[i]) - a - 1;
            R[i] = max(r, INF - query(r));
            update(i, INF - R[i]);
        }
        clr(bit, 0x3f);
        for (int i = n - 1; ~i; i--)
        {
            L[i] = query(i);
            int l = lower_bound(a, a + n, a[i] - b[i] + 1) - a;
            update(l, i);
        }
        clr(dp, 0x3f);
        dp[0][0] = 0;
        for (int i = 0; i < n; i++)
        {
            dp[R[i] + 1][0] = min(dp[R[i] + 1][0], min(dp[i][0], dp[i][1]) + 1);
            if (L[i] != INF) dp[L[i] + 1][1] = min(dp[L[i] + 1][1], min(dp[i][0], dp[i][1]) + 1);
            if (i && L[i - 1] != INF) dp[L[i - 1] + 1][1] = min(dp[L[i - 1] + 1][1], dp[i][1]);
        }
        printf("%d\n", min(dp[n][0], dp[n][1]));
    }
    return 0;
}