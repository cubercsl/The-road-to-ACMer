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

const int N = 1005;
int a[N];
int v[N][N], w[N][N];
int dp[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            for (int j = 0; j < a[i]; j++)
                cin >> v[i][j];
            for (int j = 0; j < a[i]; j++)
                cin >> w[i][j];
        }
        clr(dp, 0);
        for (int i = 0; i < n; i++)
            for (int j = m; j > 0; j--)
                for (int k = 0; k < a[i]; k++)
                    if (j >= w[i][k])
                        dp[j] = max(dp[j], dp[j - w[i][k]] + v[i][k]);
        cout << dp[m] << endl;
    }
    return 0;
}
