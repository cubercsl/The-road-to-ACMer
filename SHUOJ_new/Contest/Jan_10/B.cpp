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

const int N = 45;
int dp[N][2], cnt[N];

void dfs(int n, int k)
{
    if(n == 1)
    {
        cout << k - 1 << endl;
        return;
    }
    if(k <= cnt[n - 1])
    {
        cout << 0;
        dfs(n - 1, k);
    }
    else
    {
        cout << 1;
        dfs(n - 1, k - cnt[n - 1]);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    cnt[1] = 2;
    dp[1][0] = dp[1][1] = 1;
    for(int i = 2; i < N; i++)
    {
        dp[i][1] = dp[i - 1][0];
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        cnt[i] = dp[i][0] + dp[i][1];
    }
    int T;
    cin >> T;
    while(T--)
    {
        int n, k;
        cin >> n >> k;
        if(k > cnt[n])
        {
            cout << -1 << endl;
            continue;
        }
        dfs(n, k);
    }
    return 0;
}
