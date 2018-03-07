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

const int N = 505;
int dp[N][N];
char s[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    clr(dp, 0x3f);
    clr(dp[0], 0);
    int n, m, t;
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        int tt = 0;
        for (int j = 0; j < m; j++) tt += s[j] == '1';
        for (int j = 0; j < tt; j++)
        {
            int mm = INF;
            queue<int> q;
            for (int k = 0; k < m; k++)
            {
                if (s[k] == '1') q.push(k);
                if (q.size() == tt - j) mm = min(mm, q.back() - q.front() + 1), q.pop();
            }
            for (int k = j; k <= t; k++)
                dp[i][k] = min(dp[i][k], dp[i - 1][k - j] + mm);
        }
        for (int k = tt; k <= t; k++)
            dp[i][k] = min(dp[i][k], dp[i - 1][k - tt]);
    }
    cout << dp[n][t] << endl;
    return 0;
}