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

const int N = 1 << 20;
int dp[N][10];
int g[N];

int dfs(int n)
{
    if (n < 10) return n;
    if (~g[n]) return g[n];
    int m = n;
    int j = 1;
    while (n)
    {
        int i = n % 10;
        if (i) j *= i;
        n /= 10;
    }
    return g[m] = dfs(j);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    clr(g, -1);
    for (int i = 1; i < N; i++) g[i] = dfs(i);
    for (int i = 1; i < N; i++) dp[i][g[i]]++;
    for (int i = 1; i < N; i++)
        for (int j = 1; j < 10; j++)
            dp[i][j] += dp[i - 1][j];
    int T;
    cin >> T;
    while (T--)
    {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", dp[r][k] - dp[l - 1][k]);
    }
    return 0;
}