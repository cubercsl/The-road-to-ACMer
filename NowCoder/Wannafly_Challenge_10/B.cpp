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

int G[305][30];
bool dp[305][305];
char s[305];
char t[30005];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
            if (s[j] == '#')
                G[i][26] = 1;
            else
                G[i][s[j] - 'a'] = 1;
    }
    while (q--)
    {
        cin >> (t + 1);
        clr(dp, 0);
        int len = strlen(t + 1);
        if (len > n)
            cout << "NO" << endl;
        else
        {
            for (int i = 0; i <= n; i++) dp[i][0] = 1;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= len; j++)
                {
                    if (G[i][t[j] - 'a']) dp[i][j] |= dp[i - 1][j - 1];
                    if (G[i][26]) dp[i][j] |= dp[i - 1][j];
                }
            dp[n][len] ? cout << "YES" << endl : cout << "NO" << endl;
        }
    }
    return 0;
}